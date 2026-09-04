<script setup>
import { computed, ref, watch } from "vue";
import { highlightCodeLines } from "../utils/highlight.js";
import {
  CODE_LANGUAGES,
  DEFAULT_SITE_LANGUAGE,
  languageLabel,
} from "../utils/codeLanguages.js";
import { useSiteLanguage } from "../composables/useSiteLanguage.js";

const { language: siteLanguage } = useSiteLanguage();

const props = defineProps({
  filename: { type: String, required: true },
  content: { type: String, required: true },
  language: { type: String, default: "cpp" },
  /** Future: per-language files - [{ language, label?, filename, content }] */
  variants: { type: Array, default: null },
  languages: { type: Array, default: () => CODE_LANGUAGES },
});

const selectedLanguage = ref(
  props.variants?.[0]?.language ??
    props.language ??
    siteLanguage.value ??
    DEFAULT_SITE_LANGUAGE,
);

watch(
  () => props.variants,
  (variants) => {
    if (variants?.length) {
      selectedLanguage.value = variants[0].language;
    }
  },
);

watch(
  siteLanguage,
  (lang) => {
    if (!props.variants?.length) {
      selectedLanguage.value = lang;
    }
  },
);

const languageOptions = computed(() => {
  if (props.variants?.length) {
    return props.variants.map((variant) => ({
      id: variant.language,
      label: variant.label ?? languageLabel(variant.language),
    }));
  }
  return props.languages;
});

const activeSource = computed(() => {
  if (props.variants?.length) {
    const match =
      props.variants.find((v) => v.language === selectedLanguage.value) ??
      props.variants[0];
    return {
      filename: match.filename,
      content: match.content,
      language: match.language,
    };
  }
  return {
    filename: props.filename,
    content: props.content,
    language: selectedLanguage.value,
  };
});

const lines = computed(() =>
  highlightCodeLines(activeSource.value.content, activeSource.value.language),
);
const lineCount = computed(() => lines.value.length);
const gutterWidth = computed(
  () => `${Math.max(2, String(lineCount.value).length)}ch`,
);
</script>

<template>
  <div class="lc-code-panel">
    <div class="lc-code-header">
      <span class="lc-code-filename">{{ activeSource.filename }}</span>
      <div class="lc-code-lang-wrap">
        <select
          id="lc-code-lang-select"
          class="lc-code-lang-select"
          v-model="selectedLanguage"
          aria-label="Code language"
        >
          <option v-for="opt in languageOptions" :key="opt.id" :value="opt.id">
            {{ opt.label }}
          </option>
        </select>
      </div>
    </div>
    <div class="lc-code-body">
      <div
        class="lc-code-gutter"
        aria-hidden="true"
        :style="{ minWidth: `calc(${gutterWidth} + 22px)` }"
      >
        <span v-for="n in lineCount" :key="n" class="lc-code-ln">{{ n }}</span>
      </div>
      <pre class="lc-code-block"><code class="hljs"><span
          v-for="(line, index) in lines"
          :key="index"
          class="lc-code-line"
          v-html="line || '&#8203;'"
        /></code></pre>
    </div>
  </div>
</template>
