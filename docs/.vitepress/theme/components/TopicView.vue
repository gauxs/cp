<script setup>
import { computed, onMounted, onUnmounted, ref, watch } from "vue";
import { useData, withBase, inBrowser } from "vitepress";
import MarkdownContent from "./MarkdownContent.vue";
import PatternPanel from "./PatternPanel.vue";
import PracticePanel from "./PracticePanel.vue";
import CodePanel from "./CodePanel.vue";
import TopicStepNav from "./TopicStepNav.vue";
import TopicBreadcrumb from "./TopicBreadcrumb.vue";
import { topicDataSlug } from "../utils/routes.js";

const { frontmatter } = useData();
const topic = ref(null);
const site = ref(null);
const activeTab = ref("theory");
const loading = ref(true);
const error = ref("");

function readQuerySection() {
  if (!inBrowser) return null;
  return new URLSearchParams(window.location.search).get("section");
}

function writeQuerySection(section) {
  if (!inBrowser) return;

  const url = new URL(window.location.href);
  if (!section || section === "theory") {
    url.searchParams.delete("section");
  } else {
    url.searchParams.set("section", section);
  }

  const next = `${url.pathname}${url.search}${url.hash}`;
  history.replaceState(history.state, "", next);
}

function resolveSection(section, tabIds) {
  if (section && tabIds.includes(section)) return section;
  return "theory";
}

function syncSectionFromUrl() {
  if (!topic.value) return;
  activeTab.value = resolveSection(readQuerySection(), tabIds.value);
}

function onPopState() {
  syncSectionFromUrl();
}

onMounted(async () => {
  window.addEventListener("popstate", onPopState);

  try {
    const slug = topicDataSlug(frontmatter.value.topic_id);
    const [topicRes, siteRes] = await Promise.all([
      fetch(withBase(`/data/topics/${slug}.json`)),
      fetch(withBase("/data/site.json")),
    ]);
    if (!topicRes.ok) throw new Error(`topic data (${topicRes.status})`);
    topic.value = await topicRes.json();
    if (siteRes.ok) site.value = await siteRes.json();
    syncSectionFromUrl();
  } catch (err) {
    error.value = err.message ?? "Failed to load topic";
  } finally {
    loading.value = false;
  }
});

onUnmounted(() => {
  if (inBrowser) window.removeEventListener("popstate", onPopState);
});

const tabs = computed(() => {
  if (!topic.value) return [{ id: "theory", label: "Theory" }];

  const items = [{ id: "theory", label: "Theory" }];
  if (topic.value.code) items.push({ id: "code", label: "Code" });
  if (topic.value.library) items.push({ id: "library", label: "Library" });
  if (topic.value.practice.some((f) => f.kind === "patterns")) {
    items.push({ id: "patterns", label: "Patterns" });
  }
  if (topic.value.practice.some((f) => f.kind === "practice")) {
    items.push({ id: "practice", label: "Practice" });
  }
  return items;
});

const tabIds = computed(() => tabs.value.map((tab) => tab.id));

watch([topic, tabIds], syncSectionFromUrl, { immediate: true });

function setActiveSection(section) {
  const next = resolveSection(section, tabIds.value);
  activeTab.value = next;
  writeQuerySection(next);
}

const activeTabMeta = computed(() =>
  tabs.value.find((tab) => tab.id === activeTab.value),
);

const patternsFile = computed(() =>
  topic.value?.practice.find((f) => f.kind === "patterns"),
);

const tierFiles = computed(() =>
  topic.value?.practice.filter((f) => f.kind === "practice") ?? [],
);
</script>

<template>
  <div class="page-shell topic-page">
    <p v-if="loading" class="status-msg">Loading…</p>
    <p v-else-if="error" class="status-msg error">{{ error }}</p>

    <template v-else-if="topic">
      <header class="page-header">
        <TopicBreadcrumb
          v-if="site"
          :topic-id="topic.topic_id"
          :title="topic.title"
          :categories="site.categories"
        />
        <h1>
          {{ topic.title
          }}<template v-if="activeTabMeta">
            <span class="topic-title-sep"> - </span
            ><span class="topic-title-section">{{ activeTabMeta.label }}</span>
          </template>
        </h1>
      </header>

      <TopicStepNav
        class="topic-stepper-top"
        :active-tab="activeTab"
        :tabs="tabs"
        show-track
        @update:active-tab="setActiveSection"
      />

      <section v-if="activeTab === 'theory'" class="content-panel">
        <MarkdownContent :source="topic.theory.content" strip-leading-h1 />
      </section>

      <section v-else-if="activeTab === 'code' && topic.code" class="content-panel">
        <CodePanel
          :filename="topic.code.name"
          :content="topic.code.content"
          language="cpp"
        />
      </section>

      <section
        v-else-if="activeTab === 'library' && topic.library"
        class="content-panel"
      >
        <MarkdownContent :source="topic.library.content" strip-leading-h1 />
      </section>

      <section
        v-else-if="activeTab === 'patterns' && patternsFile"
        class="content-panel"
      >
        <PatternPanel :markdown="patternsFile.content" />
      </section>

      <section v-else-if="activeTab === 'practice'" class="content-panel">
        <PracticePanel :tiers="tierFiles" />
      </section>

      <TopicStepNav
        class="topic-stepper-bottom"
        :active-tab="activeTab"
        :tabs="tabs"
        show-footer
        @update:active-tab="setActiveSection"
      />
    </template>
  </div>
</template>
