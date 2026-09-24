---
kind: category
title: Sort
topic_id: algorithms/sort
---

# Sort

Sorting algorithms rearrange elements according to a comparison operator or key structure. Topics are grouped by comparison-based vs non-comparison approaches.

## Subcategories

| Subcategory | Topics |
| --- | --- |
| [Comparison Sort](comparison/README.md) | Bubble, Selection, Insertion, Merge, Quick, Heap, Shell |
| [Non-Comparison Sort](non_comparison/README.md) | Counting, Radix, Bucket |

## Layout

Each topic follows [_template/topic/](../../_template/topic/):

```
<topic>/
├── README.md           # kind: theory
├── <topic>.h           # implementation
└── practice/           # optional
    ├── 0. patterns.md  # kind: patterns
    └── 1. practice.md  # kind: practice (tier sections)
```

See [_template/CONVENTIONS.md](../../_template/CONVENTIONS.md) for content rules.
