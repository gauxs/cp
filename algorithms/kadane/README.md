---
kind: theory
title: Kadane's Algorithm
topic_id: algorithms/kadane
---

# Kadane's Algorithm

## Overview

Kadane's algorithm finds the best contiguous subarray by deciding at each position whether to extend the previous segment or start a new one.

## Key Observations

1. The running state is the best subarray ending exactly at the current position.
2. The global answer is the best ending-state seen anywhere.
3. Initialize from an array element rather than zero when all values may be negative.
4. Track a candidate start whenever beginning anew is better than extending.
5. Circular variants compare the ordinary maximum with total sum minus the minimum subarray.

## Algorithm Analysis

Kadane's algorithm runs in $O(N)$ time and uses $O(1)$ auxiliary space.

## References

1. [CP-Algorithms - Search the Subarray with the Maximum/Minimum Sum](https://cp-algorithms.com/others/maximum_average_segment.html)
2. [GeeksforGeeks - Largest Sum Contiguous Subarray](https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/)
