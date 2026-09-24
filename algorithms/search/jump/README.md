---
kind: theory
title: Jump Search
topic_id: algorithms/search/jump
---

# Jump Search

## Overview

Jump Search works on sorted data by jumping ahead in fixed blocks, then performing linear search within the block where the target may lie. Time complexity sits between linear and binary search.

## Key Observations

1. Works on sorted data only.
2. Jumps by a fixed length `M` until we find an element greater than the search element, then perform linear search in that range.
3. Worst case: `N/M` jumps; when the last checked value is greater than the search element, linear search does `(M-1)` comparisons.
4. Total comparisons `(N/M) + (M-1)` is minimized when `M = sqrt(N)`.
5. Time complexity is between Binary Search and Linear Search.
6. Binary Search is generally better, but Jump Search traverses back only once (Binary Search may require up to `O(log n)` jumps - e.g. when the target is the smallest element or smaller). In systems where backward traversal is costly, Jump Search can be preferable.

## Algorithm Analysis

Let $N$ be the input size.

| Case | Time | Space |
| --- | --- | --- |
| Worst | $O(\sqrt{N})$ | $O(1)$ |
| Average | $O(\sqrt{N})$ | $O(1)$ |
| Best | $O(1)$ | $O(1)$ |

## References

1. [GeeksForGeeks - Jump Search](https://www.geeksforgeeks.org/jump-search/)
