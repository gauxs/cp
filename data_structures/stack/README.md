---
kind: theory
title: Stack
topic_id: data_structures/stack
---

# Stack

## Overview

Last-in-first-out (LIFO) container adaptor. Used for parsing, monotonic stacks, DFS, and backtracking.

In C++ the standard-library type is **`std::stack`**. See the **Library** tab for API quick reference.

## Key Observations

1. Nested structures resolve from the inside out, which directly matches LIFO order.
2. Reverse Polish notation encodes evaluation order without parentheses.
3. Binary operators are usually left-associative; unary operators are commonly right-associative.
4. Operand order matters when reducing subtraction and division from a stack.

> **Related topic:** Monotonic-stack problems have their primary home under **Monotonic Stack and Queue**.

## Algorithm Analysis

A single-pass parser usually takes $O(N)$ time and $O(N)$ space for an input of length $N$.

## References

1. [cppreference](https://en.cppreference.com/w/)
2. [CP-Algorithms - Expression Parsing](https://cp-algorithms.com/string/expression_parsing.html)
3. [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
