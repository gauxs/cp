---
kind: theory
title: Sliding Window
topic_id: patterns/scanning/sliding_window
---

# Sliding Window

## Overview

Maintain a **contiguous** window over an array or string with two pointers (left / right). Expand right to grow the window; shrink left when constraints break. Used for longest / shortest subarray problems and counting valid windows.

## Key Observations

1. Window is always contiguous — not an arbitrary subset.
2. Variable-size windows need a clear invariant and a `while` shrink loop when invalid.
3. Fixed-size windows slide without resizing — sum or frequency updates per step.
4. **At most K** vs **exactly K** distinct: use inclusion-exclusion (`atMost(K) - atMost(K-1)`).
5. Sum constraints often use monotonicity; negative numbers may need a deque + prefix sums instead.
6. Min/max in a sliding range → monotonic deque (not always plain two pointers).

## Rule of Thumb

1. Contiguous substring / subarray + optimize length or count → consider sliding window.
2. Explicit `[start, end]` ranges on a timeline → Intervals, not here.
3. [Contiguous Array](https://leetcode.com/problems/contiguous-array/) uses prefix sum + hash map — not sliding window.

## References

1. [LeetCode - Sliding Window tag](https://leetcode.com/tag/sliding-window/)
