---
kind: library
lang: cpp
title: Queue - std::queue
topic_id: data_structures/queue
---

# Queue - `std::queue`

## 📦 What is a `queue`?

A **First-In-First-Out (FIFO)** data structure where elements are inserted at the back and removed from the front - like a line at a ticket counter.

Implemented as a **container adaptor** (default container is `deque`, but can also use `list`).

```cpp
#include <queue>
```

---

## 🚀 1. Creating a Queue

```cpp
std::queue<int> q;                      // Empty queue of integers
std::queue<std::string> qs;            // Queue of strings
std::queue<int, std::list<int>> ql;    // Queue using list as underlying container
```

---

## ➕ 2. Inserting and Removing Elements

```cpp
q.push(10);    // Insert at back
q.push(20);

q.pop();       // Remove element from front (10 removed)
```

---

## 👀 3. Accessing Elements

```cpp
q.front();     // Access front element (first-in)
q.back();      // Access back element (last-in)
```

---

## 📏 4. Size and Capacity

```cpp
q.size();      // Number of elements
q.empty();     // Returns true if queue is empty
```

---

## 🧪 Sample Example

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Front: " << q.front() << endl; // 1
    cout << "Back: " << q.back() << endl;   // 3
    q.pop();  // Removes 1

    cout << "Front after pop: " << q.front() << endl; // 2
    cout << "Size: " << q.size() << endl; // 2

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
```

Output:
```
Front: 1
Back: 3
Front after pop: 2
Size: 2
2 3
```

---

## 🧠 Common Use Cases

- Task scheduling
- Breadth-First Search (BFS)
- Request handling systems
- Caching strategies (FIFO)

---

## 📚 References

- [GeeksforGeeks – Queue in C++ STL](https://www.geeksforgeeks.org/queue-cpp-stl/)
- [cppreference.com – std::queue](https://en.cppreference.com/w/cpp/container/queue)
