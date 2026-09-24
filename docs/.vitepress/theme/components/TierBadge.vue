<script setup>
import { formatTier } from "../utils/tiers.js";

defineProps({
  tier: { type: String, required: true },
});
</script>

<template>
  <span class="lc-tier-label" :class="`tier-${tier}`">
    <span class="lc-tier-dot" aria-hidden="true" />
    {{ formatTier(tier) }}
  </span>
</template>
