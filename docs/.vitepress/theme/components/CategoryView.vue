<script setup>
import { computed, onMounted, ref } from "vue";
import { useData, withBase } from "vitepress";
import { topicDataSlug, topicPageUrl, categoryPageUrl, compareTopicIds } from "../utils/routes.js";
import TopicBreadcrumb from "./TopicBreadcrumb.vue";

const { frontmatter } = useData();
const site = ref(null);
const topics = ref([]);
const loading = ref(true);
const error = ref("");

const childCategories = computed(() => {
  if (!site.value) return [];
  return site.value.categories
    .filter((category) => category.parent === frontmatter.value.topic_id)
    .sort((a, b) => a.label.localeCompare(b.label));
});

onMounted(async () => {
  try {
    const res = await fetch(withBase("/data/site.json"));
    if (!res.ok) throw new Error(`site.json (${res.status})`);
    site.value = await res.json();

    const subcategories = site.value.categories.filter(
      (category) => category.parent === frontmatter.value.topic_id,
    );

    if (subcategories.length > 0) {
      return;
    }

    const prefix = `${frontmatter.value.topic_id}/`;
    const childTopics = site.value.topics
      .filter((t) => t.topic_id.startsWith(prefix))
      .sort(compareTopicIds);

    for (const child of childTopics) {
      const slug = topicDataSlug(child.topic_id);
      const topicRes = await fetch(withBase(`/data/topics/${slug}.json`));
      if (topicRes.ok) {
        topics.value.push(await topicRes.json());
      }
    }
  } catch (err) {
    error.value = err.message ?? "Failed to load category";
  } finally {
    loading.value = false;
  }
});

function topicLink(topicId) {
  return topicPageUrl(topicId);
}

function subcategoryLink(categoryId) {
  return categoryPageUrl(categoryId);
}

function problemCount(topicId) {
  if (!site.value) return 0;
  return site.value.problems.filter((p) => p.topic_id === topicId).length;
}

function problemCountUnder(prefix) {
  if (!site.value) return 0;
  return site.value.problems.filter((p) =>
    p.topic_id.startsWith(`${prefix}/`),
  ).length;
}

function problemCountLabel(count) {
  return count === 1 ? "1 problem" : `${count} problems`;
}
</script>

<template>
  <div class="page-shell category-page">
    <header class="page-header category-header">
      <TopicBreadcrumb
        v-if="site"
        ancestors-only
        :topic-id="frontmatter.topic_id"
        :title="frontmatter.title"
        :categories="site.categories"
      />
      <h1>
        {{ frontmatter.title
        }}<span class="topic-title-sep"> - </span
        ><span class="topic-title-section">Overview</span>
      </h1>
    </header>

    <p v-if="loading" class="status-msg">Loading…</p>
    <p v-else-if="error" class="status-msg error">{{ error }}</p>

    <div v-else-if="childCategories.length" class="topic-grid">
      <a
        v-for="category in childCategories"
        :key="category.topic_id"
        class="topic-card"
        :href="subcategoryLink(category.topic_id)"
      >
        <h2 class="topic-card-title">{{ category.label }}</h2>
        <p class="topic-card-count">
          {{ problemCountLabel(problemCountUnder(category.topic_id)) }}
        </p>
      </a>
    </div>

    <div v-else-if="topics.length" class="topic-grid">
      <a
        v-for="topic in topics"
        :key="topic.topic_id"
        class="topic-card"
        :href="topicLink(topic.topic_id)"
      >
        <h2 class="topic-card-title">{{ topic.title }}</h2>
        <p class="topic-card-count">{{ problemCountLabel(problemCount(topic.topic_id)) }}</p>
      </a>
    </div>

    <p v-else class="status-msg">No topics found for this category.</p>
  </div>
</template>
