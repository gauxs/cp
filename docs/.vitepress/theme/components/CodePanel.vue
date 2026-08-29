<script setup>
import { computed } from "vue";
import { highlightCodeLines } from "../utils/highlight.js";

const props = defineProps({
  filename: { type: String, required: true },
  content: { type: String, required: true },
  language: { type: String, default: "cpp" },
});

const lines = computed(() => highlightCodeLines(props.content, props.language));
const lineCount = computed(() => lines.value.length);
const gutterWidth = computed(
  () => `${Math.max(2, String(lineCount.value).length)}ch`,
);
</script>

<template>
  <div class="lc-code-panel">
    <div class="lc-code-header">
      <span class="lc-code-filename">{{ filename }}</span>
      <span class="lc-code-lang">{{ language }}</span>
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
