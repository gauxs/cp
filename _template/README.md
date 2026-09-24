# Topic Template

Reference layout for every algorithm / paradigm topic in this repo. Copy `topic/` into the right path and replace placeholders.

## Folder layout

```
<category>/<topic>/
├── README.md              # theory (kind: theory)
├── <topic>.h              # manual implementation (optional) → Code tab
├── library.md             # STL / library usage (optional) → Library tab
└── practice/
    ├── 0. patterns.md     # by-pattern index (kind: patterns)
    └── 1. practice.md     # by-difficulty tiers (kind: practice)
```

Create only the optional files you need. The site shows a tab only when that content exists (e.g. algorithms usually omit `library.md`; data structures often include it).

## Files in this folder

| File | Purpose |
| --- | --- |
| [CONVENTIONS.md](CONVENTIONS.md) | Rules for authors and the site builder |
| [topic/README.md](topic/README.md) | Theory template |
| [topic/topic.h](topic/topic.h) | Manual code stub |
| [topic/library.md](topic/library.md) | Library / STL usage template (optional) |
| [topic/practice/0. patterns.md](topic/practice/0.%20patterns.md) | Patterns template |
| [topic/practice/1. practice.md](topic/practice/1.%20practice.md) | Practice tiers template |

## Quick start

1. Copy `_template/topic/` → e.g. `data_structures/heap/` or `algorithms/search/binary/`
2. Rename `topic.h` → matching name (e.g. `priority_queue.h`); delete `library.md` if unused
3. Fill frontmatter (`title`, `topic_id`) - keep `topic_id` stable for progress tracking
4. Add problems using `[Title](https://leetcode.com/problems/slug/)` links only in `practice/`

See [CONVENTIONS.md](CONVENTIONS.md) for how problems map to **global / by-topic / by-pattern / by-difficulty** views.
