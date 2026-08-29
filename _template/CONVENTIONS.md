# Content Conventions

Rules for markdown in this repo and for the future static site.

## Frontmatter (required)

Every content file starts with YAML frontmatter:

```yaml
---
kind: theory | patterns | practice | category
title: Human-readable title
topic_id: category/path/topic    # stable id, e.g. algorithms/search/binary
---
```

Category index files (e.g. `algorithms/search/README.md`) use `kind: category` and `topic_id: algorithms/search`. They list child topics; they do not contain practice problems.

Practice tier files also include:

```yaml
tier: beginner | intermediate | advanced
```

`topic_id` should match the folder path from repo root (without leading slash).

## Problem links (required format)

Use markdown links to LeetCode only in `practice/` files:

```markdown
1. [Problem Title](https://leetcode.com/problems/problem-slug/)
```

The site uses `problem-slug` as the canonical id. One checkbox state per slug everywhere.

Problems may appear in **both** a pattern section and a difficulty tier - that is intentional (two views, one progress state).

## Theory (`README.md`, `kind: theory`)

| Section | Required | Notes |
| --- | --- | --- |
| `# Title` | yes | Matches `title` in frontmatter |
| `## Overview` | yes | What the technique is |
| `## Notes` | recommended | `> **Title:**` callouts for tips and personal notes |
| `## Key Observations` | recommended | Numbered list (`1.` …) |
| `## Rule of Thumb` | optional | Numbered list (`1.` …) |
| `## Algorithm Analysis` | recommended | Time / space in a fenced block |
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

### Problems
1. [Title](url)

### Key skills
- skill one
```

Rules:

- Heading must start with `## Pattern: ` - the rest is the pattern name used in the **by-pattern** tab
- Problems under a pattern can be any difficulty - do not split by tier here
- Separate patterns with `---`
- Pattern names should be reusable wording (e.g. "Binary Search on Answer", "Sliding Window - Fixed Size")

## Difficulty tiers (`1./2./3. *.md`, `kind: practice`)

Organized **by difficulty**. Flat numbered list only:

```markdown
## Beginner

1. [Title](url)
```

Rules:

- Heading `## Beginner` / `## Intermediate` / `## Advanced` must match `tier` in frontmatter
- Problems only - no pattern prose
- On the site, all tiers appear under a single **Practice** tab as collapsible sections (not separate tabs)
- Same problem may also appear under a pattern in `0. patterns.md`

## Code (`<topic>.h`)

Optional. Keep next to `README.md`. Not indexed as problems.

## Site views (future)

| View | Source |
| --- | --- |
| Global | All unique slugs from included `practice/` files |
| By topic | Group by `topic_id` |
| By pattern | Group by `## Pattern: …` headings in `0. patterns.md` |
| By difficulty | Group by `tier` in `1./2./3. *.md` |

Topic pages use four sections: **Theory → Code → Patterns → Practice**. Patterns and practice tiers render as collapsible lists (collapsed by default).

Progress counts: **unique slugs ticked / unique slugs total** - never count duplicate list entries.

## Filename rules

| File | Prefix | Purpose |
| --- | --- | --- |
| `0. patterns.md` | `0.` | Patterns cheat sheet |
| `1. beginner.md` | `1.` | Beginner tier |
| `2. intermediate.md` | `2.` | Intermediate tier |
| `3. advanced.md` | `3.` | Advanced tier |

Skip files you do not need (e.g. only `0.` and `2.` is fine).
