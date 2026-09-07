---
kind: theory
title: Binary Tree
topic_id: data_structures/tree
---

# Binary Tree

## Overview

Binary-tree problems combine recursive subtree reasoning with level-order traversal. The traversal order should match the information dependency: depth-first for subtree results and breadth-first for levels.

## Key Observations

1. Define exactly what a recursive call returns before combining child results.
2. Distinguish a root-to-node path from an arbitrary path through a tree.
3. A queue snapshot gives the number of nodes in the current BFS level.
4. Null children and leaf conditions should be handled explicitly.

## Algorithm Analysis

Both DFS and BFS visit each node once in $O(N)$ time. Auxiliary space is $O(H)$ for DFS or $O(W)$ for BFS, where $H$ is height and $W$ is maximum width.

## References

1. [LeetCode Binary Tree](https://leetcode.com/tag/binary-tree/)
