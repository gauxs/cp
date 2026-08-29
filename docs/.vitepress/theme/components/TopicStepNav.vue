<script setup>
import { computed } from "vue";

const props = defineProps({
  tabs: { type: Array, required: true },
  activeTab: { type: String, required: true },
  showTrack: { type: Boolean, default: false },
  showFooter: { type: Boolean, default: false },
});

const emit = defineEmits(["update:activeTab"]);

const activeIndex = computed(() =>
  props.tabs.findIndex((tab) => tab.id === props.activeTab),
);

const prevTab = computed(() =>
  activeIndex.value > 0 ? props.tabs[activeIndex.value - 1] : null,
);

const nextTab = computed(() =>
  activeIndex.value < props.tabs.length - 1
    ? props.tabs[activeIndex.value + 1]
    : null,
);
</script>

<template>
  <nav class="topic-stepper" aria-label="Topic sections">
    <ol v-if="showTrack" class="topic-stepper-track">
      <li
        v-for="(tab, index) in tabs"
        :key="tab.id"
        class="topic-stepper-item"
        :class="{
          active: tab.id === activeTab,
          done: index < activeIndex,
        }"
      >
        <button
          type="button"
          class="topic-stepper-btn"
          :aria-current="tab.id === activeTab ? 'step' : undefined"
          @click="emit('update:activeTab', tab.id)"
        >
          <span class="topic-stepper-num">{{ index + 1 }}</span>
          <span class="topic-stepper-label">{{ tab.label }}</span>
        </button>
      </li>
    </ol>

    <div v-if="showFooter" class="topic-stepper-footer">
      <button
        v-if="prevTab"
        type="button"
        class="topic-stepper-nav"
        @click="emit('update:activeTab', prevTab.id)"
      >
        <span class="topic-stepper-nav-arrow" aria-hidden="true">←</span>
        <span class="topic-stepper-nav-label">{{ prevTab.label }}</span>
      </button>
      <div v-else class="topic-stepper-nav-spacer" />

      <button
        v-if="nextTab"
        type="button"
        class="topic-stepper-nav"
        @click="emit('update:activeTab', nextTab.id)"
      >
        <span class="topic-stepper-nav-label">{{ nextTab.label }}</span>
        <span class="topic-stepper-nav-arrow" aria-hidden="true">→</span>
      </button>
      <div v-else class="topic-stepper-nav-spacer" />
    </div>
  </nav>
</template>
