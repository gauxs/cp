<script setup>
import { computed } from "vue";
import { renderMarkdown } from "../utils/markdown.js";

const props = defineProps({
  source: { type: String, required: true },
  stripLeadingH1: { type: Boolean, default: true },
  stripFrontmatter: { type: Boolean, default: false },
  stripPracticeSection: { type: Boolean, default: false },
});

const html = computed(() =>
  renderMarkdown(props.source, {
    stripLeadingH1: props.stripLeadingH1,
    stripFrontmatter: props.stripFrontmatter,
    stripPracticeSection: props.stripPracticeSection,
  }),
);
</script>

<template>
  <div class="markdown-body lc-content" v-html="html" />
</template>
