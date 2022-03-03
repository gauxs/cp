# Binary Search
At each step, the algorithm compares the median value in the search space to the target value. Based on the comparison and because the sequence is sorted, it can then eliminate half of the search space. By doing this repeatedly, it will eventually be left with a search space consisting of a single element, the target value. Following are some important observation on the algorithm:
1. Just remember to always test your code on a two-element set where the predicate is false for the first element and true for the second.

2. Why mid is calculated using **mid = lo+(hi-lo)/2** instead of the usual **mid = (lo+hi)/2**. This is to avoid another potential rounding bug: in the first case, we want the division to always round down, towards the lower bound. But division truncates, so when lo+hi would be negative, it would start rounding towards the higher bound. Coding the calculation this way ensures that the number divided is always positive and hence always rounds as we want it to. Although the bug doesn’t surface when the search space consists only of positive integers or real numbers.

3. Another reason is, if we use **mid=(low+high)/2** it fails if the sum of low and high is greater than the maximum positive int value(2^31 – 1)

### Algorithm Analysis
```
    N - Size of input

    Time Complexity:   
    1.  Worst:          O(logN)
    2.  Average:        O(logN)
    3.  Best:           O(logN)

    Space Complexity:   O(1)
```

## References
1. [Topcoder - Binary Search](https://www.topcoder.com/thrive/articles/Binary%20Search)
