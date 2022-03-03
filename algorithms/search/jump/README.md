# Jump Search
Following are some important observation on the algorithm:
1. Works on sorted data.
2. Jumps by a fixed length(M) until we find an element > search element. Then we perform linear search in that range.
3. Worst case we will do N/M jumps and when last checked value is > search element, then we perform linear search of (M-1) comparisons.
4. Total number of comparisons = ((N/M) + (M-1)), this is minimized when M = sqrt(N)
5. Time complexity is between Binary Search and Linear Search.
6. Binary Search is better than Jump Search, but Jump search has an advantage that we traverse back only once  (Binary Search may require up to O(Log n) jumps, consider a situation where the element to be searched is the smallest element or smaller than the smallest). So in a system where binary search is costly, we use Jump Search.

### Algorithm Analysis
```
    N - Size of input

    Time Complexity:   
    1.  Worst:          O(logN)
    2.  Average:        O(logN)
    3.  Best:           O(logN)

    Space Complexity:   O(1)
```

## References
1. [GeeksForGeeks - Jump Search](https://www.geeksforgeeks.org/jump-search/)
