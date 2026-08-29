import { ref, onMounted } from "vue";

const STORAGE_KEY = "cp-progress";

export function useProgress() {
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

  onMounted(load);

  return { progress, isDone, toggle, doneCount, load };
}
