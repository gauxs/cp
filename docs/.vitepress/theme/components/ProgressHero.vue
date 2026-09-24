<script setup>
import { computed } from "vue";
import ProgressRing from "./ProgressRing.vue";

const props = defineProps({
  problems: { type: Array, required: true },
  doneCount: { type: Function, required: true },
  progress: { type: Object, required: true },
});

const slugs = computed(() => props.problems.map((problem) => problem.slug));

const total = computed(() => props.problems.length);
const done = computed(() => {
  props.progress;
  return props.doneCount(slugs.value);
});
const remaining = computed(() => Math.max(total.value - done.value, 0));
</script>

<template>
  <section class="progress-card" aria-label="Practice progress">
    <div class="progress-card-top">
      <ProgressRing :done="done" :total="total" />

      <div class="progress-card-copy">
        <h1>Practice Tracker</h1>
        <div class="progress-stat-grid">
          <div class="progress-stat">
            <span class="progress-stat-value">{{ done }}</span>
            <span class="progress-stat-label">Completed</span>
          </div>
          <div class="progress-stat">
            <span class="progress-stat-value">{{ remaining }}</span>
            <span class="progress-stat-label">Remaining</span>
          </div>
          <div class="progress-stat">
            <span class="progress-stat-value">{{ total }}</span>
            <span class="progress-stat-label">Total</span>
          </div>
        </div>
      </div>
    </div>
  </section>
</template>
