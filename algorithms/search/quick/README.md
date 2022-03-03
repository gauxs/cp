# Quick Select/Search
Quickselect is a selection algorithm to find the k-th smallest element in an unordered list. It is related to the quick sort sorting algorithm. The algorithm is similar to QuickSort. The difference is, instead of recurring for both sides (after finding pivot), it recurs only for the part that contains the k-th smallest element. Following are some important observation on the algorithm:
1. The partition process is same as QuickSort, only recursive code differs.

2. Like quicksort, it is fast in practice, but has poor worst-case performance.

3. There exists an algorithm that finds [k-th smallest element in O(n)](https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/) in worst case, but QuickSelect performs better on average. 

### Algorithm Analysis
```
    N - Size of input

    Time Complexity:   
    1.  Worst:          O(N^2)
    2.  Average:        O(N)
    3.  Best:           O(1)

    Space Complexity:   O(1)
```

### Practice
1. Practice questions - 
2. Good questions - [Wiggle Sort-II](https://leetcode.com/problems/wiggle-sort-ii/)


## References
1. [GeeksForGeeks - Quick Select](https://www.geeksforgeeks.org/quickselect-algorithm/)
2. [k-th smallest element in O(n)](https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array-set-3-worst-case-linear-time/)
