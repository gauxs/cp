<script setup>
import { computed, onMounted, ref } from "vue";
import { useData, withBase } from "vitepress";
import MarkdownContent from "./MarkdownContent.vue";
import ProblemList from "./ProblemList.vue";

const { frontmatter } = useData();
const topic = ref(null);
const activeTab = ref("theory");
const loading = ref(true);
const error = ref("");

onMounted(async () => {
  try {
    const slug = frontmatter.value.topic_id.replace(/\//g, "-");
    const res = await fetch(withBase(`/data/topics/${slug}.json`));
    if (!res.ok) throw new Error(`topic data (${res.status})`);
    topic.value = await res.json();
  } catch (err) {
    error.value = err.message ?? "Failed to load topic";
  } finally {
    loading.value = false;
  }
});

const tabs = computed(() => {
  if (!topic.value) return [{ id: "theory", label: "Theory" }];
  const items = [{ id: "theory", label: "Theory" }];
  if (topic.value.code) items.push({ id: "code", label: "Code" });
  for (const file of topic.value.practice) {
    if (file.kind === "patterns") {
      items.push({ id: "patterns", label: "Patterns" });
    } else if (file.tier) {
      items.push({ id: file.tier, label: titleCase(file.tier) });
    }
  }
  return items;
});

const activePractice = computed(() => {
  if (!topic.value) return null;
  if (activeTab.value === "patterns") {
    return topic.value.practice.find((f) => f.kind === "patterns");
  }
  return topic.value.practice.find((f) => f.tier === activeTab.value);
});

function titleCase(value) {
  return value.charAt(0).toUpperCase() + value.slice(1);
}
</script>

<template>
  <div class="page-shell topic-page">
    <p v-if="loading" class="status-msg">Loading…</p>
    <p v-else-if="error" class="status-msg error">{{ error }}</p>

    <template v-else-if="topic">
      <header class="page-header">
        <p class="eyebrow">{{ topic.topic_id }}</p>
        <h1>{{ topic.title }}</h1>
      </header>

      <nav class="tab-bar">
        <button
          v-for="tab in tabs"
          :key="tab.id"
          class="tab-btn"
          :class="{ active: activeTab === tab.id }"
          @click="activeTab = tab.id"
        >
          {{ tab.label }}
        </button>
      </nav>

      <section v-if="activeTab === 'theory'" class="content-panel">
        <MarkdownContent :source="topic.theory.content" />
      </section>

      <section v-else-if="activeTab === 'code'" class="content-panel">
        <p class="file-label">{{ topic.code.name }}</p>
        <pre><code>{{ topic.code.content }}</code></pre>
      </section>

      <section v-else-if="activePractice" class="content-panel">
        <MarkdownContent :source="activePractice.content" />
        <ProblemList :markdown="activePractice.content" />
      </section>
    </template>
  </div>
</template>
