# Insertion Sort
The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part. Following are some observation on the algorithm:
1. Insertion sort is used when number of elements is small.

2. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

3. **Binary insertion sort**, we can reduce comparison by performing binary search on the sorted part of the array.

### Algorithm Analysis
```
    N - Size of input

    Time Complexity:   
    1.  Worst:      O(N^2)  // sorted in reverse order
    2.  Average:    O(N^2)
    3.  Best:       O(N)    // sorted in-order

    Space complexity:   O(1)
    Inplace sorting:    yes
    Stable sorting:     yes 
```

## References
1. [GeeksForGeeks - Insertion Sort](https://www.geeksforgeeks.org/insertion-sort/)
