---
kind: theory
title: Quick Sort
topic_id: algorithms/sort/comparison/quick
---

# Quick Sort

## Overview

Divide and conquer: pick a pivot, partition so elements $\lt$ pivot are left and $\gt$ pivot are right, then recurse on subarrays.

## Key Observations

1. Partition is the core — places pivot in its final position in linear time.
2. Preferred over merge sort for arrays; merge sort is often better for linked lists.
3. Worst-case space can be reduced to $O(\log N)$ with tail-call optimization on recursion.

## Algorithm Analysis

Let $N$ be the input size.

| Case | Time | Space |
| --- | --- | --- |
| Worst | $O(N^{2})$ | $O(\log N)$ |
| Average | $O(N \log N)$ | $O(\log N)$ |
| Best | $O(N \log N)$ | $O(\log N)$ |

In-place; not stable.

## References

1. [GeeksForGeeks - Quick Sort](https://www.geeksforgeeks.org/quick-sort/)
2. [GeeksForGeeks - Quicksort Tail Call Optimization](https://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/)
