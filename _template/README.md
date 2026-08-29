# Topic Template

Reference layout for every algorithm / paradigm topic in this repo. Copy `topic/` into the right path and replace placeholders.

## Folder layout

```
<category>/<topic>/
├── README.md              # theory (kind: theory)
├── <topic>.h              # implementation (optional)
└── practice/
    ├── 0. patterns.md     # by-pattern index (kind: patterns)
    ├── 1. beginner.md     # by-difficulty (kind: practice, tier: beginner)
    ├── 2. intermediate.md
    └── 3. advanced.md
```

Create only the `practice/` files you need. Numeric prefix controls order.

## Files in this folder

| File | Purpose |
| --- | --- |
| [CONVENTIONS.md](CONVENTIONS.md) | Rules for authors and the future site builder |
| [topic/README.md](topic/README.md) | Theory template |
| [topic/topic.h](topic/topic.h) | Code stub |
| [topic/practice/0. patterns.md](topic/practice/0.%20patterns.md) | Patterns template |
| [topic/practice/1. beginner.md](topic/practice/1.%20beginner.md) | Beginner tier template |
| [topic/practice/2. intermediate.md](topic/practice/2.%20intermediate.md) | Intermediate tier template |
| [topic/practice/3. advanced.md](topic/practice/3.%20advanced.md) | Advanced tier template |

## Quick start

1. Copy `_template/topic/` → e.g. `algorithms/search/binary/`
2. Rename `topic.h` → `binary.h`
3. Fill frontmatter (`title`, `topic_id`) - keep `topic_id` stable for progress tracking
4. Add problems using `[Title](https://leetcode.com/problems/slug/)` links only in `practice/`

See [CONVENTIONS.md](CONVENTIONS.md) for how problems map to **global / by-topic / by-pattern / by-difficulty** views.
