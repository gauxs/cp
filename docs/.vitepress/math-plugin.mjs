import texmath from "markdown-it-texmath";
import katex from "katex";

/** KaTeX via markdown-it-texmath - matches katex 0.18 CSS bundled in theme. */
export function useTexMath(md) {
  md.use(texmath, {
    engine: katex,
    delimiters: "dollars",
    katexOptions: { throwOnError: false },
  });
}
