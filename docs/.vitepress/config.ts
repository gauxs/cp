import fs from "node:fs";
import path from "node:path";
import { fileURLToPath } from "node:url";
import { defineConfig } from "vitepress";

const __dirname = path.dirname(fileURLToPath(import.meta.url));
const sidebarPath = path.join(__dirname, "sidebar.json");
const BASE = "/cp";

const LEGACY_REDIRECTS = [
  { from: "/algorithms-search", to: "/algorithms/search" },
  { from: "/algorithms-search/", to: "/algorithms/search" },
  { from: "/algorithms-search/binary", to: "/algorithms/search/binary" },
  { from: "/algorithms-search/jump", to: "/algorithms/search/jump" },
  { from: "/algorithms-search/quick_select", to: "/algorithms/search/quick_select" },
  { from: "/algorithms-search/exponential", to: "/algorithms/search/exponential" },
];

function loadSidebar() {
  if (!fs.existsSync(sidebarPath)) {
    return [{ text: "Dashboard", link: "/" }];
  }
  return JSON.parse(fs.readFileSync(sidebarPath, "utf8"));
}

function redirectTarget(fromPath) {
  const normalized = fromPath.replace(/\/+$/, "") || "/";
  const withBase = normalized.startsWith(BASE)
    ? normalized.slice(BASE.length) || "/"
    : normalized;

  for (const rule of LEGACY_REDIRECTS) {
    const legacy = rule.from.replace(/\/+$/, "");
    if (withBase === legacy || withBase === `${legacy}/`) {
      return `${BASE}${rule.to}`;
    }
  }

  if (withBase.startsWith("/algorithms-search/")) {
    return `${BASE}${withBase.replace("/algorithms-search", "/algorithms/search")}`;
  }

  return null;
}

function redirectHtml(target) {
  return `<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="refresh" content="0;url=${target}">
    <link rel="canonical" href="${target}">
    <script>location.replace("${target}")</script>
    <title>Redirecting…</title>
  </head>
  <body>
    <p>Redirecting to <a href="${target}">${target}</a></p>
  </body>
</html>
`;
}

function legacyRedirectPlugin() {
  return {
    name: "cp-legacy-redirects",
    configureServer(server) {
      server.middlewares.use((req, res, next) => {
        const target = redirectTarget(req.url?.split("?")[0] ?? "");
        if (!target) {
          next();
          return;
        }
        res.statusCode = 302;
        res.setHeader("Location", target);
        res.end();
      });
    },
    closeBundle() {
      const distDir = path.join(__dirname, "dist");
      const mappings = [
        ["algorithms-search/index.html", "/algorithms/search"],
        ["algorithms-search.html", "/algorithms/search"],
        ["algorithms-search/binary.html", "/algorithms/search/binary"],
        ["algorithms-search/jump.html", "/algorithms/search/jump"],
        ["algorithms-search/quick_select.html", "/algorithms/search/quick_select"],
        ["algorithms-search/exponential.html", "/algorithms/search/exponential"],
      ];

      for (const [file, to] of mappings) {
        const filePath = path.join(distDir, file);
        fs.mkdirSync(path.dirname(filePath), { recursive: true });
        fs.writeFileSync(filePath, redirectHtml(`${BASE}${to}`));
      }
    },
  };
}

export default defineConfig({
  title: "CP Notes",
  description: "Competitive programming notes and practice tracker",
  base: `${BASE}/`,
  cleanUrls: true,
  vite: {
    plugins: [legacyRedirectPlugin()],
  },
  themeConfig: {
    nav: [{ text: "Dashboard", link: "/" }],
    sidebar: loadSidebar(),
  },
});
