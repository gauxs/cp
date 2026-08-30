---
kind: theory
title: Radix Sort
topic_id: algorithms/sort/non_comparison/radix
---

# Radix Sort

## Overview

Sorts digit by digit from least significant to most significant, using a stable subroutine (typically counting sort) per digit.

## Key Observations

1. Linear when number of digits $d$ and base $B$ are small relative to $N$.
2. May not beat comparison sorts in practice due to constants and cache behavior.
3. Useful for large integers with bounded digit count.

## Algorithm Analysis

Let $N$ be elements, $d$ digits, base $B$, and $k$ counting-sort range (often $B$).

| Case | Time | Space |
| --- | --- | --- |
| Worst | $O(d \cdot (N + k))$ | $O(N + k)$ |
| Average | $O(d \cdot (N + k))$ | $O(N + k)$ |
| Best | $O(d \cdot (N + k))$ | $O(N + k)$ |

Stable; not in-place.

## References

1. [GeeksForGeeks - Radix Sort](https://www.geeksforgeeks.org/radix-sort/)
