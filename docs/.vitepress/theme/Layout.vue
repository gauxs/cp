<script setup>
import { useData } from "vitepress";
import DefaultLayout from "vitepress/dist/client/theme-default/Layout.vue";
import ProblemDashboard from "./components/ProblemDashboard.vue";
import CategoryView from "./components/CategoryView.vue";
import TopicView from "./components/TopicView.vue";

const { frontmatter } = useData();
</script>

<template>
  <DefaultLayout>
    <template v-if="frontmatter.cpLayout === 'home'" #doc-before>
      <div class="page-shell">
        <ProblemDashboard />
      </div>
    </template>

    <template v-else-if="frontmatter.cpLayout === 'category'" #doc-before>
      <CategoryView />
    </template>

    <template v-else-if="frontmatter.cpLayout === 'topic'" #doc-before>
      <TopicView />
    </template>
  </DefaultLayout>
</template>
