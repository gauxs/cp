---
kind: theory
title: Two Pointers
topic_id: patterns/scanning/two_pointers
---

# Two Pointers

## Overview

Two pointers scan an array or string while maintaining a relationship between two positions. The pointers may move toward each other or in the same direction.

## Key Observations

1. Opposite-end pointers are useful when sorted order or geometry tells which side must move.
2. Same-direction pointers are useful for compaction, partitioning, and maintaining a valid range.
3. Sorting can expose pointer monotonicity, but account for whether original indices must be preserved.

## Algorithm Analysis

After any required sorting, the scan usually takes $O(N)$ time and $O(1)$ auxiliary space.

## References

1. [LeetCode Two Pointers](https://leetcode.com/tag/two-pointers/)
