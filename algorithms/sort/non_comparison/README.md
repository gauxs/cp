---
kind: category
title: Non-Comparison Sort
topic_id: algorithms/sort/non_comparison
---

# Non-Comparison Sort

Uses key structure (counts, digits, buckets) instead of element comparison. Often linear when $k$ (range / buckets / digits) is small.

## Topics

| Topic | Theory | Code |
| --- | --- | --- |
| [Bucket Sort](bucket/README.md) | [README](bucket/README.md) | [bucket.h](bucket/bucket.h) |
| [Counting Sort](counting/README.md) | [README](counting/README.md) | [counting.h](counting/counting.h) |
| [Radix Sort](radix/README.md) | [README](radix/README.md) | [radix.h](radix/radix.h) |

## Summary

| Algorithm | Time | Space | Stable | In-place |
| --- | --- | --- | --- | --- |
| Counting | $O(N + k)$ | $O(k)$ | Yes | No |
| Radix | $O(d \cdot (N + k))$ | $O(N + k)$ | Yes | No |
| Bucket | $O(N + k)$ avg | $O(N + k)$ | Yes | No |
