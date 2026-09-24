<script setup>
import { computed } from "vue";

const props = defineProps({
  done: { type: Number, default: 0 },
  total: { type: Number, default: 0 },
});

const radius = 54;
const circumference = 2 * Math.PI * radius;

const percent = computed(() =>
  props.total ? Math.round((props.done / props.total) * 100) : 0,
);

const dashOffset = computed(
  () => circumference - (percent.value / 100) * circumference,
);
</script>

<template>
  <div
    class="progress-ring"
    role="img"
    :aria-label="`${done} of ${total} problems completed (${percent}%)`"
  >
    <svg viewBox="0 0 120 120" aria-hidden="true">
      <circle class="progress-ring-bg" cx="60" cy="60" :r="radius" />
      <circle
        class="progress-ring-fill"
        cx="60"
        cy="60"
        :r="radius"
        :stroke-dasharray="circumference"
        :stroke-dashoffset="dashOffset"
      />
    </svg>
    <div class="progress-ring-center">
      <span class="progress-ring-percent">{{ percent }}%</span>
    </div>
  </div>
</template>
