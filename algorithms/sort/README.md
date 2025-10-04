# Sorting
A Sorting Algorithm is used to rearrange a given array or list elements according to a comparison operator on the elements. The comparison operator is used to decide the new order of element in the respective data structure.

## Algorithm Characteristics

### In-place & Stable sorting algorithms
1. **In-place sorting algorithm**: Uses constant space for producing the output (modifies the given array only). It sorts the list only by modifying the order of the elements within the list.

2. **Stable sorting algorithm**: Two objects with equal keys appear in the same order in sorted output as they appear in the input array to be sorted. Any unstable sorting algorithm can be made stable via specific implementation [GeeksForGeeks - Making sorting stable](https://www.geeksforgeeks.org/stability-in-sorting-algorithms/)

## Comparison based sorting algorithms

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity | Stable | In-place | Notes |
|-----------|-----------|--------------|------------|------------------|--------|----------|-------|
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ | ✅ | Simple but inefficient |
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | ❌ | ✅ | Always O(n²) comparisons |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ | ✅ | Efficient for small datasets |
| **Merge Sort** | O(n log n) | O(n log n) | O(n log n) | O(n) | ✅ | ❌ | Divide and conquer, good for external sorting |
| **Quick Sort** | O(n log n) | O(n log n) | O(n²) | O(log n) | ❌ | ✅ | Average case is efficient, worst case rare |
| **Heap Sort** | O(n log n) | O(n log n) | O(n log n) | O(1) | ❌ | ✅ | Guaranteed O(n log n) performance |
| **Shell Sort** | O(n log n) | O(n^1.3) | O(n²) | O(1) | ❌ | ✅ | Improved insertion sort with gaps |

## Non-Comparison based sorting algorithms

| Algorithm | Best Case | Average Case | Worst Case | Space Complexity | Stable | In-place | Notes |
|-----------|-----------|--------------|------------|------------------|--------|----------|-------|
| **Counting Sort** | O(n + k) | O(n + k) | O(n + k) | O(k) | ✅ | ❌ | k = range of input values |
| **Radix Sort** | O(d × (n + k)) | O(d × (n + k)) | O(d × (n + k)) | O(n + k) | ✅ | ❌ | d = number of digits, k = base |
| **Bucket Sort** | O(n + k) | O(n + k) | O(n²) | O(n + k) | ✅ | ❌ | k = number of buckets |

## Complexity Analysis Summary

### Time Complexity Comparison
- **Best for small datasets**: Insertion Sort (O(n) best case)
- **Best average performance**: Quick Sort (O(n log n) average)
- **Most consistent**: Merge Sort (O(n log n) guaranteed)
- **Best for large datasets**: Heap Sort (O(n log n) guaranteed, in-place)
- **Best for specific ranges**: Counting/Radix Sort (O(n + k))

### Space Complexity Comparison
- **Most space efficient**: Bubble, Selection, Insertion, Heap, Shell Sort (O(1))
- **Moderate space usage**: Quick Sort (O(log n) for recursion)
- **Higher space usage**: Merge Sort (O(n)), Non-comparison sorts (O(n + k))

## Internal & External sorting algorithms
When all data that needs to be sorted cannot be placed in-memory at a time, the sorting is called external sorting. External Sorting is used for massive amount of data. Merge Sort and its variations are typically used for external sorting. Some external storage like hard-disk, CD, etc is used for external sorting. When all data is placed in-memory, then sorting is called internal sorting.

## When to Use Which Algorithm?

| Scenario | Recommended Algorithm | Reason |
|----------|----------------------|--------|
| Small datasets (< 50 elements) | Insertion Sort | Simple, efficient for small data |
| General purpose | Quick Sort | Fast average case performance |
| Guaranteed O(n log n) | Merge Sort or Heap Sort | Consistent performance |
| Memory constrained | Heap Sort | In-place with guaranteed performance |
| Nearly sorted data | Insertion Sort | Takes advantage of existing order |
| Integer data with small range | Counting Sort | Linear time for specific cases |
| Large integer data | Radix Sort | Linear time for large datasets |
| External sorting | Merge Sort | Good for disk-based sorting |

## Practice
1. Practice questions - [Leetcode - Sorting](https://leetcode.com/tag/sorting/)
2. Good questions - [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/) | [Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/) | [Increasing Triplet Subsequence](https://leetcode.com/problems/increasing-triplet-subsequence/) | [Wiggle Sort-II](https://leetcode.com/problems/wiggle-sort-ii/)

## Reference
1. [GeeksForGeeks - Sorting](https://www.geeksforgeeks.org/sorting-algorithms/)
2. [Afteracademy - Comparison of sorting algorithms](https://afteracademy.com/blog/comparison-of-sorting-algorithms)
3. [GeeksForGeeks - Making sorting stable](https://www.geeksforgeeks.org/stability-in-sorting-algorithms/)