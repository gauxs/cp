# Bubble Sort
This algorithm works by repeatedly swapping the adjacent elements if they are in wrong order. Following are some important observation on the algorithm:
1. One pass gives an impression of bringing the largest(smallest if sorting in decreasing order) element towards the end of the list(if we traverse from 0).
2. After first pass we know that last index element is at right place.
3. In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n). 

### Algorithm Analysis
```
    V - number of vertices
    E - number of edges

    Time complexity:    O(V+E)
    Space complexity:   O(V)   
```

### Practice
1. Practice questions - [Leetcode - Depth First Search](https://leetcode.com/tag/depth-first-search/)
2. Good questions - [Number of enclaves](https://leetcode.com/problems/number-of-enclaves/) | [Find eventual safe states](https://leetcode.com/problems/find-eventual-safe-states/)

## References
1. [GeeksForGeeks - Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)
