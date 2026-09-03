---
kind: theory
title: Intervals
topic_id: patterns/scanning/intervals
---

# Intervals

## Overview

Problems whose input is ranges `[start, end]` (or events on a timeline). Typical flow: sort by start or end, then one linear scan, a greedy placement, or a heap / sweep for concurrency.

## Key Observations

1. Sorting establishes order so a single pass can merge, check conflicts, or place resources.
2. Overlap checks compare the current interval against the last accepted end (or active set).
3. Counting concurrent intervals often uses a min-heap of end times or a sweep line of $+1/-1$ events.
4. If the hard part is `dp[l][r]` on interval endpoints, primary home is Dynamic Programming - not here.

## Rule of Thumb

1. Merge / conflict check after sort → scan.
2. Minimum resources / rooms for concurrent ranges → heap or sweep.
3. Select max non-overlapping set → sort by end, greedy take.

## References

1. [LeetCode - Merge Intervals](https://leetcode.com/problems/merge-intervals/)
2. [LeetCode tag - Array (interval cluster)](https://leetcode.com/tag/array/)
