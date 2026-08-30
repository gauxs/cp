---
kind: theory
title: Sliding Window
topic_id: patterns/scanning/sliding_window
---

# Sliding Window

## Overview

Maintain a contiguous window over an array or string while expanding / shrinking to satisfy a constraint. Practice content will migrate from `paradigms/sliding_window/`.

## Key Observations

1. Window is always contiguous — not an arbitrary subset.
2. Expand right; shrink left when the invariant breaks.
3. Prefer this over Intervals when there are no explicit `[start, end]` ranges.

## References

1. [LeetCode - Sliding Window](https://leetcode.com/tag/sliding-window/)
