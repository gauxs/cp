# Sorting
A Sorting Algorithm is used to rearrange a given array or list elements according to a comparison operator on the elements. The comparison operator is used to decide the new order of element in the respective data structure.

### Comparison based sorting algorithms
<img src="https://github.com/gauxs/cp/blob/master/media/images/sorting_comparison.png?raw=true" width="800" height="400">

<br>

### Non-Comparison based sorting algorithms
<img src="https://github.com/gauxs/cp/blob/master/media/images/sorting_non_comparison.png?raw=true" width="800" height="400">

### In-place & Stable sorting algorithms
1. An in-place sorting algorithm uses constant space for producing the output (modifies the given array only). It sorts the list only by modifying the order of the elements within the list.

2. A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input array to be sorted. Any unstable sorting algorithm can be made stable via specific implementation [GeeksForGeeks - Making sorting stable](https://www.geeksforgeeks.org/stability-in-sorting-algorithms/)

<img src="https://github.com/gauxs/cp/blob/master/media/images/sorting_stable_inplace.png?raw=true" width="800" height="400">

<br>

### Internal & external sorting algorithms
When all data that needs to be sorted cannot be placed in-memory at a time, the sorting is called external sorting. External Sorting is used for massive amount of data. Merge Sort and its variations are typically used for external sorting. Some external storage like hard-disk, CD, etc is used for external sorting. When all data is placed in-memory, then sorting is called internal sorting.

### Practice
1. Practice questions - [Leetcode - Sorting](https://leetcode.com/tag/sorting/)
2. Good questions - 

## Reference
1. [GeeksForGeeks - Sorting](https://www.geeksforgeeks.org/sorting-algorithms/)
2. [Afteracademy - Comaprison of sorting algorithms](https://afteracademy.com/blog/comparison-of-sorting-algorithms)
3. [GeeksForGeeks - Making sorting stable](https://www.geeksforgeeks.org/stability-in-sorting-algorithms/)