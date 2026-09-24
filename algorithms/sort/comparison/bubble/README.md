---
kind: theory
title: Bubble Sort
topic_id: algorithms/sort/comparison/bubble
---

# Bubble Sort

## Overview

Repeatedly swaps adjacent elements if they are in the wrong order. One pass moves the largest element to the end; after $i$ passes, the last $i$ elements are in place.

## Key Observations

1. After the first pass, the last index is in its final position.
2. Useful in graphics for detecting tiny errors in nearly sorted arrays (linear extra work).
3. Simple but $O(N^{2})$ in typical cases.

## Algorithm Analysis

Let $N$ be the input size.

| Case | Time | Space |
| --- | --- | --- |
| Worst | $O(N^{2})$ | $O(1)$ |
| Average | $O(N^{2})$ | $O(1)$ |
| Best | $O(N)$ | $O(1)$ |

Stable and in-place.

## References

1. [GeeksForGeeks - Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)
