# Z Algorithm

Z-function for a string is an array of length n where the i-th element is equal to the greatest number of characters starting from the position i that coincide with the first characters of s.

In other words, z[i] is the length of the longest string that is, at the same time, a prefix of s and a prefix of the suffix of s starting at i. Note that the first element of Z-function, z[0], is generally not well defined, we will assume it is zero.

For example, here are the values of the Z-function computed for different strings:

- "aaaaa" - [0,4,3,2,1]
- "aaabaab" - [0,2,1,0,2,1,0]
- "abacaba" - [0,0,1,0,3,0,1]

### Algorithm Analysis

```
    N is length of the string

    Time complexity:  O(N)
    Space complexity: O(N)
```

### Practice

1. Practice questions - [Leetcode - Sum of Scores of Built Strings](https://leetcode.com/problems/sum-of-scores-of-built-strings/)
2. Good questions -

## References

1. [CP Algorithms - Z algorithm](https://cp-algorithms.com/string/z-function.html)
