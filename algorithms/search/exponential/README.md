---
kind: theory
title: Exponential Search
topic_id: algorithms/search/exponential
---

# Exponential Search

## Overview

Exponential Search (also called exponential binary search) finds a range where the target may exist by doubling the index, then runs binary search within that range. It is especially useful when the search space is unbounded or when the target lies near the start of a bounded array.

## Key Observations

1. Particularly useful for **unbounded** searches where array size is effectively infinite.
2. On **bounded** arrays, it can outperform plain binary search when the target is closer to the first element.

## Algorithm Analysis

```
N - size of input

Time Complexity:
    Worst:   O(log N)
    Average: O(log N)
    Best:    O(log N)

Space Complexity: O(1)
```

## References

1. [GeeksForGeeks - Exponential Search](https://www.geeksforgeeks.org/exponential-search/)
