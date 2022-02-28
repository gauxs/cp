# Selection Sort
Sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. Following are some important observation on the algorithm:
1. The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation. 

### Algorithm Analysis
```
    N - Size of input

    Time complexity:
    1. Worst:           O(N^2)
    2. Average:         O(N^2)
    3. Best:            O(N^2)

    Space complexity:   O(1)
    Inplace sorting:    yes
    Stable sorting:     No, but can be made stable
```

### Stable
Selection sort can be made Stable if instead of swapping, the minimum element is placed in its position without swapping i.e. by placing the number in its position by pushing every element one step forward. Example: 4A 5 3 2 4B 1 | First minimum element is 1, now instead of swapping. Insert 1 in its correct place and pushing every element one step forward i.e forward pushing.

## References
1. [GeeksForGeeks - Selection Sort](https://www.geeksforgeeks.org/selection-sort/)