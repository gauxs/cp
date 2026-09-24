<script setup>
const props = defineProps({
  size: { type: Number, default: 18 },
});
</script>

<template>
  <img
    class="lc-favicon"
    src="https://assets.leetcode.com/static_assets/public/icons/favicon-32x32.png"
    alt="LeetCode"
    :width="size"
    :height="size"
    loading="lazy"
  />
</template>

<style scoped>
.lc-favicon {
  display: block;
  flex-shrink: 0;
  border-radius: 4px;
}
</style>
