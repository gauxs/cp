---
kind: theory
title: Bucket Sort
topic_id: algorithms/sort/non_comparison/bucket
---

# Bucket Sort

## Overview

Distributes elements into buckets, sorts each bucket (often with insertion sort), then concatenates.

## Key Observations

1. Best when input is uniformly distributed over a range.
2. Average linear; worst case degrades if many elements land in one bucket.
3. Related to pigeonhole and counting ideas for bounded ranges.

## Algorithm Analysis

Let $N$ be the input size and $k$ the number of buckets.

| Case | Time | Space |
| --- | --- | --- |
| Worst | $O(N^{2})$ | $O(N + k)$ |
| Average | $O(N + k)$ | $O(N + k)$ |
| Best | $O(N + k)$ | $O(N + k)$ |

Stable; not in-place.

## References

1. [GeeksForGeeks - Bucket Sort](https://www.geeksforgeeks.org/bucket-sort-2/)
