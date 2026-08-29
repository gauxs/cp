---
kind: category
title: Search
topic_id: algorithms/search
---

# Search

Search algorithms for sorted and unsorted data: classic lookup, selection, and bounded/unbounded search strategies.

## Topics

| Topic | Theory | Code | Practice |
| --- | --- | --- | --- |
| [Binary Search](binary/README.md) | [README](binary/README.md) | [binary.h](binary/binary.h) | [practice/](binary/practice/) |
| [Jump Search](jump/README.md) | [README](jump/README.md) | [jump.h](jump/jump.h) | — |
| [Quick Select](quick_select/README.md) | [README](quick_select/README.md) | [quick_select.h](quick_select/quick_select.h) | [practice/](quick_select/practice/) |
| [Exponential Search](exponential/README.md) | [README](exponential/README.md) | [exponential.h](exponential/exponential.h) | — |

## Layout

Each topic follows [_template/topic/](../../_template/topic/):

```
<topic>/
├── README.md           # kind: theory
├── <topic>.h           # implementation
└── practice/           # optional
    ├── 0. patterns.md  # kind: patterns
    └── N. <tier>.md    # kind: practice
```

See [_template/CONVENTIONS.md](../../_template/CONVENTIONS.md) for content rules.
