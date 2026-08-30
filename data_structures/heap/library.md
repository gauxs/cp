---
kind: library
title: Heap — std::priority_queue
topic_id: data_structures/heap
---

# Heap — `std::priority_queue`

A **max-heap** by default: the largest element has the highest priority and is always at the top. Customize to a **min-heap** or custom order with a comparator.

```cpp
#include <queue>
```

## Creating

```cpp
std::priority_queue<int> pq(vec.begin(), vec.end());  // init from range

std::priority_queue<int> pq;  // max-heap (default)

std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

struct Compare {
  bool operator()(int a, int b) const {
    return a > b;  // min-heap behavior
  }
};
std::priority_queue<int, std::vector<int>, Compare> customPQ;
```

## Custom comparator

```cpp
struct MyComparator {
  bool operator()(int const& a, int const& b) const {
    // return a < b;  // max-heap style
    return a > b;  // min-heap style
  }
};

std::priority_queue<int, std::vector<int>, MyComparator> pq;
```

## Operations

```cpp
pq.push(10);   // insert
pq.pop();      // remove top (highest priority)
pq.top();      // peek top (does not remove)
pq.size();     // number of elements
pq.empty();    // true if empty
```

## Sample

```cpp
#include <iostream>
#include <queue>

int main() {
  std::priority_queue<int> pq;
  pq.push(5);
  pq.push(1);
  pq.push(10);

  std::cout << "Top: " << pq.top() << "\n";  // 10
  pq.pop();
  std::cout << "Top after pop: " << pq.top() << "\n";  // 5
  std::cout << "Size: " << pq.size() << "\n";  // 2

  while (!pq.empty()) {
    std::cout << pq.top() << " ";
    pq.pop();
  }
}
```

Output:

```
Top: 10
Top after pop: 5
Size: 2
5 1
```

## Notes

> **Default is max-heap:** For Dijkstra / “smallest first,” use `std::greater<T>` (or an equivalent comparator).

> **No decrease-key:** `priority_queue` does not support efficient arbitrary updates — use lazy deletion, a set, or an indexed heap when needed.

## References

1. [GeeksforGeeks – Priority Queue in C++ STL](https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/)
2. [cppreference – std::priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue)
