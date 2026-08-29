<script setup>
import { computed, onMounted, ref } from "vue";
import { withBase } from "vitepress";
import { useProgress } from "../composables/useProgress.js";

const site = ref(null);
const activeView = ref("global");
const loading = ref(true);
const error = ref("");
const { isDone, toggle, doneCount, load } = useProgress();

onMounted(async () => {
  load();
  try {
    const res = await fetch(withBase("/data/site.json"));
    if (!res.ok) throw new Error(`site.json (${res.status})`);
    site.value = await res.json();
    activeView.value = site.value.config.default_view;
  } catch (err) {
    error.value = err.message ?? "Failed to load problems";
  } finally {
    loading.value = false;
  }
});

const problemBySlug = computed(() => {
  if (!site.value) return {};
  return Object.fromEntries(site.value.problems.map((p) => [p.slug, p]));
});

const tabs = [
  { id: "global", label: "All" },
  { id: "byTopic", label: "By topic" },
  { id: "byPattern", label: "By pattern" },
  { id: "byDifficulty", label: "By difficulty" },
];

const stats = computed(() => {
  if (!site.value) return { done: 0, total: 0 };
  const slugs = site.value.problems.map((p) => p.slug);
  return { done: doneCount(slugs), total: slugs.length };
});

const groups = computed(() => {
  if (!site.value) return [];
  const view = site.value.views[activeView.value] ?? {};
  return Object.entries(view)
    .map(([name, slugs]) => ({
      name: formatGroupName(name, activeView.value),
      slugs: [...new Set(slugs)],
    }))
    .sort((a, b) => a.name.localeCompare(b.name));
});

function formatGroupName(name, view) {
  if (view === "byTopic" && site.value) {
    const sample = problemBySlug.value[site.value.views.byTopic[name]?.[0]];
    return sample?.topic_title ?? name;
  }
  if (view === "byDifficulty") {
    return name.charAt(0).toUpperCase() + name.slice(1);
  }
  return name;
}
</script>

<template>
  <div class="dashboard">
    <p v-if="loading" class="status-msg">Loading…</p>
    <p v-else-if="error" class="status-msg error">{{ error }}</p>

    <template v-else-if="site">
    <header class="page-header">
      <p class="eyebrow">Practice tracker</p>
      <h1>Problems</h1>
      <p class="stats">{{ stats.done }} / {{ stats.total }} completed</p>
    </header>

    <nav class="tab-bar">
      <button
        v-for="tab in tabs"
        :key="tab.id"
        class="tab-btn"
        :class="{ active: activeView === tab.id }"
        @click="activeView = tab.id"
      >
        {{ tab.label }}
      </button>
    </nav>

    <section v-if="activeView === 'global'" class="content-panel">
      <div class="problem-checklist">
        <label
          v-for="problem in site.problems"
          :key="problem.slug"
          class="problem-row"
        >
          <input
            type="checkbox"
            :checked="isDone(problem.slug)"
            @change="toggle(problem.slug)"
          />
          <span class="problem-meta">
            <a :href="problem.url" target="_blank" rel="noopener">{{
              problem.title
            }}</a>
            <small>{{ problem.topic_title }}</small>
          </span>
        </label>
      </div>
    </section>

    <section v-else class="group-stack">
      <div v-for="group in groups" :key="group.name" class="group-card">
        <div class="group-header">
          <h2>{{ group.name }}</h2>
          <span>{{ doneCount(group.slugs) }} / {{ group.slugs.length }}</span>
        </div>
        <div class="problem-checklist">
          <label
            v-for="slug in group.slugs"
            :key="`${group.name}-${slug}`"
            class="problem-row"
          >
            <input
              type="checkbox"
              :checked="isDone(slug)"
              @change="toggle(slug)"
            />
            <span class="problem-meta">
              <a
                :href="problemBySlug[slug]?.url"
                target="_blank"
                rel="noopener"
              >
                {{ problemBySlug[slug]?.title ?? slug }}
              </a>
              <small v-if="activeView === 'byPattern'">
                {{ problemBySlug[slug]?.topic_title }}
              </small>
            </span>
          </label>
        </div>
      </div>
    </section>
    </template>
  </div>
</template>
