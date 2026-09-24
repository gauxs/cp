<script setup>
import LeetCodeIcon from "./LeetCodeIcon.vue";
import TierBadge from "./TierBadge.vue";

defineProps({
  slug: { type: String, required: true },
  title: { type: String, required: true },
  url: { type: String, required: true },
  done: { type: Boolean, default: false },
  topicTitle: { type: String, default: "" },
  difficulty: { type: String, default: "" },
  showTopic: { type: Boolean, default: false },
  showDifficulty: { type: Boolean, default: true },
});

defineEmits(["toggle"]);
</script>

<template>
  <div class="lc-problem-row" :class="{ done }">
    <input
      type="checkbox"
      class="lc-checkbox"
      :checked="done"
      @click.stop
      @change="$emit('toggle')"
    />

    <a
      class="lc-problem-open"
      :href="url"
      target="_blank"
      rel="noopener noreferrer"
    >
      <span class="lc-problem-title">{{ title }}</span>
    </a>

    <span
      v-if="(showTopic && topicTitle) || (showDifficulty && difficulty)"
      class="lc-problem-badges"
    >
      <span v-if="showTopic && topicTitle" class="lc-topic-badge">
        {{ topicTitle }}
      </span>

      <TierBadge v-if="showDifficulty && difficulty" :tier="difficulty" />
    </span>

    <a
      class="lc-problem-link"
      :href="url"
      target="_blank"
      rel="noopener noreferrer"
      aria-label="Open on LeetCode"
      @click.stop
    >
      <LeetCodeIcon :size="20" />
    </a>
  </div>
</template>
