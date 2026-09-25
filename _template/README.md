# Authoring guide

How to run the site, add topics, and wire new sections into the build. For markdown rules (headings, patterns, tiers), see [CONVENTIONS.md](CONVENTIONS.md).

## How the site is built

Content lives at the **repo root** (`algorithms/`, `patterns/`, `data_structures/`). The `docs/` tree is mostly **generated** (stub pages, sidebar, JSON bundles).

```text
Your markdown + code  →  npm run build:index  →  docs/public/data/*.json + docs/**/*.md stubs
                                                      ↓
                                              vitepress build docs  →  static site
```

| Command | What it does |
| --- | --- |
| `npm install` | Install Node dependencies (once). |
| `npm run docs:dev` | Rebuild index, then local dev server (default VitePress port). |
| `npm run build:index` | Only run `scripts/build-index.mjs` (JSON + sidebar + stub pages). |
| `npm run docs:build` | Index + production build (`docs/.vitepress/dist`). |
| `npm run docs:preview` | Serve the production build locally. |

Pushes to `main` / `master` deploy via [`.github/workflows/pages.yml`](../.github/workflows/pages.yml) when GitHub Pages source is **GitHub Actions**. Site URL uses base path `/cp/` (project Pages).

**Do not hand-edit** generated artifacts under `docs/public/data/`, `docs/.vitepress/sidebar.json`, or stub topic pages unless you are debugging the generator—they are overwritten on the next `build:index`.

---

## Topic folder layout

Copy [`topic/`](topic/) into the right tree and rename placeholders.

```text
<category>/<topic>/
├── README.md                 # Theory tab (kind: theory)
├── <name>.h                  # optional → Code tab (first *.h in folder)
├── library.md                # optional legacy C++ library tab
├── library/cpp.md            # optional → Library tab (cpp / java / go)
└── practice/
    ├── 0. patterns.md        # optional → Patterns tab (kind: patterns)
    └── 1. practice.md        # optional → Practice tab (kind: practice)
```

Create only what you need. The UI shows **Theory → Code → Library → Patterns → Practice** tabs when that content exists.

| Template file | Purpose |
| --- | --- |
| [CONVENTIONS.md](CONVENTIONS.md) | Authoring rules and dashboard indexing |
| [topic/README.md](topic/README.md) | Theory template |
| [topic/topic.h](topic/topic.h) | Code stub |
| [topic/library.md](topic/library.md) | Library stub (optional) |
| [topic/practice/0. patterns.md](topic/practice/0.%20patterns.md) | Patterns list |
| [topic/practice/1. practice.md](topic/practice/1.%20practice.md) | Difficulty tiers |

**Where to put a topic:** `algorithms/` (named algorithm), `data_structures/` (ADT/structure), or `patterns/` (recognition family). Placement rules are in [CONVENTIONS.md § Topic roots](CONVENTIONS.md#topic-roots-mutually-exclusive).

---

## Add a topic (existing section)

Example: new sort under `algorithms/sort/comparison/`.

1. **Copy** `_template/topic/` → `algorithms/sort/comparison/foo/`.
2. **Rename** `topic.h` → e.g. `foo.h` (or delete if no code).
3. **Set frontmatter** on every file. `topic_id` must match the folder path and stay stable (progress is keyed by LeetCode slug + topic):

   ```yaml
   topic_id: algorithms/sort/comparison/foo
   ```

4. **Theory:** `README.md` with `kind: theory` (required for the topic page to exist).
5. **Practice:** LeetCode links only under `practice/`:

   ```markdown
   1. [Problem Title](https://leetcode.com/problems/problem-slug/)
   ```

6. **Run** `npm run docs:dev` and open the topic from the sidebar.

### What the indexer picks up automatically

| Source | Picked up when |
| --- | --- |
| Theory | `README.md` exists with `kind: theory` at `topic_id` path |
| Code | Any `*.h` in the topic folder (first sorted file is used) |
| Library | `library.md` or `library/*.md` with `kind: library` |
| Practice files | Files under `practice/` for that topic (embedded in topic JSON) |
| Dashboard problems | Practice file path matches a glob in `site.config.yaml` → `include` **and** frontmatter has `topic_id` + `kind: patterns` or `kind: practice` |

If the topic page works but problems are missing from the **home dashboard**, your `practice/` path is probably not covered by `include` yet (see below).

### Optional polish in `site.config.yaml`

Under `topics:` add a display label (and ordering) for sidebar/titles:

```yaml
topics:
  algorithms/sort/comparison/foo:
    label: Foo Sort
```

If the parent section already exists in `categories:` (e.g. `algorithms/sort/comparison`), the new leaf usually appears in the nav without more config.

---

## Add a new section (sidebar group or tree)

Use this when you introduce a **new branch** of the tree (e.g. `algorithms/tricks/…`) or a new top-level area.

### 1. Register navigation — `categories:`

Each sidebar group/section needs a `topic_id` and `label`. Nested items set `parent:` to the parent `topic_id`.

```yaml
categories:
  - topic_id: algorithms/tricks
    label: Tricks
    parent: algorithms
```

- **Folder with only child topics:** parent category often has no `README.md`; the build still emits a category overview page when this entry exists.
- **Leaf section** (single topic at that path, e.g. `patterns/divide_and_conquer`): list it under `topics:` and hang it under the right parent in `categories:` like existing leaves.

### 2. Index practice for the dashboard — `include:`

The home dashboard only scans paths listed here. Add a glob that matches your new `practice/` files:

```yaml
include:
  - "algorithms/tricks/**/practice/*.md"
```

Without this, theory/code/library still build, but **Global / by-pattern / by-difficulty views** will not see those problems.

### 3. Labels — `topics:`

Add one entry per **leaf** topic (path → human title), same as existing entries in `site.config.yaml`.

### 4. Category index (optional)

For a group that lists children in prose, add `algorithms/tricks/README.md` with `kind: category` and `topic_id: algorithms/tricks` (see `algorithms/search/README.md`).

### 5. Verify

```bash
npm run build:index
```

Check the log (`N` problems, `M` topics), then `npm run docs:dev`. Confirm sidebar, category page, topic tabs, and dashboard filters.

---

## Checklist for a new leaf topic

- [ ] Folder path equals `topic_id` in all frontmatter
- [ ] `README.md` has `kind: theory`
- [ ] Practice files have `kind: patterns` / `kind: practice` and LeetCode links only in `practice/`
- [ ] `site.config.yaml`: `include` glob covers `…/practice/*.md` (if you use practice)
- [ ] `site.config.yaml`: `topics:` label (recommended)
- [ ] `site.config.yaml`: `categories:` parent chain (if sidebar should show the section)
- [ ] `npm run docs:dev` — topic loads, dashboard counts look right

---

## Reference

- [CONVENTIONS.md](CONVENTIONS.md) — frontmatter, pattern headings, difficulty tiers, library layout
- [`site.config.yaml`](../site.config.yaml) — `include`, `categories`, `topics`, site title
- [`scripts/build-index.mjs`](../scripts/build-index.mjs) — indexer implementation
