# Sorting - Comparison Based
## Merge Sort
Its's a ***Divide and Conquer*** algorithm. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves. 

The merge_array() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. 

### Algorithm Analysis
```
Stable Sorting:         yes
Inplace Sorting:        No
Recurrence Equation:    T(n) = 2T(n/2) + θ(n)

Time Complexity:   
    1. Worst:   O(n * log(n))
    2. Average: O(n * log(n))
    3. Best:    O(n * log(n))

Space Complexity:   O(n)
```

### Applications and Drawbacks:
1.  Slower comparative to the other sort algorithms for smaller tasks.
2.  Merge sort algorithm requires additional memory space of 0(n) for the temporary array .
3.  It goes through the whole process even if the array is sorted.

### References
- https://www.geeksforgeeks.org/merge-sort/

### Interesting Problems
1. https://leetcode.com/problems/sort-list/


## Patience Sort
Not sure what this algorithm is but i found a [question](https://leetcode.com/problems/longest-increasing-subsequence/) which gets solved using dp in O(N^2) but using ideas from this algorithm reduces to O(NlogN).

### References
- https://en.wikipedia.org/wiki/Patience_sorting
- 

### Quality Problems
1. https://leetcode.com/problems/longest-increasing-subsequence/ - [Reference](https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/)
2. https://leetcode.com/problems/largest-divisible-subset/
3. https://leetcode.com/problems/increasing-triplet-subsequence/