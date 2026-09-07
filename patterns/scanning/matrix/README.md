---
kind: theory
title: Matrix Scanning
topic_id: patterns/scanning/matrix
---

# Matrix Scanning

## Overview

Matrix problems combine two-dimensional traversal with careful coordinate transformations. Common techniques include direction vectors, shrinking boundaries, layer-by-layer processing, and transpose/reflection operations.

## Key Observations

1. Keep row and column bounds explicit; most simulation bugs are boundary errors.
2. A direction array centralizes neighbor movement and turning logic.
3. Clockwise rotation by $90^\circ$ is a horizontal reflection followed by a transpose.
4. Counter-clockwise rotation by $90^\circ$ is a vertical reflection followed by a transpose.
5. In-place marking may encode state in the matrix when the original value set leaves spare markers.

## Algorithm Analysis

Most full-matrix traversals and transformations take $O(RC)$ time. In-place transformations use $O(1)$ auxiliary space; output-generating traversals use space proportional to their output.

## References

1. [LeetCode Matrix](https://leetcode.com/tag/matrix/)
