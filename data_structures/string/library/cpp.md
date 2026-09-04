---
kind: library
lang: cpp
title: String - std::string
topic_id: data_structures/string
---

# String - `std::string`

```cpp
#include <string>
```

## Find

```cpp
std::string s = "Welcome to GfG!";
std::string sub = "hello";

int res = s.find(sub);
if (res != std::string::npos)
  std::cout << res;
else
  std::cout << sub << " NOT found.";
```

## Substring

```cpp
std::string s = "abcdef";
std::string part = s.substr(2, 3);  // "cde" - start 2, length 3
std::string tail = s.substr(2);     // from index 2 to end
```

## Insert / erase / replace

```cpp
std::string s = "hello";
s.insert(5, " world");
s.erase(5, 1);         // remove one char at index 5
s.replace(0, 5, "hi");
```

## Compare

```cpp
std::string a = "abc";
std::string b = "abd";
int cmp = a.compare(b);  // < 0 if a < b
bool eq = (a == b);
```

## Size and access

```cpp
s.size();
s.empty();
s.clear();
s.front();
s.back();
s.push_back('x');
s.pop_back();
```

## Conversions

```cpp
int n = std::stoi("42");
std::string digits = std::to_string(42);
```

## References

1. [cppreference - std::string](https://en.cppreference.com/w/cpp/string/basic_string)
2. [GeeksforGeeks - String in C++](https://www.geeksforgeeks.org/string-in-cpp-stl/)
