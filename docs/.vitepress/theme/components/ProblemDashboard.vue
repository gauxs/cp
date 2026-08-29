<script setup>
import { computed, onMounted, ref } from "vue";
import { withBase } from "vitepress";
import { useProgress } from "../composables/useProgress.js";
import { primaryTier } from "../utils/tiers.js";
import LeetCodeProblemRow from "./LeetCodeProblemRow.vue";
import ProgressHero from "./ProgressHero.vue";

const site = ref(null);
const activeView = ref("global");
const showTopics = ref(false);
const loading = ref(true);
const error = ref("");
const { isDone, toggle, doneCount, load, progress } = useProgress();

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
  { id: "byDifficulty", label: "By difficulty" },
];

const showTopicBadge = computed(
  () => showTopics.value && activeView.value !== "byTopic",
);
const showDifficultyBadge = computed(() => activeView.value !== "byDifficulty");

const groups = computed(() => {
  if (!site.value) return [];
  const view = site.value.views[activeView.value] ?? {};
  return Object.entries(view)
    .map(([name, slugs]) => ({
      name: formatGroupName(name, activeView.value),
      key: name,
      slugs: [...new Set(slugs)],
    }))
    .filter((group) => group.slugs.length > 0)
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

function rowProps(problem) {
  return {
    slug: problem.slug,
    title: problem.title,
    url: problem.url,
    done: isDone(problem.slug),
    topicTitle: problem.topic_title,
    difficulty: primaryTier(problem.difficulties),
    showTopic: showTopicBadge.value,
    showDifficulty: showDifficultyBadge.value,
  };
}
</script>

<template>
  <div class="dashboard">
    <p v-if="loading" class="status-msg">Loading…</p>
    <p v-else-if="error" class="status-msg error">{{ error }}</p>

    <template v-else-if="site">
      <ProgressHero
        :problems="site.problems"
        :done-count="doneCount"
        :progress="progress"
      />

      <div class="dashboard-toolbar">
        <nav class="tab-bar dashboard-tabs" aria-label="Problem views">
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

        <button
          type="button"
          class="visibility-toggle"
          :class="{ active: showTopics }"
          :aria-pressed="showTopics"
          aria-label="Toggle topic labels on problem rows"
          @click="showTopics = !showTopics"
        >
          <svg
            v-if="showTopics"
            class="visibility-toggle-icon"
            viewBox="0 0 24 24"
            aria-hidden="true"
          >
            <path
              d="M12 5C7 5 2.73 8.11 1 12c1.73 3.89 6 7 11 7s9.27-3.11 11-7c-1.73-3.89-6-7-11-7zm0 11a4 4 0 1 1 0-8 4 4 0 0 1 0 8z"
              fill="currentColor"
            />
          </svg>
          <svg
            v-else
            class="visibility-toggle-icon"
            viewBox="0 0 24 24"
            aria-hidden="true"
          >
            <path
              d="M12 6.5c3.79 0 7.17 2.13 8.82 5.5-1.65 3.37-5.03 5.5-8.82 5.5S4.83 15.37 3.18 12C4.83 8.63 8.21 6.5 12 6.5m0-2C7 4.5 2.73 7.61 1 12c1.73 4.39 6 7.5 11 7.5s9.27-3.11 11-7.5C21.27 7.61 17 4.5 12 4.5zM12 9a3 3 0 1 0 0 6 3 3 0 0 0 0-6z"
              fill="currentColor"
              opacity="0.45"
            />
            <path
              d="M3.27 3.27 20.73 20.73 19.27 22.27 1.73 4.73z"
              fill="currentColor"
            />
          </svg>
          <span>Topics</span>
        </button>
      </div>

      <section v-if="activeView === 'global'" class="content-panel dashboard-list">
        <div class="lc-problem-list">
          <LeetCodeProblemRow
            v-for="problem in site.problems"
            :key="problem.slug"
            v-bind="rowProps(problem)"
            @toggle="toggle(problem.slug)"
          />
        </div>
      </section>

      <section v-else class="group-stack dashboard-list">
        <details v-for="group in groups" :key="group.key" class="group-card">
          <summary class="group-header">
            <h2>{{ group.name }}</h2>
            <span class="group-count"
              >{{ doneCount(group.slugs) }} / {{ group.slugs.length }}</span
            >
            <span class="lc-chevron" aria-hidden="true" />
          </summary>
          <div class="group-body">
            <div class="lc-problem-list">
              <LeetCodeProblemRow
                v-for="slug in group.slugs"
                :key="`${group.key}-${slug}`"
                v-bind="rowProps(problemBySlug[slug])"
                @toggle="toggle(slug)"
              />
            </div>
          </div>
        </details>
      </section>
    </template>
  </div>
</template>
