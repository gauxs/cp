---
kind: theory
title: Difference Array
topic_id: patterns/scanning/difference_array
---

# Difference Array

## Overview

A difference array records where a range update starts and where its effect stops. One final prefix scan reconstructs every resulting value.

## Key Observations

1. Add at the left boundary and subtract immediately after the right boundary.
2. Coordinate compression or an event map handles large or sparse coordinates.
3. Difference arrays optimize batches of updates; they are not intended for interleaved online queries.

## Algorithm Analysis

For $Q$ updates over $N$ positions, updates take $O(Q)$ total and reconstruction takes $O(N)$.

## References

1. [USACO Guide - Difference Arrays](https://usaco.guide/silver/prefix-sums#difference-arrays)
