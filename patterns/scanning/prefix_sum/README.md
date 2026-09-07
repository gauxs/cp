---
kind: theory
title: Prefix Sum
topic_id: patterns/scanning/prefix_sum
---

# Prefix Sum

## Overview

A prefix sum stores the aggregate of every prefix so that a range sum becomes the difference of two prefix values. Combined with hashing, it can count subarrays whose aggregate satisfies a target or remainder condition.

## Key Observations

1. Define `prefix[0] = 0` so ranges beginning at index zero need no special case.
2. A subarray sum from `l` through `r` is `prefix[r + 1] - prefix[l]`.
3. For counting problems, store how often each earlier prefix or remainder has appeared.

## Algorithm Analysis

Preprocessing takes $O(N)$ time and usually $O(N)$ space. Each range query is $O(1)$.

## References

1. [USACO Guide - Prefix Sums](https://usaco.guide/silver/prefix-sums)
