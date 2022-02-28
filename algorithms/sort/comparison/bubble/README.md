# Bubble Sort
This algorithm works by repeatedly swapping the adjacent elements if they are in wrong order. Following are some important observation on the algorithm:
1. One pass gives an impression of bringing the largest(smallest if sorting in decreasing order) element towards the end of the list(if we traverse from 0).

2. After first pass we know that last index element is at right place.

3. In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity O(2*N). 

### Algorithm Analysis
```
    N - Size of input

    Time Complexity:   
    1.  Worst:          O(N^2)
    2.  Average:        O(N^2)
    3.  Best:           O(N)        // when the input is sorted  

    Space Complexity:   O(1)
    Inplace Sorting:    yes
    Stable Sorting:     yes 
```

## References
1. [GeeksForGeeks - Bubble Sort](https://www.geeksforgeeks.org/bubble-sort/)
