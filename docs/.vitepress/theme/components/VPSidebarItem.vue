<script setup>
import { computed } from "vue";
import { useSidebarControl } from "vitepress/dist/client/theme-default/composables/sidebar.js";
import VPLink from "vitepress/dist/client/theme-default/components/VPLink.vue";

const props = defineProps({
  item: { type: Object, required: true },
  depth: { type: Number, required: true },
});

const {
  collapsed,
  collapsible,
  isLink,
  isActiveLink,
  hasActiveLink,
  hasChildren,
} = useSidebarControl(computed(() => props.item));

const sectionTag = computed(() => (hasChildren.value ? "section" : "div"));

const classes = computed(() => [
  [`level-${props.depth}`],
  { collapsible: collapsible.value },
  { collapsed: collapsed.value },
  { "is-link": isLink.value },
  { "is-active": isActiveLink.value },
  { "has-active": hasActiveLink.value },
  { "has-children": hasChildren.value },
]);

function onParentClick(event) {
  if ("key" in event && event.key !== "Enter") return;

  event.preventDefault();
  event.stopPropagation();

  if (hasChildren.value) {
    collapsed.value = !collapsed.value;
  }
}
</script>

<template>
  <component :is="sectionTag" class="VPSidebarItem" :class="classes">
    <div
      v-if="item.text"
      class="item"
      :class="{ 'item-parent': hasChildren }"
      :role="hasChildren ? 'button' : undefined"
      :tabindex="hasChildren ? 0 : undefined"
      v-on="hasChildren ? { click: onParentClick, keydown: onParentClick } : {}"
    >
      <span class="indicator" />

      <VPLink v-if="!hasChildren && item.link" tag="a" class="link" :href="item.link">
        <span class="text" v-html="item.text" />
      </VPLink>
      <span v-else class="text" v-html="item.text" />

      <span
        v-if="hasChildren && item.items && item.items.length"
        class="caret"
        aria-hidden="true"
      >
        <span class="vpi-chevron-right caret-icon" />
      </span>
    </div>

    <div v-if="item.items && item.items.length" class="items">
      <template v-if="depth < 5">
        <VPSidebarItem
          v-for="child in item.items"
          :key="child.text"
          :item="child"
          :depth="depth + 1"
        />
      </template>
    </div>
  </component>
</template>

<style scoped>
.VPSidebarItem.level-0 {
  padding-bottom: 0;
}

.VPSidebarItem.collapsed.level-0 {
  padding-bottom: 0;
}

.item {
  position: relative;
  display: flex;
  align-items: center;
  gap: 4px;
  width: 100%;
  min-height: 30px;
  padding: 0 4px;
  border-radius: 6px;
}

.item-parent {
  cursor: pointer;
}

.item-parent:hover {
  background: var(--vp-c-default-soft);
}

.indicator {
  position: absolute;
  top: 5px;
  bottom: 5px;
  left: 0;
  width: 2px;
  border-radius: 2px;
  transition: background-color 0.2s;
}

.VPSidebarItem.level-2.is-active > .item > .indicator,
.VPSidebarItem.level-3.is-active > .item > .indicator,
.VPSidebarItem.level-4.is-active > .item > .indicator,
.VPSidebarItem.level-5.is-active > .item > .indicator {
  background-color: var(--vp-c-brand-1);
}

.link {
  display: flex;
  align-items: center;
  flex: 1;
  min-width: 0;
  text-decoration: none;
}

.text {
  flex: 1;
  min-width: 0;
  margin: 0;
  padding: 4px 0;
  line-height: 1.35;
  font-size: 13px;
  font-weight: 500;
  color: var(--vp-c-text-2);
  transition: color 0.2s;
  white-space: nowrap;
}

.VPSidebarItem.level-0 .text {
  font-weight: 600;
  color: var(--vp-c-text-1);
}

.VPSidebarItem.is-link > .item > .link:hover .text {
  color: var(--vp-c-brand-1);
}

.VPSidebarItem.has-active > .item > .text,
.VPSidebarItem.has-active > .item > .link > .text {
  color: var(--vp-c-text-1);
}

.VPSidebarItem.is-active > .item .link > .text,
.VPSidebarItem.is-active > .item > .text {
  color: var(--vp-c-brand-1);
}

.caret {
  display: inline-flex;
  align-items: center;
  justify-content: center;
  width: 18px;
  height: 18px;
  color: var(--vp-c-text-3);
  flex-shrink: 0;
}

.caret-icon {
  font-size: 12px;
  transform: rotate(90deg);
  transition: transform 0.2s;
}

.VPSidebarItem.collapsed .caret-icon {
  transform: rotate(0);
}

.VPSidebarItem.level-1 .items,
.VPSidebarItem.level-2 .items,
.VPSidebarItem.level-3 .items,
.VPSidebarItem.level-4 .items,
.VPSidebarItem.level-5 .items {
  border-left: 1px solid var(--vp-c-divider);
  padding-left: 10px;
  margin-top: 2px;
}

.VPSidebarItem.collapsed .items {
  display: none;
}
</style>
