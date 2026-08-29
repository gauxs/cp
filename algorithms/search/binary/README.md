---
kind: theory
title: Binary Search
topic_id: algorithms/search/binary
---

# Binary Search

## Overview

At each step, the algorithm compares the median value in the search space to the target value. Based on the comparison and because the sequence is sorted, it can then eliminate half of the search space. By doing this repeatedly, it will eventually be left with a search space consisting of a single element, the target value.

Sometimes we won't even realize that the problem should be solved with binary search — we might turn to dynamic programming or DFS and get stuck for a very long time. **When can we use binary search?** If we can discover some kind of monotonicity, for example, if `condition(k)` is True then `condition(>k)` is True, or if `condition(k)` is False then `condition(>k)` is False (and vice-versa), then we can consider binary search.

## Key Observations

1. **Choice of `low` and `high` (the boundary):** Normally we set the initial boundary to the number of elements in the array (`low=0`, `high=n-1`), but this is not always the case. The boundary is the range of elements we will be searching from. The initial boundary should include ALL possible answers. Binary search applies to non-array problems too (e.g. math). For example, Search Insert Position asks for an index to insert into the array — it is possible to insert after the last element, so the boundary becomes `low=0` and `high=n`.

2. **Calculating `mid` can overflow** when numbers are extremely big:
   - `mid = (low + high) / 2` — worst, very easy to overflow
   - `mid = low + (high - low) / 2` — much better, but still possible
   - `mid = (low + high) >>> 1` — the best, but harder to understand

3. **Left vs right mid:** With an even number of elements, we choose the left or right mid. A bad choice leads to an infinite loop:
   - `mid = low + (high - low) / 2` — left/lower mid
   - `mid = low + (high - low + 1) / 2` — right/upper mid

4. **While loop condition `low < high`:** The loop exits only when `low == high`. They point to the same element, and we know that element always exists:
   ```cpp
   while (low < high) { ... }
   ```

5. **Avoiding infinite loops:** The choice of `mid` and shrinking logic must work together so at least one element is excluded each step. When stuck, think about the case when only 2 elements remain. Did the boundary shrink correctly?

   Choosing left mid with `low = mid` when `target > nums[mid]`:
   ```cpp
   int mid = low + (high - low) / 2;
   while (low < high) {
     ...
     if (target < nums[mid]) {
       high = mid - 1;
     } else {
       low = mid;  // infinite loop risk with left mid
     }
     ...
   }
   ```

   Choosing right mid with `high = mid` when `target > nums[mid]`:
   ```cpp
   int mid = low + (high - low + 1) / 2;
   while (low < high) {
     ...
     if (target > nums[mid]) {
       low = mid + 1;
     } else {
       high = mid;  // infinite loop risk with right mid
     }
     ...
   }
   ```

### Rule of Thumb

1. Include ALL possible answers when initializing `low` and `high`
2. Don't overflow the mid calculation
3. Shrink boundary using logic that excludes `mid`
4. Avoid infinite loops by picking the correct mid and shrinking logic
5. Always think of the case when there are 2 elements left

> **Note:** I have neglected all the points mentioned here and followed my implementation `binary_iterative()` because it is another way of implementing bug-free binary search and seems to work in every question solved till now.

## Algorithm Analysis

```
N - size of input

Time Complexity:
    Worst:   O(log N)
    Average: O(log N)
    Best:    O(log N)

Space Complexity: O(1)
```

## Practice

Problems live in `practice/` only. Study flow: patterns → difficulty tiers.

- [Patterns & Techniques](practice/0.%20patterns.md)
- [Beginner](practice/1.%20beginner.md)
- [Intermediate](practice/2.%20intermediate.md)
- [Advanced](practice/3.%20advanced.md)

Additional resources:

- [Leetcode - My Binary Search List](https://leetcode.com/list/9zvbx4we)

## References

1. [Topcoder - Binary Search](https://www.topcoder.com/thrive/articles/Binary%20Search)
2. [Leetcode - Binary Search 101](https://leetcode.com/problems/binary-search/discuss/423162/Binary-Search-101-The-Ultimate-Binary-Search-Handbook)
