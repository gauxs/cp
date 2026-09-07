---
kind: theory
title: Linked List
topic_id: data_structures/linked_list
---

# Linked List

## Overview

A linked list stores elements as nodes connected by references. Most interview problems test safe pointer rewiring, dummy nodes, and reasoning without random access.

## Key Observations

1. A dummy head removes special cases when the real head may change.
2. Save the next node before changing links.
3. Fast and slow pointers derive relative positions using only constant extra space.
4. Drawing the links before and after an operation prevents accidental cycles or lost suffixes.

## Algorithm Analysis

Most single-pass operations take $O(N)$ time and $O(1)$ auxiliary space.

## References

1. [LeetCode Linked List](https://leetcode.com/tag/linked-list/)
