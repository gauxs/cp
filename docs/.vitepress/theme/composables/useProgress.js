import { ref } from "vue";

const STORAGE_KEY = "cp-progress";
const progress = ref({});

function load() {
  try {
    progress.value = JSON.parse(localStorage.getItem(STORAGE_KEY) || "{}");
  } catch {
    progress.value = {};
  }
}

function save() {
  localStorage.setItem(STORAGE_KEY, JSON.stringify(progress.value));
}

export function useProgress() {
  function isDone(slug) {
    return Boolean(progress.value[slug]?.done);
  }

  function toggle(slug) {
    if (isDone(slug)) {
      delete progress.value[slug];
    } else {
      progress.value[slug] = { done: true, doneAt: new Date().toISOString() };
    }
    save();
  }

  function doneCount(slugs) {
    return slugs.filter((slug) => isDone(slug)).length;
  }

  if (typeof window !== "undefined" && !Object.keys(progress.value).length) {
    load();
  }

  return { progress, isDone, toggle, doneCount, load };
}
