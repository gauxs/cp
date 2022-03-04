# Binary Search
At each step, the algorithm compares the median value in the search space to the target value. Based on the comparison and because the sequence is sorted, it can then eliminate half of the search space. By doing this repeatedly, it will eventually be left with a search space consisting of a single element, the target value. Following are some important observation on the algorithm:
1. Choice of **low** and **high** i.e. the boundary:
> Normally, we set the initial boundary to the number of elements in the array i.e. low=0 and high=n-1, but this is not always the case. We need to remember: the boundary is the range of elements we will be searching from. The initial boundary should include ALL the elements, meaning all the possible answers should be included. Binary search can be applied to none array problems, such as Math, and this statement is still valid. For example, in [Search insert position](https://leetcode.com/problems/search-insert-position/), the question asks us to find an index to insert into the array. It is possible that we insert after the last element of the array, thus the complete range of boundary becomes low=0 and high=n.

2. Calculating **mid** can result in overflow when the numbers are extremely big. Following are the ways of calculating mid:
> &emsp;mid = Math.floor((low + high) / 2)         &nbsp;&nbsp;&emsp;&emsp;&emsp;// worst, very easy to overflow <br>
  &emsp;mid = low + Math.floor((high - low) / 2)   &emsp;// much better, but still possible <br>
  &emsp;mid = (low + high) >>> 1                   &nbsp;&nbsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;// the best, but hard to understand <br>

3. When we are dealing with even number of elements, it is our choice to pick the left one as mid or the right one as mid, a bad choice will lead to an infinity loop.
> &emsp;mid = low + Math.floor((high - low) / 2)        &emsp;&emsp;&emsp;// left/lower mid   <br>
  &emsp;mid = low + Math.floor((high - low + 1) / 2)    &emsp;// right/upper mid  <br>
  
4. While loop condition **low<high**, the only condition the loop exits is low == high, we can be sure that they will be pointing to the same element, and we know that element always exists:
> while(low < high) { ... }

5. Avoiding infinity loop:
6. Just remember to always test your code on a two-element set where the predicate is false for the first element and true for the second.

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
1. [Topcoder - Binary Search](https://www.topcoder.com/thrive/articles/Binary%20Search)
2. [Leetcode - Binary Search 101](https://leetcode.com/problems/binary-search/discuss/423162/Binary-Search-101-The-Ultimate-Binary-Search-Handbook)
