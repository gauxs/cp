# Content Conventions

Rules for markdown in this repo and for the future static site.

## Frontmatter (required)

Every content file starts with YAML frontmatter:

```yaml
---
kind: theory | library | patterns | practice | category
title: Human-readable title
topic_id: category/path/topic    # stable id, e.g. algorithms/search/binary
---
```

Category index files (e.g. `algorithms/search/README.md`) use `kind: category` and `topic_id: algorithms/search`. They list child topics; they do not contain practice problems.

Practice tier files use section headings inside a single file (see Difficulty tiers below). Legacy per-tier files with `tier:` in frontmatter are still supported.

## Problem links (required format)

Use markdown links to LeetCode only in `practice/` files:

```markdown
1. [Problem Title](https://leetcode.com/problems/problem-slug/)
```

The site uses `problem-slug` as the canonical id. One checkbox state per slug everywhere.

Problems may appear in **both** a pattern section and a difficulty tier within the **same** topic - that is intentional (two views, one progress state).

Do **not** list the same problem under two different `topic_id`s. One primary home only.

## Topic roots (mutually exclusive)

| Root | Use for |
| --- | --- |
| `algorithms/` | Named algorithm is the lesson (merge sort, BFS, binary search) |
| `patterns/` | Recognition family (DP, greedy, sliding window, intervals, …) |
| `data_structures/` | Structure / ADT is the lesson (heap, trie, …) |

### Placement (first match wins)

1. Named algorithm is the lesson → `algorithms/…`
2. Data structure is the lesson → `data_structures/…`
3. DP state / transitions are the hard part → `patterns/optimization/dp`
4. Greedy choice is the hard part → `patterns/optimization/greedy`
5. Contiguous subarray / substring window → `patterns/scanning/sliding_window`
6. Intervals / scheduling on `[start, end]` → `patterns/scanning/intervals`
7. Split + combine (not a concrete algorithm folder) → `patterns/divide_and_conquer`

## Theory (`README.md`, `kind: theory`)

| Section | Required | Notes |
| --- | --- | --- |
| `# Title` | yes | Matches `title` in frontmatter |
| `## Overview` | yes | What the technique is |
| `## Notes` | recommended | `> **Title:**` callouts for tips and personal notes |
| `## Key Observations` | recommended | Numbered list (`1.` …) |
| `## Rule of Thumb` | optional | Numbered list (`1.` …) |
| `## Algorithm Analysis` | recommended | Table + KaTeX (`$O(N^{2})$`, `$O(\log N)$`) - use `markdown-it-texmath` + katex 0.18 |
| `## References` | recommended | External links (include LeetCode lists here) |

Do **not** add a `## Practice` section - the site shows practice under **Patterns** and **Practice** tabs.

Do **not** list LeetCode problems in theory except as conceptual examples inside observations (avoid duplicate maintenance).

## Patterns (`0. patterns.md`, `kind: patterns`)

Organized **by pattern**. Each pattern is one section:

```markdown
## Pattern: Standard Binary Search on Sorted Array

**Use when:** ...
**Pattern:** ...
**Key insight:** ...

### Key skills
- skill one

### Problems
1. [Title](url)
```

Rules:

- Heading must start with `## Pattern: ` - the rest is the pattern name used in the **by-pattern** tab
- **Keep patterns few** - one pattern per recognition-level approach, not per validation trick or problem shape
- Validation hooks, counting tricks, and helper routines belong in **Key skills**, not new patterns
- Do not add "Hybrid / Advanced" patterns - harder problems still use the same parent pattern with a richer `check(mid)`
- Section order within a pattern: **Use when → Pattern → Key insight → Key skills → Problems** (matches the site UI)
- Problems under a pattern can be any difficulty - do not split by tier here
- Separate patterns with `---`
- Pattern names should be reusable wording (e.g. "Binary Search on Answer", "Sliding Window - Fixed Size")

## Difficulty tiers (`1. practice.md`, `kind: practice`)

Organized **by difficulty** in one file. Use `## Beginner`, `## Intermediate`, `## Advanced` sections:

```markdown
---
kind: practice
title: Practice
topic_id: category/path/topic
---

## Beginner

1. [Title](url)

## Intermediate

1. [Title](url)
```

Rules:

- One `1. practice.md` per topic (omit sections you do not need)
- Headings must be exactly `## Beginner`, `## Intermediate`, or `## Advanced`
- Problems only under each heading - no pattern prose
- On the site, all tiers appear under a single **Practice** tab as collapsible sections
- Same problem may also appear under a pattern in `0. patterns.md`

## Code (`<topic>.h`)

Optional. Manual implementation next to `README.md`. Shown under the **Code** tab. Not indexed as problems.

Prefer one primary `.h` per topic (the indexer currently picks the first `*.h` in the folder).

## Library (`library/<lang>.md` or `library.md`, `kind: library`)

Optional. Language / STL / standard-library usage for the topic (cheatsheet with snippets). Shown under the **Library** tab when present. Use the site **Language** dropdown (C++ / Java / Go) to switch variants.

Preferred layout:

```
<topic>/library/cpp.md
<topic>/library/java.md
<topic>/library/go.md
```

Legacy single file `library.md` is treated as C++. Each file should set `lang: cpp | java | go` in frontmatter.

| Section | Required | Notes |
| --- | --- | --- |
| `# Title` | yes | Matches `title` in frontmatter |
| Creating / Operations / Sample | recommended | Short code fences; keep runnable where useful |
| `## References` | recommended | cppreference, language docs |

Do **not** list LeetCode problems here - those belong in `practice/`.

Omit this file for topics with no library surface (typical for many algorithms). Data-structure topics often migrate content from `language/<lang>/…` into `library.md`, then remove the language file.

## Site views

| View | Source |
| --- | --- |
| Global | All unique slugs from included `practice/` files |
| By topic | Group by `topic_id` |
| By pattern | Group by `## Pattern: …` headings in `0. patterns.md` |
| By difficulty | Group by `## Beginner` / `## Intermediate` / `## Advanced` in `1. practice.md` |

Topic pages use presence-based sections: **Theory → Code → Library → Patterns → Practice**. A tab appears only when that content exists for the topic.

Progress counts: **unique slugs ticked / unique slugs total** - never count duplicate list entries.

## Filename rules

| File | Prefix | Purpose |
| --- | --- | --- |
| `library.md` | - | Library / STL usage (optional) |
| `0. patterns.md` | `0.` | Patterns cheat sheet |
| `1. practice.md` | `1.` | Practice by difficulty (all tiers in one file) |

Skip `library.md`, `0. patterns.md`, or `1. practice.md` when not needed.
