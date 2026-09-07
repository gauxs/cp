---
kind: theory
title: Backtracking
topic_id: algorithms/backtracking
---

# Backtracking

## Overview

Backtracking explores a decision tree by choosing an option, recursing, and undoing the choice. Constraints prune branches that cannot produce valid answers.

## Key Observations

1. Define the state, available choices, completion condition, and pruning rule.
2. Restore every mutable choice before returning to the caller.
3. Sort candidates when duplicate skipping or early termination depends on order.
4. Separate path construction from result recording.

## Algorithm Analysis

Runtime is usually exponential in the number of decisions; effective pruning reduces the explored state space. Recursion uses space proportional to decision depth.

## References

1. [LeetCode Backtracking](https://leetcode.com/tag/backtracking/)
