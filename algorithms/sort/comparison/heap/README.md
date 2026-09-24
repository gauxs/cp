---
kind: theory
title: Heap Sort
topic_id: algorithms/sort/comparison/heap
---

# Heap Sort

## Overview

Build a max-heap (or min-heap), then repeatedly extract the root to obtain sorted order. Related to selection sort but uses heap structure for $O(\log N)$ extract per step.

## Key Observations

1. Guaranteed $O(N \log N)$ time with $O(1)$ extra space.
2. Not stable by default but can be adapted.
3. Heap operations also underpin priority-queue problems (top-K, streaming median).

## Algorithm Analysis

Let $N$ be the input size.

| Case | Time | Space |
| --- | --- | --- |
| Worst | $O(N \log N)$ | $O(1)$ |
| Average | $O(N \log N)$ | $O(1)$ |
| Best | $O(N \log N)$ | $O(1)$ |

In-place; not stable by default.

## References

1. [GeeksForGeeks - Heap Sort](https://www.geeksforgeeks.org/heap-sort/)
