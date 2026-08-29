<script setup>
import MarkdownIt from "markdown-it";

const props = defineProps({
  source: { type: String, required: true },
});

const md = new MarkdownIt({ html: true, linkify: true });
const html = md.render(props.source);
</script>

<template>
  <div class="markdown-body" v-html="html" />
</template>
