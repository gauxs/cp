# Quick Sort
Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways. 
1. Always pick first element as pivot.

2. Always pick last element as pivot.

3. Pick a random element as pivot.

4. Pick median as pivot.

The key process in quickSort is **partition()**. Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time. 

Following are some important observation on the algorithm:
1. Quick Sort is preferred over MergeSort for sorting Arrays.

2. MergeSort is preferred over QuickSort for Linked Lists.

3. QuickSort can be optimised so that it takes O(LogN) extra space(recursion i.e.stack frames) in **worst case scenario** [GeeksForGeeks - Quicksort Tail Call Optimization](https://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/)

### Algorithm Analysis
```
    N - Size of input

    Time complexity:    T(N) = T(N) + T(N-K-1) + θ(N)

    The first two terms are for two recursive calls, the last term is for the partition process. K is the number of elements which are smaller than pivot.
    The time taken by QuickSort depends upon the input array and partition strategy. Following are three cases:   
    1.  Worst:      T(N) = T(0) + T(N-1) + θ(N) ≈ θ(N^2)
    2.  Average:    T(N) = T(N/9) + T(9N/10) + θ(N) ≈ O(Nlog(N))     // To do average case analysis, we need to consider all possible permutation 
                                                                        // of array and calculate time taken by every permutation which doesn’t look easy. 
                                                                        // We can get an idea of average case by considering the case when partition 
                                                                        // puts O(N/9) elements in one set and O(9N/10) elements in other set. 
    3.  Best:       T(N) = 2T(N/2) + θ(N) ≈ θ(Nlog(N))

    Space complexity:   O(N)
    Inplace sorting:    Yes, it uses extra space only for storing recursive function calls but not for manipulating the input
    Stable sorting:     No
```

## References
1. [GeeksForGeeks - Quick Sort](https://www.geeksforgeeks.org/quick-sort/)
2. [GeeksForGeeks - Quicksort Tail Call Optimization](https://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/)