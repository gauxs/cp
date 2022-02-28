# Merge Sort
Merge Sort is a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. The merge() function is used for merging two halves.

### Algorithm Analysis
```
    N - Size of input

    Time Complexity:   
    1.  Worst:      θ(NLogN)
    2.  Average:    θ(NLogN)
    3.  Best:       θ(NLogN)

    Space complexity:   O(N)
    Inplace sorting:    No
    Stable sorting:     yes 
```

### Applications and Drawbacks:
1. Slower comparative to the other sort algorithms for smaller tasks.
2. Merge sort algorithm requires additional memory space of 0(N) for the temporary array .
3. It goes through the whole process even if the array is sorted.

### Practice
1. Good questions - [Sort List](https://leetcode.com/problems/sort-list/)

## References
1. [GeeksForGeeks - Merge Sort](https://www.geeksforgeeks.org/merge-sort/)
