<script setup>
import { computed } from "vue";
import { useProgress } from "../composables/useProgress.js";
import { extractProblems } from "../utils/content.js";
import LeetCodeProblemRow from "./LeetCodeProblemRow.vue";

const props = defineProps({
  markdown: { type: String, required: true },
  heading: { type: String, default: "" },
});

const { isDone, toggle } = useProgress();

const problems = computed(() => extractProblems(props.markdown));

const doneCount = computed(
  () => problems.value.filter((p) => isDone(p.slug)).length,
);
</script>

<template>
  <section v-if="problems.length" class="lc-tier-block">
    <div v-if="heading" class="lc-tier-header">
      <h3>{{ heading }}</h3>
      <span>{{ doneCount }} / {{ problems.length }}</span>
    </div>
    <div class="lc-problem-list">
      <LeetCodeProblemRow
        v-for="problem in problems"
        :key="problem.slug"
        :slug="problem.slug"
        :title="problem.title"
        :url="problem.url"
        :done="isDone(problem.slug)"
        @toggle="toggle(problem.slug)"
      />
    </div>
  </section>
</template>
