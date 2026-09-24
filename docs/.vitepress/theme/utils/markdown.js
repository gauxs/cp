import MarkdownIt from "markdown-it";
import { withBase } from "vitepress";
import { highlightCode, DEFAULT_CODE_LANG } from "./highlight.js";
import { useTexMath } from "../../math-plugin.mjs";

const md = new MarkdownIt({
  html: true,
  linkify: true,
  typographer: false,
});

useTexMath(md);

md.renderer.rules.fence = (tokens, idx) => {
  const token = tokens[idx];
  const lang = (token.info || "").trim() || DEFAULT_CODE_LANG;
  const highlighted = highlightCode(token.content, lang);
  return `<pre class="lc-markdown-code"><code class="hljs language-${lang}">${highlighted}</code></pre>\n`;
};

const defaultLinkOpen =
  md.renderer.rules.link_open ||
  ((tokens, idx, options, env, self) => self.renderToken(tokens, idx, options));

const defaultLinkClose =
  md.renderer.rules.link_close ||
  ((tokens, idx, options, env, self) => self.renderToken(tokens, idx, options));

const defaultHeadingOpen =
  md.renderer.rules.heading_open ||
  ((tokens, idx, options, env, self) => self.renderToken(tokens, idx, options));

const defaultBlockquoteOpen =
  md.renderer.rules.blockquote_open ||
  ((tokens, idx, options, env, self) => self.renderToken(tokens, idx, options));

md.renderer.rules.link_open = (tokens, idx, options, env, self) => {
  const hrefIndex = tokens[idx].attrIndex("href");
  if (hrefIndex >= 0) {
    const href = tokens[idx].attrs[hrefIndex][1];
    if (href.startsWith("/") && !href.startsWith("//")) {
      tokens[idx].attrs[hrefIndex][1] = withBase(href);
    }
  }
  return defaultLinkOpen(tokens, idx, options, env, self);
};

md.renderer.rules.blockquote_open = (tokens, idx, options, env, self) => {
  if (env?.notesMode) {
    tokens[idx].attrJoin("class", "lc-note");
  }
  return defaultBlockquoteOpen(tokens, idx, options, env, self);
};

md.renderer.rules.heading_open = (tokens, idx, options, env, self) => {
  const inline = tokens[idx + 1];
  if (tokens[idx].tag === "h2" && inline?.type === "inline") {
    if (inline.content === "Notes") {
      tokens[idx].attrJoin("class", "lc-notes-heading");
    }
  }
  return defaultHeadingOpen(tokens, idx, options, env, self);
};

export function preprocessMarkdown(source, options = {}) {
  let text = source ?? "";

  if (options.stripFrontmatter) {
    text = text.replace(/^---[\s\S]*?---\n/, "");
  }

  if (options.stripLeadingH1) {
    text = text.replace(/^#\s+.+\n+/, "");
  }

  if (options.stripPracticeSection) {
    text = text.replace(/^## Practice[\s\S]*?(?=^## |\Z)/m, "");
  }

  return text;
}

export function renderMarkdown(source, options = {}) {
  const text = preprocessMarkdown(source, options);
  const notesMode = /^## Notes/m.test(text);

  return md.render(text, { notesMode });
}

export function renderInlineMarkdown(source) {
  return md.renderInline(source ?? "");
}

export function renderCodeMarkdown(filename, content, lang = "cpp") {
  return renderMarkdown(`\`${filename}\`\n\n\`\`\`${lang}\n${content}\n\`\`\``);
}

export { md };
