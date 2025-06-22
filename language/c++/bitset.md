# C++ std::bitset

In C++, `std::bitset` is a container that represents a fixed-size sequence of bits. It allows for efficient manipulation of individual bits, making it useful in problems involving bitwise operations, such as managing flags or representing binary numbers.

`std::bitset` is defined in the `<bitset>` header file.

## Creating a Bitset

The syntax to create a bitset is:

```cpp
#include <bitset>

std::bitset<N> my_bitset;
```

Where `N` is a compile-time constant representing the number of bits.

## Initialization

By default, all bits in a new bitset are initialized to `0`.

```cpp
#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> b; // all 8 bits are 0
    std::cout << b << std::endl; // 00000000
    return 0;
}
```

### From an integer value

You can initialize a bitset with the binary representation of an unsigned long long integer.

```cpp
#include <iostream>
#include <bitset>

int main() {
    // 18 in binary is 10010
    std::bitset<8> b(18); 
    std::cout << b << std::endl; // 00010010
    return 0;
}
```

### From a string

A bitset can also be initialized from a `std::string` containing binary digits (`0`s and `1`s).

```cpp
#include <iostream>
#include <bitset>
#include <string>

int main() {
    std::string binary_string = "101010";
    std::bitset<8> b(binary_string);
    std::cout << b << std::endl; // 00101010
    return 0;
}
```
The string must only contain `'0'` or `'1'`, otherwise, an `std::invalid_argument` exception is thrown.

## Accessing Individual Bits

You can access individual bits using the `[]` operator or the `test()` member function.

- `operator[]`: Accesses the bit at a specific position (`pos`).
- `test(pos)`: Returns `true` if the bit at `pos` is set (1), and `false` otherwise.

The position `pos` is 0-indexed from the right.

```cpp
#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> b(18); // 00010010

    // Access using []
    std::cout << "Bit at position 1: " << b[1] << std::endl; // 1
    std::cout << "Bit at position 2: " << b[2] << std::endl; // 0

    // Access using test()
    if (b.test(4)) { // 10010 -> bit 4 is 1
        std::cout << "Bit at position 4 is set." << std::endl;
    }

    return 0;
}
```

## Modifying Bits

### `set()`, `reset()`, `flip()`

- `set()`: Sets all bits to `1`.
- `set(pos, value = true)`: Sets the bit at position `pos` to `1` (or to `value`).
- `reset()`: Resets all bits to `0`.
- `reset(pos)`: Resets the bit at position `pos` to `0`.
- `flip()`: Flips all bits.
- `flip(pos)`: Flips the bit at position `pos`.

```cpp
#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> b(18); // 00010010
    std::cout << "Original: " << b << std::endl;

    b.set(0); // Set bit at position 0
    std::cout << "After set(0): " << b << std::endl; // 00010011

    b.reset(4); // Reset bit at position 4
    std::cout << "After reset(4): " << b << std::endl; // 00000011
    
    b.flip(1); // Flip bit at position 1
    std::cout << "After flip(1): " << b << std::endl; // 00000001

    b.flip(); // Flip all bits
    std::cout << "After flip(): " << b << std::endl; // 11111110

    return 0;
}
```

## Bitwise Operators

`std::bitset` overloads bitwise operators for easy manipulation.

| Operator | Operation              |
| -------- | ---------------------- |
| `&`      | Bitwise AND            |
| `|`      | Bitwise OR             |
| `^`      | Bitwise XOR            |
| `~`      | Bitwise NOT            |
| `<<=`    | Left shift and assign  |
| `>>=`    | Right shift and assign |
| `&=`     | AND and assign         |
| `|=`     | OR and assign          |
| `^=`     | XOR and assign         |

```cpp
#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> b1(18); // 00010010
    std::bitset<8> b2(5);  // 00000101

    std::cout << "b1: " << b1 << std::endl;
    std::cout << "b2: " << b2 << std::endl;

    // AND
    std::cout << "b1 & b2: " << (b1 & b2) << std::endl; // 00000000

    // OR
    std::cout << "b1 | b2: " << (b1 | b2) << std::endl; // 00010111

    // XOR
    std::cout << "b1 ^ b2: " << (b1 ^ b2) << std::endl; // 00010111

    // NOT
    std::cout << "~b1:     " << (~b1) << std::endl;     // 11101101

    return 0;
}
```

## Member Functions

| Function      | Description                               |
|---------------|-------------------------------------------|
| `any()`       | Returns `true` if at least one bit is set.  |
| `none()`      | Returns `true` if no bits are set.        |
| `all()`       | Returns `true` if all bits are set.         |
| `count()`     | Returns the number of set bits.           |
| `size()`      | Returns the number of bits in the bitset.   |
| `to_string()` | Converts the bitset to a `std::string`.     |
| `to_ulong()`  | Converts the bitset to an `unsigned long`.  |
| `to_ullong()` | Converts the bitset to an `unsigned long long`. |

## `bitset` vs `vector<bool>` vs `bool[]`

| Parameter  | `std::bitset`                                     | `std::vector<bool>`                             | `bool[]`                                 |
|------------|---------------------------------------------------|-------------------------------------------------|------------------------------------------|
| **Size**   | Fixed at compile-time.                            | Dynamic size.                                   | Fixed size.                              |
| **Memory** | Memory-optimized, each `bool` takes 1 bit.        | Memory-optimized, each `bool` takes 1 bit.      | Each `bool` usually takes 1 byte.        |
| **Speed**  | Generally fast due to bitwise operations.         | Can be slower due to proxy objects for access.  | Faster element access.                   |


## Why use `std::bitset`?

- **Memory Efficiency**: Ideal for large sequences of bits as each bit takes only one bit of memory.
- **Performance**: Offers fast bitwise manipulation capabilities.
- **Convenience**: Provides a user-friendly interface for bit-level operations, improving code readability and reducing complexity.
- **Fixed Size**: Predictable memory usage since the size is known at compile-time.
