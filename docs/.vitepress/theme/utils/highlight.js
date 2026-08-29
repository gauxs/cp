import hljs from "highlight.js";

function highlightHtml(source, lang = "cpp") {
  const trimmed = (source ?? "").trim();
  if (lang && hljs.getLanguage(lang)) {
    return hljs.highlight(trimmed, { language: lang }).value;
  }
  return hljs.highlightAuto(trimmed).value;
}

export function highlightCode(source, lang = "cpp") {
  return highlightHtml(source, lang);
}

/** Split highlighted output into lines for gutter alignment. */
export function highlightCodeLines(source, lang = "cpp") {
  const html = highlightHtml(source, lang);
  const split = html.split("\n");
  if (split.length > 1 && split[split.length - 1] === "") {
    split.pop();
  }
  return split;
}
