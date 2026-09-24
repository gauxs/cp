---
kind: library
lang: cpp
title: Deque - std::deque
topic_id: data_structures/deque
---

# Deque - `std::deque`

## 🧱 What is a `deque`?

A **double-ended queue (deque)** is a sequence container that allows fast insertion and deletion at both the **front and back**.

- Pronounced as **"deck"**
- Implemented as a **dynamic array of fixed-size arrays**
- Allows random access
- Unlike `vector`, insertion/deletion at the front is efficient

```cpp
#include <deque>
```

---

## 🚀 Creating a Deque

```cpp
std::deque<int> dq;                    // Empty deque
std::deque<int> dq(5, 10);             // 5 elements of value 10
std::deque<int> dq2 = {1, 2, 3};       // Initializer list
```

---

## ➕ Inserting Elements

```cpp
dq.push_back(1);       // Add at end
dq.push_front(2);      // Add at beginning
dq.insert(dq.begin()+1, 3); // Insert at position
```

---

## ➖ Deleting Elements

```cpp
dq.pop_back();         // Remove from end
dq.pop_front();        // Remove from front
dq.erase(dq.begin());  // Erase by position
dq.clear();            // Remove all elements
```

---

## 👀 Accessing Elements

```cpp
int x = dq[0];         // Access using operator[]
int y = dq.at(1);      // Bounds-checked access
int f = dq.front();    // First element
int l = dq.back();     // Last element
```

---

## 🔁 Iterating Over a Deque

```cpp
for (int i : dq)
    std::cout << i << " ";

for (auto it = dq.begin(); it != dq.end(); ++it)
    std::cout << *it << " ";
```

---

## 📏 Size and Capacity

```cpp
dq.size();      // Number of elements
dq.empty();     // True if empty
```

---

## 🔄 Assign, Swap

```cpp
dq.assign(5, 100);         // Assign 5 elements of value 100
dq.swap(dq2);              // Swap with another deque
```

---

## 🧪 Sample Code

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);

    cout << "Deque contents: ";
    for (int val : dq)
        cout << val << " ";
    cout << endl;

    dq.pop_front();
    dq.pop_back();

    cout << "After pops: ";
    for (int val : dq)
        cout << val << " ";
    cout << endl;

    return 0;
}
```

Output:
```
Deque contents: 20 10 30 
After pops: 10 
```

---

## 🧠 Common Use Cases

- Sliding window problems
- Palindrome checking
- LRU cache implementation
- Task scheduling

---

## 🆚 `deque` vs `vector`

| Feature              | `deque`           | `vector`         |
|----------------------|------------------|------------------|
| Random access        | ✅ Yes           | ✅ Yes           |
| Push/pop at front    | ✅ Efficient     | ❌ Inefficient   |
| Push/pop at back     | ✅ Efficient     | ✅ Efficient     |
| Memory locality      | ❌ Less optimal  | ✅ Better        |
| Performance (front)  | ✅ Better        | ❌ Poor          |

---

## 📚 References

- [GeeksforGeeks – Deque in C++ STL](https://www.geeksforgeeks.org/deque-cpp-stl/)
- [cppreference.com – std::deque](https://en.cppreference.com/w/cpp/container/deque)
