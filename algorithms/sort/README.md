# Sorting
A Sorting Algorithm is used to rearrange a given array or list elements according to a comparison operator on the elements. The comparison operator is used to decide the new order of element in the respective data structure.

Two main category of sorting algorithm are:
1. Non-comparison based e.g. radix sort
2. Comparison based e.g. merge sort

<img src="https://github.com/gauxs/cp/blob/master/media/images/sorting_comparison.png?raw=true" width="600" height="400">

<img src="https://github.com/gauxs/cp/blob/master/media/images/sorting_non_comparison.png?raw=true" width="600" height="400">

Terminologies used in sorting algorithms:
1. In-place sorting - An in-place sorting algorithm uses constant space for producing the output (modifies the given array only). It sorts the list only by modifying the order of the elements within the list.

2. Internal & external sorting - When all data that needs to be sorted cannot be placed in-memory at a time, the sorting is called external sorting. External Sorting is used for massive amount of data. Merge Sort and its variations are typically used for external sorting. Some external storage like hard-disk, CD, etc is used for external sorting.
When all data is placed in-memory, then sorting is called internal sorting.

3. Stable sorting - A sorting algorithm is said to be stable if two objects with equal keys appear in the same order in sorted output as they appear in the input array to be sorted.

## Reference
1. [GeeksForGeeks - Sorting](https://www.geeksforgeeks.org/sorting-algorithms/)