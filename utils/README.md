# Expression Parsing
In comparison, testing of reverse Polish notation with algebraic notation, ***reverse Polish has been found to lead to faster calculations***, for two reasons. 
1. The first reason is that reverse Polish calculators do not need expressions to be parenthesized, so fewer operations need to be entered to perform typical calculations.
2. Additionally, users of reverse Polish calculators made fewer mistakes than for other types of calculators.

***Left-associative*** means if the priorities are equal, they get executed from left to right. ***Binary operators*** have left associativity and ***unary operator*** have right associativity.


## Algorithm Analysis
```
N - expression string length

Time Complexity:         O(N)
Space Complexity:        O(N)
```

## References
- [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
- https://cp-algorithms.com/string/expression_parsing.html

## Warmup Problems
1. https://leetcode.com/problems/evaluate-reverse-polish-notation/ - In this question there are no brackets which is expected, whereas in code implementation we are converting polish notation expression to reverse polish notation.

## Quality Problems
1. 

# Something