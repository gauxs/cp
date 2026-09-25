<script setup>
import { computed, nextTick, watch } from "vue";
import { useData, useRoute } from "vitepress";
import DefaultLayout from "vitepress/dist/client/theme-default/Layout.vue";
import ProblemDashboard from "./components/ProblemDashboard.vue";
import CategoryView from "./components/CategoryView.vue";
import TopicView from "./components/TopicView.vue";
import { provideSiteLanguage } from "./composables/useSiteLanguage.js";
import { useSidebarWidthSync } from "./composables/useSidebarWidth.js";

provideSiteLanguage();

const { frontmatter, page } = useData();
const route = useRoute();
const pageKey = computed(() => page.value.relativePath);

const isDashboard = computed(
  () =>
    frontmatter.value.cpLayout === "home" ||
    page.value.relativePath === "index.md",
);
const { sync: syncSidebarWidth } = useSidebarWidthSync();

watch(
  () => route.path,
  () => nextTick(() => syncSidebarWidth()),
);
</script>

<template>
  <DefaultLayout>
    <template v-if="isDashboard" #doc-before>
      <div class="page-shell">
        <ProblemDashboard :key="pageKey" />
      </div>
    </template>

    <template v-else-if="frontmatter.cpLayout === 'category'" #doc-before>
      <CategoryView :key="pageKey" />
    </template>

    <template v-else-if="frontmatter.cpLayout === 'topic'" #doc-before>
      <TopicView :key="pageKey" />
    </template>
  </DefaultLayout>
</template>
