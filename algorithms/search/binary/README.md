# Binary Search
Important observation on this algorithm:
1. To avoid infinite loops cases, always test your code on a two-element set where the predicate is false for the first element and true for the second.
2. Why mid is calculated using mid = lo + (hi-lo)/2 instead of the usual mid = (lo+hi)/2? This is to avoid another potential rounding bug: in the first case, we want the division to always round down, towards the lower bound. But division truncates, so when lo+hi would be negative, it would start rounding towards the higher bound. Coding the calculation this way ensures that the number divided is always positive and hence always rounds as we want it to.

## References
1. [Topcoder - Binary Search](https://www.topcoder.com/thrive/articles/Binary%20Search)
