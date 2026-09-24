---
kind: theory
title: Selection Sort
topic_id: algorithms/sort/comparison/selection
---

# Selection Sort

## Overview

Repeatedly selects the minimum from the unsorted portion and places it at the front. Performs at most $O(N)$ swaps.

## Key Observations

1. Useful when memory writes are expensive (few swaps).
2. Not stable by default; can be made stable by shifting instead of swapping.
3. Always $\Theta(N^{2})$ comparisons regardless of input order.

## Algorithm Analysis

Let $N$ be the input size.

| Case | Time | Space |
| --- | --- | --- |
| Worst | $O(N^{2})$ | $O(1)$ |
| Average | $O(N^{2})$ | $O(1)$ |
| Best | $O(N^{2})$ | $O(1)$ |

In-place; not stable by default.

## References

1. [GeeksForGeeks - Selection Sort](https://www.geeksforgeeks.org/selection-sort/)
