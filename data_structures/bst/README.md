---
kind: theory
title: Binary Search Tree
topic_id: data_structures/bst
---

# Binary Search Tree

## Overview

A binary search tree orders every left subtree before its node and every right subtree after it. Its ordering supports directed search and sorted inorder traversal.

## Key Observations

1. Validate bounds for the entire ancestor path, not only each parent and child.
2. Inorder traversal visits keys in sorted order.
3. Search and lowest-common-ancestor decisions discard one subtree using key order.
4. Deleting a node with two children requires a predecessor or successor replacement.

## Algorithm Analysis

Search, insertion, and deletion take $O(H)$ time, where $H$ is tree height: $O(\log N)$ when balanced and $O(N)$ in the worst case.

## References

1. [LeetCode Binary Search Tree](https://leetcode.com/tag/binary-search-tree/)
