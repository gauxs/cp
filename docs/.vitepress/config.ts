import fs from "node:fs";
import path from "node:path";
import { fileURLToPath } from "node:url";
import { defineConfig } from "vitepress";

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const sidebarPath = path.join(__dirname, "sidebar.json");

function loadSidebar() {
  if (!fs.existsSync(sidebarPath)) {
    return [{ text: "Dashboard", link: "/" }];
  }
  return JSON.parse(fs.readFileSync(sidebarPath, "utf8"));
}

export default defineConfig({
  title: "CP Notes",
  description: "Competitive programming notes and practice tracker",
  base: "/cp/",
  cleanUrls: true,
  themeConfig: {
    nav: [{ text: "Dashboard", link: "/" }],
    sidebar: loadSidebar(),
  },
});
