# 📚 C++ std::priority_queue

## 🧱 What is a `priority_queue`?

A **max-heap** by default: the largest element has the highest priority and is always at the top.

Can be customized to behave as a **min-heap** or to follow custom comparison logic using function objects or lambdas.

```cpp
#include <queue>
```

---

## 🚀 1. Creating a Priority Queue

```cpp
std::priority_queue<int> pq(vec.begin(), vec.end());     // init with existing vector

std::priority_queue<int> pq; // Max-heap (default)

std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Min-heap

// Custom comparator
struct Compare {
    bool operator()(int a, int b) {
        return a > b; // Min-heap behavior
    }
};
std::priority_queue<int, std::vector<int>, Compare> customPQ;
```

---

## 2. User Defined Comparator

```cpp
struct mycomparator{
    bool operator()(int const&a, int const&b){
        return a<b; // max-heap
        return a>b; // min-heap
    }
}

priority_queue<int, vector<int>, mycomparator> pq;
```

## ➕ 3. Inserting Elements

```cpp
pq.push(10);
pq.push(30);
pq.push(20);
// Elements are automatically sorted based on priority
```

---

## ➖ 4. Removing Elements

```cpp
pq.pop(); // Removes the element with the highest priority (top element)
```

---

## 👀 5. Accessing the Top Element

```cpp
pq.top(); // Returns the element with the highest priority
```

---

## 📏 6. Size and Capacity

```cpp
pq.size();  // Number of elements in the queue
pq.empty(); // Returns true if queue is empty
```

---

## 🧪 Sample Example

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(5);
    pq.push(1);
    pq.push(10);

    cout << "Top element: " << pq.top() << endl; // 10
    pq.pop();
    cout << "Top after pop: " << pq.top() << endl; // 5
    cout << "Size: " << pq.size() << endl; // 2

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
```

Output:
```
Top element: 10
Top after pop: 5
Size: 2
5 1
```

---

## 🧠 Common Use Cases

- Dijkstra’s algorithm (min-heap)
- A* pathfinding
- CPU/job/task scheduling
- K largest/smallest elements

---

## 📚 References

- [GeeksforGeeks – Priority Queue in C++ STL](https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/)
- [cppreference.com – std::priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue)