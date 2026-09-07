---
kind: theory
title: Monotonic Stack and Queue
topic_id: data_structures/monotonic
---

# Monotonic Stack and Queue

## Overview

A monotonic stack or queue keeps its candidate elements entirely in non-increasing or non-decreasing order. Elements made permanently irrelevant by a new value are removed immediately.

## Key Observations

1. A monotonic decreasing stack produces a decreasing sequence when popped, respects the input order, and may purge earlier values dominated by the newest value.
2. A monotonic queue is usually implemented with a deque. Elements may be removed from both ends but are inserted only at the back.
3. The front is the current minimum or maximum, depending on the maintained order.
4. Each element is inserted once and removed at most once, so a complete scan is $O(N)$.
5. Stacks model nearest-greater or nearest-smaller relationships; queues additionally evict indices that leave a moving window.

## Algorithm Analysis

| Operation | Amortized time | Space |
| --- | --- | --- |
| Insert and remove dominated candidates | $O(1)$ | $O(N)$ |
| Complete scan | $O(N)$ | $O(N)$ |

## References
- [My monotonic queue questions list](https://leetcode.com/list/9i2dcaum)
- [Monotonic Queues and Monotonic Optimization in Dynamic Programming](https://activities.tjhsst.edu/sct/lectures/1920/2020_2_21_Monotonic_Queues.pdf)
- [Medium article on monotonic queue](https://1e9.medium.com/monotonic-queue-notes-980a019d5793)
- [Applications of Monotonous Increasing stack](https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step) by [@wxd_sjtu](https://leetcode.com/wxd_sjtu/)
- [Monotonic Queue Summary](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/204290/Monotonic-Queue-Summary) by [@luxy622](https://leetcode.com/luxy622/)