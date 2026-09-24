<script setup>
import { computed } from "vue";
import { categoryPageUrl } from "../utils/routes.js";

const props = defineProps({
  topicId: { type: String, required: true },
  title: { type: String, required: true },
  categories: { type: Array, default: () => [] },
  ancestorsOnly: { type: Boolean, default: false },
});

function humanize(segment) {
  return segment
    .replace(/_/g, " ")
    .replace(/\b\w/g, (char) => char.toUpperCase());
}

const crumbs = computed(() => {
  const parts = props.topicId.split("/");
  const categoryById = Object.fromEntries(
    props.categories.map((category) => [category.topic_id, category.label]),
  );

  const all = parts.map((_, index) => {
    const path = parts.slice(0, index + 1).join("/");
    const isLast = index === parts.length - 1;
    const label = isLast
      ? props.title
      : (categoryById[path] ?? humanize(parts[index]));

    let href = null;
    if (!isLast && categoryById[path]) {
      href = categoryPageUrl(path);
    }

    return { label, href, current: isLast };
  });

  return props.ancestorsOnly ? all.slice(0, -1) : all;
});
</script>

<template>
  <nav v-if="crumbs.length" class="topic-breadcrumb" aria-label="Breadcrumb">
    <template v-for="(crumb, index) in crumbs" :key="`${crumb.label}-${index}`">
      <span v-if="index > 0" class="topic-breadcrumb-sep" aria-hidden="true">/</span>
      <a v-if="crumb.href" :href="crumb.href">{{ crumb.label }}</a>
      <span
        v-else
        class="topic-breadcrumb-current"
        :aria-current="crumb.current ? 'page' : undefined"
      >
        {{ crumb.label }}
      </span>
    </template>
  </nav>
</template>
