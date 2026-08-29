<script setup>
import { computed } from "vue";
import { useProgress } from "../composables/useProgress.js";

const props = defineProps({
  markdown: { type: String, required: true },
});

const { isDone, toggle } = useProgress();

const LEETCODE_RE =
  /\[([^\]]+)\]\(https:\/\/leetcode\.com\/problems\/([^/)]+)\/?\)/g;

const problems = computed(() => {
  const items = [];
  let match;
  const re = new RegExp(LEETCODE_RE.source, "g");
  while ((match = re.exec(props.markdown)) !== null) {
    items.push({
      slug: match[2],
      title: match[1].trim(),
      url: `https://leetcode.com/problems/${match[2]}/`,
    });
  }
  return items;
});
</script>

<template>
  <div v-if="problems.length" class="problem-checklist">
    <h3>Progress</h3>
    <label v-for="problem in problems" :key="problem.slug" class="problem-row">
      <input
        type="checkbox"
        :checked="isDone(problem.slug)"
        @change="toggle(problem.slug)"
      />
      <a :href="problem.url" target="_blank" rel="noopener">{{ problem.title }}</a>
    </label>
  </div>
</template>
