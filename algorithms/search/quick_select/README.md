---
kind: theory
title: Quick Select
topic_id: algorithms/search/quick_select
---

# Quick Select

## Overview

Quickselect finds the k-th smallest element in an unordered list. It is related to quicksort: the partition step is the same, but recursion continues only on the side containing the k-th smallest element.

## Key Observations

1. The partition process is the same as QuickSort; only the recursive calls differ.
2. Like quicksort, it is fast in practice but has poor worst-case performance.
3. There exists an algorithm that finds the [k-th smallest element in O(n)](https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/) in the worst case, but QuickSelect performs better on average.

## Algorithm Analysis

```
N - size of input

Time Complexity:
    Worst:   O(N^2)
    Average: O(N)
    Best:    O(1)

Space Complexity: O(1)
```

## References

1. [GeeksForGeeks - Quick Select](https://www.geeksforgeeks.org/quickselect-algorithm/)
2. [k-th smallest element in O(n)](https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/)
