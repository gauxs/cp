<script setup>
import { useSiteLanguage } from "../composables/useSiteLanguage.js";

const { language, languages } = useSiteLanguage();
</script>

<template>
  <div class="lc-nav-lang-wrap">
    <label class="lc-nav-lang-label" for="cp-site-language">Language</label>
    <select
      id="cp-site-language"
      v-model="language"
      class="lc-code-lang-select lc-nav-lang-select"
      aria-label="Programming language"
    >
      <option v-for="lang in languages" :key="lang.id" :value="lang.id">
        {{ lang.label }}
      </option>
    </select>
  </div>
</template>
