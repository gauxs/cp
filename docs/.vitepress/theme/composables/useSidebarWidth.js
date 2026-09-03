import { onMounted, onUnmounted, nextTick } from "vue";

const DESKTOP_MQ = "(min-width: 960px)";

/**
 * VitePress sizes the main column from --vp-sidebar-width. Measure once using
 * the widest label at any depth (including collapsed branches) so expanding
 * sections does not change sidebar width.
 */
export function useSidebarWidthSync() {
  let resizeObserver = null;
  let mediaQuery = null;
  let raf = 0;
  let measuring = false;

  function measureContentWidth(sidebar) {
    measuring = true;
    sidebar.style.setProperty("width", "max-content", "important");
    sidebar.style.setProperty("max-width", "none", "important");

    const hiddenItems = sidebar.querySelectorAll(
      ".VPSidebarItem.collapsed > .items",
    );
    for (const el of hiddenItems) {
      el.style.setProperty("display", "block", "important");
    }

    const nav = sidebar.querySelector("#VPSidebarNav");
    let content = 0;
    if (nav) {
      for (const el of nav.querySelectorAll(".item")) {
        content = Math.max(content, el.scrollWidth);
      }
      content = Math.max(content, nav.scrollWidth);
    }

    for (const el of hiddenItems) {
      el.style.removeProperty("display");
    }

    const styles = getComputedStyle(sidebar);
    const pad =
      (parseFloat(styles.paddingLeft) || 0) +
      (parseFloat(styles.paddingRight) || 0);

    const width = Math.ceil(Math.max(content + pad, sidebar.scrollWidth));

    sidebar.style.removeProperty("width");
    sidebar.style.removeProperty("max-width");
    measuring = false;
    return width;
  }

  function sync() {
    if (typeof document === "undefined" || measuring) return;

    const root = document.documentElement;
    if (!window.matchMedia(DESKTOP_MQ).matches) {
      root.style.removeProperty("--vp-sidebar-width");
      return;
    }

    const sidebar = document.querySelector(".VPSidebar");
    if (!sidebar) return;

    const vw = window.innerWidth;
    const minPx = Math.round(vw * 0.12);
    const measured = measureContentWidth(sidebar);
    const width = Math.max(minPx, measured);
    root.style.setProperty("--vp-sidebar-width", `${width}px`);
  }

  function scheduleSync() {
    if (measuring) return;
    cancelAnimationFrame(raf);
    raf = requestAnimationFrame(sync);
  }

  function attach() {
    const sidebar = document.querySelector(".VPSidebar");
    if (!sidebar) return;

    resizeObserver?.disconnect();
    resizeObserver = new ResizeObserver(() => {
      if (!measuring) scheduleSync();
    });
    const nav = sidebar.querySelector("#VPSidebarNav") ?? sidebar;
    resizeObserver.observe(nav);

    scheduleSync();
  }

  function onMediaChange() {
    nextTick(attach);
  }

  onMounted(() => {
    mediaQuery = window.matchMedia(DESKTOP_MQ);
    mediaQuery.addEventListener("change", onMediaChange);
    window.addEventListener("resize", scheduleSync);
    nextTick(attach);
  });

  onUnmounted(() => {
    cancelAnimationFrame(raf);
    resizeObserver?.disconnect();
    mediaQuery?.removeEventListener("change", onMediaChange);
    window.removeEventListener("resize", scheduleSync);
  });

  return { sync: scheduleSync };
}
