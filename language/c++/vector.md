# C++ STL

## 1. Creating a Vector
```cpp
std::vector<int> v;                  // Empty vector
std::vector<int> v(5);               // 5 elements, default-initialized (0)
std::vector<int> v(5, 10);           // 5 elements, all 10
std::vector<int> v = {1, 2, 3};      // Initialize using initializer list
```

## 2. Accessing Elements
``` cpp
int x = v[2];            // No bounds check
int y = v.at(2);         // With bounds check

int first = v.front();   // First element
int last = v.back();     // Last element

int* arr = v.data();     // Pointer to underlying array
```

## 3. Size and Capacity
``` cpp
v.size();            // Current size
v.capacity();        // Current capacity
v.empty();           // Check if vector is empty

v.resize(10);        // Resize to 10 elements (default-initialized)
v.resize(10, 5);     // Resize with value 5

v.reserve(20);       // Pre-allocate capacity
v.shrink_to_fit();   // Reduce capacity to match size
```

## 4. Modifiers
``` cpp
v.push_back(10);               // Add at end
v.insert(v.begin() + 1, 15);   // Insert at index 1
v.emplace(v.begin() + 2, 99);  // In-place insert
v.emplace_back(100);          // In-place insert at end


v.pop_back();                  // Remove last element
v.erase(v.begin() + 2);        // Remove third element
v.clear();                     // Remove all elements

v.assign(5, 8);                // Replace with five 8s
v.assign({1, 2, 3});           // Replace with initializer list

std::vector<int> v2 = {7, 8};
v.swap(v2);                    // Swap contents
```

## 5. Iterators

``` cpp
auto it = v.begin();           // Start iterator
auto it_end = v.end();         // End iterator

auto rit = v.rbegin();         // Reverse start
auto rit_end = v.rend();       // Reverse end

auto cit = v.cbegin();         // Const start
auto crit = v.crbegin();       // Const reverse start
```

## 6. Reverse a vector

```cp
reverse(v.begin(), v.end());
```
## 📚 References

1. [GeeksforGeeks – Vector in C++ STL](https://www.geeksforgeeks.org/vector-in-cpp-stl/)
2. [cppreference.com – std::vector](https://en.cppreference.com/w/cpp/container/vector.html)