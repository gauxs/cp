# Binary Search
At each step, the algorithm compares the median value in the search space to the target value. Based on the comparison and because the sequence is sorted, it can then eliminate half of the search space. By doing this repeatedly, it will eventually be left with a search space consisting of a single element, the target value. Following are some important observation on the algorithm:
1. Choice of **low** and **high** i.e. the boundary:
> Normally, we set the initial boundary to the number of elements in the array i.e. low=0 and high=n-1, but this is not always the case. We need to remember: the boundary is the range of elements we will be searching from. The initial boundary should include ALL the elements, meaning all the possible answers should be included. Binary search can be applied to none array problems, such as Math, and this statement is still valid. For example, in [Search insert position](https://leetcode.com/problems/search-insert-position/), the question asks us to find an index to insert into the array. It is possible that we insert after the last element of the array, thus the complete range of boundary becomes low=0 and high=n.

2. Calculating **mid** can result in overflow when the numbers are extremely big. Following are the ways of calculating mid:
> &emsp; mid = Math.floor((low + high) / 2)         &nbsp;&nbsp;&emsp;&emsp;&emsp;// worst, very easy to overflow <br>
  &emsp; mid = low + Math.floor((high - low) / 2)   &emsp;// much better, but still possible <br>
  &emsp; mid = (low + high) >>> 1                   &emsp;&nbsp;&nbsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&nbsp;// the best, but hard to understand <br>

3. When we are dealing with even number of elements, it is our choice to pick the left one as mid or the right one as mid, a bad choice will lead to an infinity loop.
> &emsp; mid = low + Math.floor((high - low) / 2)        &emsp;&emsp;&emsp;// left/lower mid   <br>
  &emsp; mid = low + Math.floor((high - low + 1) / 2)    &emsp;// right/upper mid  <br>
  
4. While loop condition **low<high**, the only condition the loop exits is low == high, we can be sure that they will be pointing to the same element, and we know that element always exists:
> &emsp; while(low < high) { ... }

5. Avoiding infinity loop:
In this we code, suppose we have two element in searchspace, and low>target, then we will be stuck in infinite loop.

```
  int mid = low+(high-low)/2;   // choosing left one as mid causing infinite loop
  while(low<high){
    ...
    if(target<nums[mid]){
      high = mid-1;
    }else{
      low = mid;
    }
    ...
  }
```

In this code too
```
  int mid = low+(high-low+1)/2;   // choosing right one as mid causing infinite loop
  while(low<high){
    ...
    if(target>nums[mid]){
      low = mid+1;
    }else{
      high = mid;
    }
    ...
  }
```
We have to keep in mind that, the choice of **mid** and our shrinking logic has to work together in a way that every time, at least 1 element is excluded. So when your binary search is stuck, think of the situation when there are only 2 elements left. Did the boundary shrink correctly?

### Rule of Thumb
1. Include ALL possible answers when initialize low & high
2. Don't overflow the mid calculation
3. Shrink boundary using a logic that will exclude mid
4. Avoid infinity loop by picking the correct mid and shrinking logic
5. Always think of the case when there are 2 elements left

***NOTE: I have neglected all the points mentioned here and followed my implementation binary_iterative() because it is another way of implementing bug free  binary search and seems to work in every quetion solved till now.***

***Sometimes we won't even realize that the problem should be solved with binary search -- we might just turn to dynamic programming or DFS and get stuck for a very long time so, "When can we use binary search?", answer is, if we can discover some kind of monotonicity, for example, if condition(k) is True then condition(>k) is True OR if condition(k) is Fale then condition(>k) is False and vice-versa, then we can consider binary search.***
### Algorithm Analysis
```
    N - Size of input

    Time Complexity:   
    1.  Worst:          O(logN)
    2.  Average:        O(logN)
    3.  Best:           O(logN)

    Space Complexity:   O(1)
```

### Practice
1. Practice questions - [Leetcode - Binary Search](https://leetcode.com/tag/binary-search/)
2. Good questions     -  

## References
1. [Topcoder - Binary Search](https://www.topcoder.com/thrive/articles/Binary%20Search)
2. [Leetcode - Binary Search 101](https://leetcode.com/problems/binary-search/discuss/423162/Binary-Search-101-The-Ultimate-Binary-Search-Handbook)
