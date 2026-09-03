---
kind: theory
title: Dynamic Programming
topic_id: patterns/optimization/dp
---

# Dynamic Programming

## Overview

Optimize over recursion by storing subproblem results. Map problems to a **state**, **transitions**, and **base cases**; choose top-down or bottom-up.

## Key Observations

1. Some problems need a **fresh** sub-state each recursion (e.g. decode ways); others **reuse** prior state (subset sum).
2. Memoization array size $\neq$ runtime — e.g. LIS can be $O(N)$ space but $O(N^2)$ time.
3. Top-down base cases can be **tight** (return formula immediately) vs **weak** (fill many cells) — see Edit Distance last row.
4. Top-down often converts to bottom-up by mirroring recursion order and bases.
5. Interval-shaped inputs with `dp[l][r]` transitions belong here even when input is intervals — not under Scanning → Intervals.
6. Memory-optimized DP keeps recurrence but compresses dimensions (1D rolling row, bitset).

## Rule of Thumb

Define state before code. If transitions need all split points on an interval → interval DP. If state is on a tree → tree DP.

## References

1. [Dynamic Programming Summary](https://leetcode.com/discuss/general-discussion/592146/dynamic-programming-summary) by [@richenyunqi](https://leetcode.com/richenyunqi)
2. [How to approach DP problems](https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems) by [@heroes3001](https://leetcode.com/heroes3001)
3. [LeetCode - Dynamic Programming tag](https://leetcode.com/tag/dynamic-programming/)
