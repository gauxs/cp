---
kind: theory
title: Merge Sort
topic_id: algorithms/sort/comparison/merge
---

# Merge Sort

## Overview

Divide and conquer: split the array in half, sort recursively, then merge two sorted halves in linear time.

## Key Observations

1. Guaranteed $O(N \log N)$ regardless of input.
2. Stable; requires $O(N)$ extra space for the merge buffer.
3. Preferred for linked lists and external sorting; slower constant factors than quick sort on arrays.

## Algorithm Analysis

Let $N$ be the input size.

| Case | Time | Space |
| --- | --- | --- |
| Worst | $O(N \log N)$ | $O(N)$ |
| Average | $O(N \log N)$ | $O(N)$ |
| Best | $O(N \log N)$ | $O(N)$ |

Stable; not in-place.

## References

1. [GeeksForGeeks - Merge Sort](https://www.geeksforgeeks.org/merge-sort/)
