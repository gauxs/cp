import fs from "node:fs";
import path from "node:path";
import { fileURLToPath } from "node:url";
import fg from "fast-glob";
import matter from "gray-matter";
import yaml from "js-yaml";

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const ROOT = path.resolve(__dirname, "..");
const DOCS = path.join(ROOT, "docs");
const DATA_DIR = path.join(DOCS, "public", "data");
const TOPICS_DIR = path.join(DATA_DIR, "topics");

const LEETCODE_RE =
  /\[([^\]]+)\]\(https:\/\/leetcode\.com\/problems\/([^/)]+)\/?\)/g;
const PATTERN_HEADING_RE = /^## Pattern:\s*(.+)$/m;

function loadConfig() {
  const raw = fs.readFileSync(path.join(ROOT, "site.config.yaml"), "utf8");
  return yaml.load(raw);
}

function readFile(relPath) {
  return fs.readFileSync(path.join(ROOT, relPath), "utf8");
}

function extractProblems(markdown) {
  const problems = [];
  let match;
  const re = new RegExp(LEETCODE_RE.source, "g");
  while ((match = re.exec(markdown)) !== null) {
    problems.push({
      slug: match[2],
      title: match[1].trim(),
      url: `https://leetcode.com/problems/${match[2]}/`,
    });
  }
  return problems;
}

function parsePatternSections(markdown) {
  const body = matter(markdown).content;
  const sections = body.split(/\n---\n/);
  const patterns = [];

  for (const section of sections) {
    const heading = section.match(PATTERN_HEADING_RE);
    if (!heading) continue;
    patterns.push({
      name: heading[1].trim(),
      problems: extractProblems(section),
    });
  }

  return patterns;
}

function topicLabel(topicId, config, frontmatterTitle) {
  return config.topics?.[topicId]?.label ?? frontmatterTitle ?? topicId;
}

function topicOrder(topicId, config) {
  return config.topics?.[topicId]?.order ?? 999;
}

function findCodeFile(topicDir) {
  const files = fs.readdirSync(topicDir).filter((f) => f.endsWith(".h"));
  if (files.length === 0) return null;
  const file = files[0];
  return {
    path: path.relative(ROOT, path.join(topicDir, file)),
    name: file,
    content: fs.readFileSync(path.join(topicDir, file), "utf8"),
  };
}

function buildTopicBundle(topicId, config) {
  const topicDir = path.join(ROOT, topicId);
  if (!fs.existsSync(topicDir)) return null;

  const readmePath = path.join(topicDir, "README.md");
  if (!fs.existsSync(readmePath)) return null;

  const readme = matter(readFile(path.relative(ROOT, readmePath)));
  if (readme.data.kind !== "theory") return null;

  const practiceDir = path.join(topicDir, "practice");
  const practiceFiles = [];

  if (fs.existsSync(practiceDir)) {
    for (const file of fs
      .readdirSync(practiceDir)
      .filter((f) => f.endsWith(".md"))
      .sort()) {
      const rel = path.relative(ROOT, path.join(practiceDir, file));
      const parsed = matter(readFile(rel));
      practiceFiles.push({
        file: rel,
        kind: parsed.data.kind,
        tier: parsed.data.tier ?? null,
        title: parsed.data.title ?? file,
        content: parsed.content.trim(),
      });
    }
  }

  return {
    topic_id: topicId,
    title: topicLabel(topicId, config, readme.data.title),
    order: topicOrder(topicId, config),
    theory: {
      path: path.relative(ROOT, readmePath),
      content: readme.content.trim(),
    },
    code: findCodeFile(topicDir),
    practice: practiceFiles,
  };
}

function ensureDir(dir) {
  fs.mkdirSync(dir, { recursive: true });
}

function slugifyTopicId(topicId) {
  return topicId.replace(/\//g, "-");
}

function docsDirForTopicId(topicId) {
  return path.join(DOCS, ...topicId.split("/"));
}

function cleanLegacyGeneratedDocs() {
  const legacyDir = path.join(DOCS, "algorithms-search");
  if (fs.existsSync(legacyDir)) {
    fs.rmSync(legacyDir, { recursive: true, force: true });
  }
}

function writeTopicPages(topicBundles, categories) {
  for (const category of categories) {
    const categoryDir = docsDirForTopicId(category.topic_id);
    ensureDir(categoryDir);

    fs.writeFileSync(
      path.join(categoryDir, "index.md"),
      `---
cpLayout: category
topic_id: ${category.topic_id}
title: ${category.label}
pageClass: cp-custom
outline: false
aside: false
---
`,
    );
  }

  for (const topic of topicBundles) {
    const parts = topic.topic_id.split("/");
    const slug = parts[parts.length - 1];
    const pageDir = docsDirForTopicId(parts.slice(0, -1).join("/"));
    ensureDir(pageDir);

    fs.writeFileSync(
      path.join(pageDir, `${slug}.md`),
      `---
cpLayout: topic
topic_id: ${topic.topic_id}
title: ${topic.title}
pageClass: cp-custom
outline: false
aside: false
---
`,
    );
  }
}

function buildSidebar(categories, topicBundles) {
  const config = loadConfig();
  const homeLabel = config.site?.home_title ?? "Home";
  const items = [{ text: homeLabel, link: "/" }];
  const topLevel = categories.filter((category) => !category.parent);

  for (const parent of topLevel) {
    const subcategories = categories
      .filter((category) => category.parent === parent.topic_id)
      .sort((a, b) => a.label.localeCompare(b.label));

    if (subcategories.length > 0) {
      const sectionItems = subcategories.map((subcategory) => {
        const topics = topicBundles
          .filter((topic) => topic.topic_id.startsWith(`${subcategory.topic_id}/`))
          .sort((a, b) => a.order - b.order)
          .map((topic) => ({
            text: topic.title,
            link: `/${topic.topic_id}`,
          }));

        return {
          text: subcategory.label,
          link: `/${subcategory.topic_id}`,
          collapsed: true,
          items: topics,
        };
      });

      items.push({
        text: parent.label,
        link: `/${parent.topic_id}`,
        collapsed: true,
        items: sectionItems,
      });
      continue;
    }

    const topics = topicBundles
      .filter((topic) => topic.topic_id.startsWith(`${parent.topic_id}/`))
      .sort((a, b) => a.order - b.order)
      .map((topic) => ({
        text: topic.title,
        link: `/${topic.topic_id}`,
      }));

    items.push({
      text: parent.label,
      link: `/${parent.topic_id}`,
      collapsed: true,
      items: topics,
    });
  }

  return [
    {
      // Single wrapper so VitePress doesn't split leaf links (Dashboard) and
      // sections (Algorithms) into separate padded .group blocks.
      items,
    },
  ];
}

async function main() {
  const config = loadConfig();
  const practiceFiles = await fg(config.include, { cwd: ROOT, absolute: false });

  /** @type {Map<string, object>} */
  const problemMap = new Map();

  for (const file of practiceFiles) {
    const raw = readFile(file);
    const { data, content } = matter(raw);
    const topicId = data.topic_id;
    if (!topicId) continue;

    const label = topicLabel(topicId, config, data.title);

    if (data.kind === "patterns") {
      for (const pattern of parsePatternSections(raw)) {
        for (const problem of pattern.problems) {
          upsertProblem(problemMap, problem, topicId, label, {
            pattern: pattern.name,
          });
        }
      }
    }

    if (data.kind === "practice" && data.tier) {
      for (const problem of extractProblems(content)) {
        upsertProblem(problemMap, problem, topicId, label, {
          difficulty: data.tier,
        });
      }
    }
  }

  const problems = [...problemMap.values()].map((p) => ({
    slug: p.slug,
    title: p.title,
    url: p.url,
    topic_id: p.topic_id,
    topic_title: p.topic_title,
    patterns: [...p.patterns],
    difficulties: [...p.difficulties],
  }));

  problems.sort((a, b) => a.title.localeCompare(b.title));

  const views = {
    global: problems.map((p) => p.slug),
    byTopic: groupBy(problems, (p) => p.topic_id),
    byPattern: groupProblemsByPattern(problems),
    byDifficulty: groupBy(problems, (p) =>
      p.difficulties.length ? p.difficulties : ["uncategorized"],
    ),
  };

  const topicIds = new Set(problems.map((p) => p.topic_id));
  for (const key of Object.keys(config.topics ?? {})) {
    topicIds.add(key);
  }

  const topicBundles = [...topicIds]
    .map((id) => buildTopicBundle(id, config))
    .filter(Boolean)
    .sort((a, b) => a.order - b.order);

  ensureDir(TOPICS_DIR);
  for (const topic of topicBundles) {
    fs.writeFileSync(
      path.join(TOPICS_DIR, `${slugifyTopicId(topic.topic_id)}.json`),
      JSON.stringify(topic, null, 2),
    );
  }

  const site = {
    generated_at: new Date().toISOString(),
    site: {
      name: config.site?.name ?? "MyGrindSheet",
      description:
        config.site?.description ??
        "Patterns, theory, and practice for algorithms and data structures",
      home_title: config.site?.home_title ?? "Home",
    },
    config: {
      default_view: config.homepage?.default_view ?? "global",
      views: config.views ?? ["global", "byTopic", "byPattern", "byDifficulty"],
    },
    categories: config.categories ?? [],
    topics: topicBundles.map(({ topic_id, title, order }) => ({
      topic_id,
      title,
      order,
    })),
    problems,
    views,
    stats: { total: problems.length },
  };

  ensureDir(DATA_DIR);
  fs.writeFileSync(path.join(DATA_DIR, "site.json"), JSON.stringify(site, null, 2));

  fs.writeFileSync(
    path.join(DOCS, "index.md"),
    `---
cpLayout: home
title: ${config.site?.home_title ?? "Home"}
pageClass: cp-custom
outline: false
aside: false
---
`,
  );

  writeTopicPages(topicBundles, config.categories ?? []);
  cleanLegacyGeneratedDocs();
  fs.writeFileSync(
    path.join(DOCS, ".vitepress", "sidebar.json"),
    JSON.stringify(buildSidebar(config.categories ?? [], topicBundles), null, 2),
  );

  console.log(
    `Built index: ${problems.length} unique problems, ${topicBundles.length} topics`,
  );
}

function upsertProblem(map, problem, topicId, topicTitle, meta) {
  let entry = map.get(problem.slug);
  if (!entry) {
    entry = {
      slug: problem.slug,
      title: problem.title,
      url: problem.url,
      topic_id: topicId,
      topic_title: topicTitle,
      patterns: new Set(),
      difficulties: new Set(),
    };
    map.set(problem.slug, entry);
  }

  if (meta.pattern) entry.patterns.add(meta.pattern);
  if (meta.difficulty) entry.difficulties.add(meta.difficulty);
}

function groupBy(items, keyFn) {
  /** @type {Record<string, string[]>} */
  const out = {};
  for (const item of items) {
    const keys = keyFn(item);
    const list = Array.isArray(keys) ? keys : [keys];
    for (const key of list) {
      if (!out[key]) out[key] = [];
      out[key].push(item.slug);
    }
  }
  return out;
}

function groupProblemsByPattern(problems) {
  /** @type {Record<string, string[]>} */
  const out = {};
  for (const problem of problems) {
    for (const pattern of problem.patterns) {
      if (!out[pattern]) out[pattern] = [];
      out[pattern].push(problem.slug);
    }
  }
  return out;
}

main().catch((err) => {
  console.error(err);
  process.exit(1);
});
