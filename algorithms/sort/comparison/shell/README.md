# Shell Sort
ShellSort is mainly a variation of Insertion Sort. In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved. The idea of shellSort is to allow exchange of far items.

In shellSort, we make the array **H-sorted** for a large value of **H**. We keep reducing the value of **H** until it becomes 1. An array is said to be **H-sorted** if all sublists of every **H’th** element is sorted.

### Algorithm Analysis
```
    N - Size of input

    Time complexity:
    1.  Worst:          O(N^2)      // sorted in reverse order
    2.  Average:        O(N^2)
    3.  Best:           O(N)        // sorted in-order

    Space complexity:   O(1)
    Inplace sorting:    yes
    Stable sorting:     yes
```

## References
1. [GeeksForGeeks - Shell Sort](https://www.geeksforgeeks.org/shellsort/)