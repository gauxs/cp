---
kind: theory
title: Heap (Priority Queue)
topic_id: data_structures/heap
---

# Heap (Priority Queue)

## Overview

A **binary heap** is a complete binary tree that satisfies the heap property: in a min-heap, every parent is $\le$ its children; in a max-heap, every parent is $\ge$ its children. The usual array layout places the root at index $0$, with children of $i$ at $2i+1$ and $2i+2$.

A **priority queue** is the ADT (insert, extract-min/max, peek). A binary heap is the common implementation; in C++ the STL type is `std::priority_queue`.

## Key Observations

1. Array-backed complete tree needs no explicit child pointers — parent of $i$ is $\lfloor (i-1)/2 \rfloor$.
2. Insert bubbles up; extract replaces root with last leaf and heapifies down — both $O(\log N)$.
3. `build_heap` from $N$ elements is $O(N)$ by heapifying from the last non-leaf upward (not $N$ inserts).
4. Default `std::priority_queue` is a **max-heap**; use `greater<>` (or a custom comparator) for a min-heap.
5. Prefer the library in contests unless you need decrease-key, indexed heap, or a custom layout.

## Rule of Thumb

1. Need k-th largest / smallest or streaming order stats → heap (or quickselect for one-shot k-th).
2. Need Dijkstra / best-first expansion → min-heap of pending nodes.
3. Need two running extremes (e.g. median) → two heaps.

## Operations Analysis

Let $N$ be the number of elements in the heap.

| Operation | Time | Notes |
| --- | --- | --- |
| Peek (top) | $O(1)$ | Root of the array |
| Insert (push) | $O(\log N)$ | Bubble up |
| Extract (pop) | $O(\log N)$ | Heapify down |
| Build from array | $O(N)$ | Bottom-up heapify |
| Heap sort | $O(N \log N)$ | Repeated extract |

## References

1. [GeeksforGeeks - Binary Heap](https://www.geeksforgeeks.org/binary-heap/)
2. [cppreference - std::priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue)
