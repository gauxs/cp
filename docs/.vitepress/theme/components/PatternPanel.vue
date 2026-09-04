<script setup>
import { computed } from "vue";
import { parsePatterns } from "../utils/content.js";
import { useProgress } from "../composables/useProgress.js";
import LeetCodeProblemRow from "./LeetCodeProblemRow.vue";
import InlineMarkdown from "./InlineMarkdown.vue";

const props = defineProps({
  markdown: { type: String, required: true },
});

const { isDone, toggle, doneCount } = useProgress();

const patterns = computed(() => parsePatterns(props.markdown));

function patternDoneCount(pattern) {
  const slugs = pattern.problems.map((p) => p.slug);
  return doneCount(slugs);
}
</script>

<template>
  <div class="lc-pattern-list">
    <details
      v-for="(pattern, index) in patterns"
      :key="pattern.name"
      class="lc-pattern-item"
    >
      <summary class="lc-pattern-summary">
        <span class="lc-pattern-index">{{ index + 1 }}</span>
        <span class="lc-pattern-name">{{ pattern.name }}</span>
        <span v-if="pattern.problems.length" class="lc-pattern-count">
          {{ patternDoneCount(pattern) }} / {{ pattern.problems.length }}
        </span>
        <span class="lc-chevron" aria-hidden="true" />
      </summary>

      <div class="lc-pattern-body">
        <dl class="lc-pattern-fields">
          <template v-if="pattern.useWhen">
            <dt>Use when</dt>
            <dd><InlineMarkdown :source="pattern.useWhen" /></dd>
          </template>
          <template v-if="pattern.pattern">
            <dt>Pattern</dt>
            <dd><InlineMarkdown :source="pattern.pattern" /></dd>
          </template>
          <template v-if="pattern.insight">
            <dt>Key insight</dt>
            <dd><InlineMarkdown :source="pattern.insight" /></dd>
          </template>
        </dl>

        <div v-if="pattern.skills.length" class="lc-skill-list">
          <p class="lc-subheading">Key skills</p>
          <ol class="lc-skill-items">
            <li
              v-for="(skill, skillIndex) in pattern.skills"
              :key="skill"
              class="lc-skill-item"
            >
              <span class="lc-skill-num">{{ skillIndex + 1 }}</span>
              <span class="lc-skill-text"><InlineMarkdown :source="skill" /></span>
            </li>
          </ol>
        </div>

        <section v-if="pattern.problems.length" class="lc-pattern-problems">
          <div class="lc-pattern-problems-header">
            <p class="lc-subheading">Practice problems</p>
            <span class="lc-pattern-problems-count">
              {{ patternDoneCount(pattern) }} / {{ pattern.problems.length }}
            </span>
          </div>
          <div class="lc-problem-list lc-pattern-problem-list">
            <LeetCodeProblemRow
              v-for="problem in pattern.problems"
              :key="`${pattern.name}-${problem.slug}`"
              :slug="problem.slug"
              :title="problem.title"
              :url="problem.url"
              :done="isDone(problem.slug)"
              @toggle="toggle(problem.slug)"
            />
          </div>
        </section>
      </div>
    </details>
  </div>
</template>
