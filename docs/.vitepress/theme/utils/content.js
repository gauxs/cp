export const LEETCODE_FAVICON =
  "https://assets.leetcode.com/static_assets/public/icons/favicon-32x32.png";

export const LEETCODE_RE =
  /\[([^\]]+)\]\(https:\/\/leetcode\.com\/problems\/([^/)]+)\/?\)/g;

export function extractProblems(markdown) {
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

export function parsePatterns(markdown) {
  const body = markdown.replace(/^---[\s\S]*?---\n/, "");
  return body
    .split(/\n---\n/)
    .map((section) => {
      const name = section.match(/^## Pattern:\s*(.+)$/m)?.[1]?.trim();
      if (!name) return null;

      const field = (label) =>
        section.match(new RegExp(`\\*\\*${label}:\\*\\*\\s*(.+)`))?.[1]?.trim() ??
        "";

      const skillsBlock = section.match(/### Key skills\n([\s\S]*?)(?=\n---|$)/)?.[1] ?? "";
      const skills = skillsBlock
        .split("\n")
        .map((line) => line.replace(/^-\s*/, "").trim())
        .filter(Boolean);

      return {
        name,
        useWhen: field("Use when"),
        pattern: field("Pattern"),
        insight: field("Key insight"),
        problems: extractProblems(section),
        skills,
      };
    })
    .filter(Boolean);
}

export function stripFrontmatter(markdown) {
  return markdown.replace(/^---[\s\S]*?---\n/, "");
}
