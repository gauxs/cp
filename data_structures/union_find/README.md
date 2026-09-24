---
kind: theory
title: Disjoint Set Union
topic_id: data_structures/union_find
---

# Disjoint Set Union

## Overview

Often it is also called **Union Find** because of its two main operations. This data structure provides the following capabilities. We are given several elements, each of which is a separate set. A DSU will have an operation to combine any two sets, and it will be able to tell in which set a specific element is. The classical version also introduces a third operation, it can create a set from a new element.

Thus the basic interface of this data structure consists of only three operations:
1. make_set
2. union_sets
3. find_set

**Applications** of this data structure are mentioned in the references.

## Algorithm Analysis
```
    N - number of elements

    Time complexity:
        1. make_set:                                    O(1)
        2. find_set(without balancing):                  O(N)
        3. amortized operation with both optimizations:  O(α(N))

    Space complexity:   O(N)
```

## References
1. [CP Algorithms - Disjoint set union](https://cp-algorithms.com/data_structures/disjoint_set_union.html)
2. [LeetCode Union Find](https://leetcode.com/tag/union-find/)
3. [Most Stones Removed with Same Row or Column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/)
4. [Satisfiability of Equality Equations](https://leetcode.com/problems/satisfiability-of-equality-equations/)
5. [Redundant Connection II](https://leetcode.com/problems/redundant-connection-ii/)
