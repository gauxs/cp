---
kind: theory
title: Insertion Sort
topic_id: algorithms/sort/comparison/insertion
---

# Insertion Sort

## Overview

Maintains a sorted prefix; each step inserts the next element into its correct position in the sorted part.

## Key Observations

1. Efficient for small $N$.
2. Fast when the array is nearly sorted.
3. Binary insertion sort reduces comparisons via binary search on the sorted prefix.

## Algorithm Analysis

Let $N$ be the input size.

| Case | Time | Space |
| --- | --- | --- |
| Worst | $O(N^{2})$ | $O(1)$ |
| Average | $O(N^{2})$ | $O(1)$ |
| Best | $O(N)$ | $O(1)$ |

Stable and in-place.

## References

1. [GeeksForGeeks - Insertion Sort](https://www.geeksforgeeks.org/insertion-sort/)
