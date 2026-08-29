import MarkdownIt from "markdown-it";
import hljs from "highlight.js";

const md = new MarkdownIt({
  html: true,
  linkify: true,
  typographer: false,
  highlight(str, lang) {
    if (lang && hljs.getLanguage(lang)) {
      try {
        return hljs.highlight(str, { language: lang }).value;
      } catch {
        /* fall through */
      }
    }
    return hljs.highlightAuto(str).value;
  },
});

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

export function renderCodeMarkdown(filename, content, lang = "cpp") {
  return renderMarkdown(`\`${filename}\`\n\n\`\`\`${lang}\n${content}\n\`\`\``);
}

export { md };
