import { inject, provide, ref, watch } from "vue";
import { inBrowser } from "vitepress";
import { DEFAULT_SITE_LANGUAGE, SITE_LANGUAGES } from "../utils/codeLanguages.js";

const SITE_LANGUAGE_KEY = Symbol("cp-site-language");
const STORAGE_KEY = "cp-language";

function readStoredLanguage() {
  if (!inBrowser) return DEFAULT_SITE_LANGUAGE;
  const stored = localStorage.getItem(STORAGE_KEY);
  return SITE_LANGUAGES.some((lang) => lang.id === stored)
    ? stored
    : DEFAULT_SITE_LANGUAGE;
}

export function provideSiteLanguage() {
  const language = ref(readStoredLanguage());

  if (inBrowser) {
    watch(language, (value) => {
      localStorage.setItem(STORAGE_KEY, value);
    });
  }

  provide(SITE_LANGUAGE_KEY, language);
  return language;
}

export function useSiteLanguage() {
  const language = inject(SITE_LANGUAGE_KEY);
  if (!language) {
    throw new Error("useSiteLanguage() called without provideSiteLanguage()");
  }
  return { language, languages: SITE_LANGUAGES };
}
