# 📚 C++ std::map

## 🧱 What is a `map`?

A `std::map` is an **associative container** that stores elements in key-value pairs, automatically **sorted by key** (ascending by default). Keys are **unique**.

Implemented internally as a **Red-Black Tree**, giving O(log n) time for insertion, deletion, and search.

```cpp
#include <map>
```

---

## 🧾 Ordered vs Unordered Map

### ✅ Ordered Map (`std::map`)
- Keys are stored in sorted order.
- Slower (O(log n) operations).
```cpp
#include <map>
std::map<int, std::string> orderedMap;

orderedMap[3] = "three";
orderedMap[1] = "one";
orderedMap[2] = "two";

for (auto& [key, val] : orderedMap)
    std::cout << key << ": " << val << "\n";

// Output:
// 1: one
// 2: two
// 3: three
```

---

### ⚡ Unordered Map (`std::unordered_map`)
- Keys are stored in no specific order.
- Faster average-case performance (O(1) operations).
```cpp
#include <unordered_map>
std::unordered_map<int, std::string> unorderedMap;

unorderedMap[3] = "three";
unorderedMap[1] = "one";
unorderedMap[2] = "two";

for (auto& [key, val] : unorderedMap)
    std::cout << key << ": " << val << "\n";

// Output may vary in order
```

---

## 🚀 Creating a Map

```cpp
std::map<int, std::string> m;
```

---

## ➕ Inserting Elements

```cpp
m[1] = "apple";               // Inserts or updates key 1
m.insert({2, "banana"});      // Insert using pair
m.emplace(3, "cherry");       // More efficient insertion
```

---

## ➖ Erasing Elements

```cpp
m.erase(2);                  // Remove key 2
m.erase(m.begin());          // Erase by iterator
```

---

## 👀 Accessing Elements

```cpp
std::cout << m[1];           // Access value at key 1 (inserts default if not found)
std::cout << m.at(1);        // Access value at key 1 (throws if not found)
```

---

## 🔍 Finding and Checking

```cpp
map<int, int> m;
auto it = m.find(2)

if (it != mp.end()) {
    cout << "Key '" << it->first << "' found with";
    cout << " value: " << it->second << endl;
}

if (m.count(3)) {
    std::cout << "Key 3 exists";
}
```

---

## 🔁 Iterating Over a Map

```cpp
for (auto& [key, value] : m) {
    std::cout << key << " => " << value << std::endl;
}
```

---

## 📏 Size and Utilities

```cpp
m.size();    // Returns number of elements
m.empty();   // True if map is empty
m.clear();   // Removes all elements
```

---

## 🧪 Sample Code

```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> m;
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";

    cout << "Element at key 2: " << m[2] << endl;

    if (m.count(3))
        cout << "Key 3 found" << endl;

    m.erase(1);

    for (auto& [key, val] : m) {
        cout << key << " -> " << val << endl;
    }

    return 0;
}
```

Output:
```
Element at key 2: two
Key 3 found
2 -> two
3 -> three
```

---

## 🧠 Common Use Cases

- Counting frequencies (e.g., word or number frequencies)
- Sorted dictionary operations
- Configurations/settings with sorted access
- Ordered key-value storage

---

## 🆚 Map vs Unordered Map

| Feature             | `map` (Ordered)   | `unordered_map`      |
|---------------------|------------------|-----------------------|
| Order               | Sorted by key     | No order              |
| Time Complexity     | O(log n)          | Avg O(1), worst O(n)  |
| Implementation      | Red-Black Tree    | Hash Table            |
| Custom key sort     | ✅ Supported      | ❌ Not supported      |
| Predictable order   | ✅ Yes            | ❌ No                 |

---

## 📚 References

- [GeeksforGeeks – Map in C++ STL](https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/)
- [cppreference.com – std::map](https://en.cppreference.com/w/cpp/container/map)