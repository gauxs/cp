---
kind: theory
title: Mathematics
topic_id: algorithms/math
---

# Mathematics

## Overview

Mathematical interview problems usually become straightforward after identifying the relevant number-theory structure: primes, divisibility, greatest common divisors, or factor counts.

## Key Observations

1. The Sieve of Eratosthenes finds all primes in the range $[1,N]$ by marking multiples of each discovered prime.
2. Euclid's algorithm repeatedly replaces $(a,b)$ with $(b,a \bmod b)$ until the remainder is zero.
3. Factorial trailing zeroes come from matched factors of $2$ and $5$; factors of $5$ are scarcer.
4. Prime factorization is often more useful than testing every candidate divisor independently.

## Notes

> **Geometric-loop analysis:** A nested loop whose inner work is $N, N/2, N/4, \ldots$ still performs $O(N)$ total work because the geometric series is bounded by $2N$.

<details>
<summary>Worked example</summary>

```cpp
int count = 0;
for (int i = N; i > 0; i /= 2) {
    for (int j = 0; j < i; ++j) {
        ++count;
    }
}
```

The work is

$$
N + \frac{N}{2} + \frac{N}{4} + \cdots
= N\left(1 + \frac{1}{2} + \frac{1}{4} + \cdots\right)
< 2N,
$$

so the total time complexity is $O(N)$.

</details>

## Algorithm Analysis

| Technique | Time | Space |
| --- | --- | --- |
| Sieve of Eratosthenes through $N$ | $O(N \log \log N)$ | $O(N)$ |
| Euclid's algorithm | $O(\log \min(a,b))$ | $O(1)$ |
| Trial-division factorization | $O(\sqrt{N})$ | $O(1)$ |

## References

1. [CP-Algorithms - Sieve of Eratosthenes](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html)
2. [CP-Algorithms - Euclidean Algorithm](https://cp-algorithms.com/algebra/euclid-algorithm.html)
3. [Wikipedia - Infinite geometric series](https://en.wikipedia.org/wiki/Geometric_series)