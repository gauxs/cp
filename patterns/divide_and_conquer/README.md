---
kind: theory
title: Divide and Conquer
topic_id: patterns/divide_and_conquer
---

# Divide and Conquer

## Overview

Break the problem into independent subproblems, solve recursively, then combine. Recognition axes: split by midpoint, split on bad elements, partition on a pivot, or divide the **answer space** (often overlaps Binary Search on Answer — see `algorithms/search/binary`).

## Key Observations

1. **Mid-split + combine:** cross-mid cases dominate merge-sort-style counting (e.g. range sums).
2. **Split on property:** invalid characters force cuts; recurse on segments.
3. **Pivot / quickselect:** partition and recurse one side — primary home is `algorithms/search/quick_select`.
4. **Binary search on answer:** divide answer range, not the array — primary home is `algorithms/search/binary`.
5. **Trees:** each node splits into subtrees; tree DP often owns path-sum style problems.

## Rule of Thumb

Ask: split by **mid**, **bad element**, **pivot**, or **answer value**? Named merge / quickselect implementations live under `algorithms/sort` and `algorithms/search`.

## References

1. [LeetCode - Divide and Conquer tag](https://leetcode.com/tag/divide-and-conquer/)
