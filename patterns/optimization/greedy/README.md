---
kind: theory
title: Greedy
topic_id: patterns/optimization/greedy
---

# Greedy

## Overview

Make locally optimal choices when an exchange argument or structural proof shows they yield a global optimum. Often preceded by sorting.

## Key Observations

1. Greedy fails when local choices need future rollback — use DP instead.
2. Interval scheduling by earliest end is a classic greedy proof.
3. **Capacity to Ship Packages Within D Days** and similar feasibility problems → Binary Search on Answer (`algorithms/search/binary`), not greedy primary home.
4. Meeting-room style range problems → Scanning → Intervals when input is `[start, end]`.

## Rule of Thumb

Can you prove that picking the “best looking” option now never hurts? If not, try DP or BS on answer.

## References

1. [LeetCode - Greedy tag](https://leetcode.com/tag/greedy/)
