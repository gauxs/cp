<script setup>
import { computed } from "vue";
import { useProgress } from "../composables/useProgress.js";
import { extractProblems, parsePracticeTiers } from "../utils/content.js";
import { formatTier } from "../utils/tiers.js";
import LeetCodeProblemRow from "./LeetCodeProblemRow.vue";

const props = defineProps({
  tiers: { type: Array, required: true },
});

const { isDone, toggle, doneCount } = useProgress();

const tierOrder = ["beginner", "intermediate", "advanced"];

const sortedTiers = computed(() => {
  const files = props.tiers;
  if (files.length === 1 && !files[0].tier) {
    const parsed = parsePracticeTiers(files[0].content);
    if (parsed.length) return parsed;
  }

  return [...files]
    .filter((f) => f.tier)
    .sort((a, b) => tierOrder.indexOf(a.tier) - tierOrder.indexOf(b.tier));
});

function tierProblems(tier) {
  return extractProblems(tier.content);
}

function tierDone(tier) {
  return doneCount(tierProblems(tier).map((p) => p.slug));
}
</script>

<template>
  <div class="lc-practice-panel">
    <details
      v-for="(tier, index) in sortedTiers"
      :key="tier.tier"
      class="lc-tier-item"
    >
      <summary class="lc-tier-summary">
        <span class="lc-tier-index">{{ index + 1 }}</span>
        <span class="lc-tier-name">{{ formatTier(tier.tier) }}</span>
        <span class="lc-tier-count">
          {{ tierDone(tier) }} / {{ tierProblems(tier).length }}
        </span>
        <span class="lc-chevron" aria-hidden="true" />
      </summary>

      <div class="lc-tier-body">
        <div class="lc-problem-list">
          <LeetCodeProblemRow
            v-for="problem in tierProblems(tier)"
            :key="problem.slug"
            :slug="problem.slug"
            :title="problem.title"
            :url="problem.url"
            :done="isDone(problem.slug)"
            @toggle="toggle(problem.slug)"
          />
        </div>
      </div>
    </details>
  </div>
</template>
