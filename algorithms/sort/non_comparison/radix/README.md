# Radix Sort
Digit by digit sort starting from least significant digit to most significant digit. Radix sort uses counting sort as a subroutine to sort.

Is Radix Sort preferable to Comparison based sorting algorithms like Quick-Sort? 
>If we have log2n bits for every digit, the running time of Radix appears to be better than Quick Sort for a wide range of input numbers. The constant factors hidden in asymptotic notation are higher for Radix Sort and Quick-Sort uses hardware caches more effectively. Also, Radix sort uses counting sort as a subroutine and counting sort takes extra space to sort numbers.

### Algorithm Analysis
```
    D - digits in input integers
    N - number of elements
    B - base for representing numbers, e.g. for the decimal system, B is 10
    K - range of input(for counting sort) which is constant here i.e 10

    Time complexity:    O(D*(N+B))
    What is the value of d? If k is the maximum possible value, then d would
    be O(logb(k)). So overall time complexity is O((n+b) * logb(k)). Which looks more than the time complexity of comparison-based
    sorting algorithms for a large k. Let us first limit k. Let k <= n^c where c is a constant. In that case, the complexity becomes
    O(n*logb(n)). But it still doesn’t beat comparison-based sorting algorithms.

    What if we make the value of b larger?. What should be the value of b to make the time complexity linear? If we set b as n, we
    get the time complexity as O(n). In other words, we can sort an array of integers with a range from 1 to n^c if the numbers are
    represented in base n (or every digit takes log2(n) bits).

    Space complexity:   O(N+K)
    Inplace sorting:    No
    Stable sorting:     Yes
```

## References
1. [GeeksForGeeks - Radix Sort](https://www.geeksforgeeks.org/radix-sort/)
