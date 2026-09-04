---
kind: library
lang: cpp
title: Stack - std::stack
topic_id: data_structures/stack
---

# Stack - `std::stack`

## 🧱 What is a `stack`?

A **Last-In-First-Out (LIFO)** data structure, where the last element inserted is the first to be removed. Think of it like a stack of plates – you push on top, and pop from the top.

Implemented as a container adaptor (defaults to `deque`, but can be used with `vector`, `list` etc.)

```cpp
#include <stack>
```

---

## 📦 1. Creating a Stack

```cpp
std::stack<int> s;                     // Empty stack of integers
std::stack<std::string> st;           // Stack of strings
std::stack<int, std::vector<int>> vs; // Stack using vector as underlying container
```

---

## 🚀 2. Pushing and Popping Elements

```cpp
s.push(10);     // Push element to top
s.push(20);

s.pop();        // Remove top element (20 removed)
```

---

## 👀 3. Accessing Top Element

```cpp
int topElem = s.top();   // Access the top (most recent) element
```

---

## 📏 4. Size and Capacity

```cpp
s.size();       // Number of elements
s.empty();      // Returns true if stack is empty
```

---

## 🧪 Sample Example

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top element: " << s.top() << endl; // 3
    s.pop();
    cout << "Top after pop: " << s.top() << endl; // 2
    cout << "Size: " << s.size() << endl; // 2

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
```

Output:
```
Top element: 3
Top after pop: 2
Size: 2
2 1
```

---

## 🧠 Common Use Cases

- Expression evaluation
- Syntax parsing
- Undo features
- Backtracking problems (e.g., maze solving, DFS)

---

## 📚 References

- [GeeksforGeeks – Stack in C++ STL](https://www.geeksforgeeks.org/stack-in-cpp-stl/)
- [cppreference.com – std::stack](https://en.cppreference.com/w/cpp/container/stack)
