<script setup>
import { computed } from "vue";
import { renderInlineMarkdown } from "../utils/markdown.js";

const props = defineProps({
  source: { type: String, required: true },
});

const html = computed(() => renderInlineMarkdown(props.source));
</script>

<template>
  <span class="lc-inline-md" v-html="html" />
</template>
