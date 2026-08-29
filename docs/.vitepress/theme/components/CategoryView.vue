<script setup>
import { computed, onMounted, ref } from "vue";
import { useData, withBase } from "vitepress";

const { frontmatter } = useData();
const site = ref(null);
const topics = ref([]);
const loading = ref(true);
const error = ref("");

onMounted(async () => {
  try {
    const res = await fetch(withBase("/data/site.json"));
    if (!res.ok) throw new Error(`site.json (${res.status})`);
    site.value = await res.json();

    const prefix = `${frontmatter.value.topic_id}/`;
    const childTopics = site.value.topics
      .filter((t) => t.topic_id.startsWith(prefix))
      .sort((a, b) => a.order - b.order);

    for (const child of childTopics) {
      const slug = child.topic_id.replace(/\//g, "-");
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

const categorySlug = computed(() =>
  frontmatter.value.topic_id.replace(/\//g, "-"),
);

function topicLink(topicId) {
  const slug = topicId.split("/").pop();
  return withBase(`/${categorySlug.value}/${slug}`);
}

function problemCount(topicId) {
  if (!site.value) return 0;
  return site.value.problems.filter((p) => p.topic_id === topicId).length;
}
</script>

<template>
  <div class="page-shell">
    <header class="page-header">
      <p class="eyebrow">Category</p>
      <h1>{{ frontmatter.title }}</h1>
    </header>

    <p v-if="loading" class="status-msg">Loading…</p>
    <p v-else-if="error" class="status-msg error">{{ error }}</p>

    <div v-else-if="topics.length" class="topic-grid">
      <a
        v-for="topic in topics"
        :key="topic.topic_id"
        class="topic-card"
        :href="topicLink(topic.topic_id)"
      >
        <h2>{{ topic.title }}</h2>
        <p>
          {{
            problemCount(topic.topic_id)
              ? `${problemCount(topic.topic_id)} problems indexed`
              : "Theory only — no practice list yet"
          }}
        </p>
        <p v-if="topic.code" class="muted">{{ topic.code.name }}</p>
      </a>
    </div>
  </div>
</template>
