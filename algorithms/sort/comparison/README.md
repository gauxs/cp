---
kind: category
title: Comparison Sort
topic_id: algorithms/sort/comparison
---

# Comparison Sort

Sorts by comparing pairs of elements. General comparison sorts run in $O(N \log N)$ time; several simple algorithms are $O(N^{2})$.

## Topics

| Topic | Theory | Code |
| --- | --- | --- |
| [Bubble Sort](bubble/README.md) | [README](bubble/README.md) | [bubble.h](bubble/bubble.h) |
| [Heap Sort](heap/README.md) | [README](heap/README.md) | [heap.h](heap/heap.h) |
| [Insertion Sort](insertion/README.md) | [README](insertion/README.md) | [insertion.h](insertion/insertion.h) |
| [Merge Sort](merge/README.md) | [README](merge/README.md) | [merge.h](merge/merge.h) |
| [Quick Sort](quick/README.md) | [README](quick/README.md) | [quick.h](quick/quick.h) |
| [Selection Sort](selection/README.md) | [README](selection/README.md) | [selection.h](selection/selection.h) |
| [Shell Sort](shell/README.md) | [README](shell/README.md) | [shell.h](shell/shell.h) |

## Summary

| Algorithm | Best | Average | Worst | Space | Stable | In-place |
| --- | --- | --- | --- | --- | --- | --- |
| Bubble | $O(N)$ | $O(N^{2})$ | $O(N^{2})$ | $O(1)$ | Yes | Yes |
| Selection | $O(N^{2})$ | $O(N^{2})$ | $O(N^{2})$ | $O(1)$ | No | Yes |
| Insertion | $O(N)$ | $O(N^{2})$ | $O(N^{2})$ | $O(1)$ | Yes | Yes |
| Merge | $O(N \log N)$ | $O(N \log N)$ | $O(N \log N)$ | $O(N)$ | Yes | No |
| Quick | $O(N \log N)$ | $O(N \log N)$ | $O(N^{2})$ | $O(\log N)$ | No | Yes |
| Heap | $O(N \log N)$ | $O(N \log N)$ | $O(N \log N)$ | $O(1)$ | No | Yes |
| Shell | $O(N \log N)$* | $O(N^{1.5})$* | $O(N^{2})$ | $O(1)$ | No | Yes |

\*Depends on gap sequence.
