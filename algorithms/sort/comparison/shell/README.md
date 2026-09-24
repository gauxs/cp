---
kind: theory
title: Shell Sort
topic_id: algorithms/sort/comparison/shell
---

# Shell Sort

## Overview

Generalized insertion sort with a gap sequence: sort subarrays of elements $H$ apart, then reduce $H$ until $H = 1$.

## Key Observations

1. Allows exchanges of far-apart elements early (unlike plain insertion sort).
2. An array is $H$-sorted when every sublist of $H$-separated elements is sorted.
3. Performance depends heavily on the gap sequence.

## Algorithm Analysis

Let $N$ be the input size.

| Case | Time | Space |
| --- | --- | --- |
| Worst | $O(N^{2})$ | $O(1)$ |
| Average | $O(N^{1.5})$* | $O(1)$ |
| Best | $O(N \log N)$* | $O(1)$ |

\*Depends on gap sequence. In-place; not stable.

## References

1. [GeeksForGeeks - Shell Sort](https://www.geeksforgeeks.org/shellsort/)
