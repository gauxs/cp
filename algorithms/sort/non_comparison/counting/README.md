---
kind: theory
title: Counting Sort
topic_id: algorithms/sort/non_comparison/counting
---

# Counting Sort

## Overview

Counts occurrences of each key in a bounded range, then reconstructs the sorted output from cumulative counts.

## Key Observations

1. Works when keys lie in a known range $k$.
2. Can sort characters when alphabet size is fixed (e.g. 26 letters).
3. Building block for radix sort.

## Algorithm Analysis

Let $N$ be the input size and $k$ the key range.

| Case | Time | Space |
| --- | --- | --- |
| Worst | $O(N + k)$ | $O(k)$ |
| Average | $O(N + k)$ | $O(k)$ |
| Best | $O(N + k)$ | $O(k)$ |

Stable; not in-place.

## References

1. [GeeksForGeeks - Counting Sort](https://www.geeksforgeeks.org/counting-sort/)
