---
kind: theory
title: Bit Manipulation
topic_id: algorithms/bit_manipulation
---

# Bit Manipulation

## Overview

Bit manipulation uses shifts, masks, XOR, and bit-clearing identities to operate directly on a value's binary representation.

## Key Observations

1. XOR cancels equal values and has zero as its identity.
2. `x & (x - 1)` clears the lowest set bit.
3. Unsigned values avoid implementation-specific behavior during logical shifts.
4. Test, set, clear, and toggle a bit with a mask shifted to its position.

## Algorithm Analysis

Operations on a machine word take $O(1)$ time. Scanning every bit takes $O(B)$ for a $B$-bit representation.

## References

1. [CP-Algorithms - Bit Manipulation](https://cp-algorithms.com/algebra/bit-manipulation.html)
