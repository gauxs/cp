# Dynamic Programming
Dynamic Programming is mainly an optimization over plain recursion. Wherever we see a recursive solution that has repeated calls for same inputs, we can optimize it using Dynamic Programming. The idea is to simply store the results of subproblems, so that we do not have to re-compute them when needed later. This simple optimization reduces time complexities from exponential to polynomial.

[A very important article describing how to look at (not how to solve) dynamic programming](https://stackoverflow.com/questions/6164629/what-is-the-difference-between-bottom-up-and-top-down)

## Key Observations

Following are some important observations (original content, lightly reorganized):

1. Some DP questions require us **NOT** to bring previous state (previous recursion results) to the current recursion, and instead always try to start a fresh state from each recursion.  
   - Example: [Decode Ways](https://leetcode.com/problems/decode-ways/)

2. Some DP questions **WANT** us to bring previous state (previous recursion results) to the current recursion and use it to memoize / transition.  
   - Example: [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)  
     Do go through [my submission](https://leetcode.com/submissions/detail/609838238/) for **Partition Equal Subset Sum**; it directly converts top-down to bottom-up with minimal changes, which helps intuition and interview performance.

3. [Leetcode - Iterative subset sum approach](https://leetcode.com/problems/target-sum/discuss/97334/java-15-ms-c-3-ms-ons-iterative-dp-solution-using-subset-sum-with-explanation) by [@yuxiangmusic](https://leetcode.com/yuxiangmusic) and [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/) teach an important concept: using previous state variables when memoizing the current state.  
   It is recommended to go through these questions and all their solutions: top-down, bottom-up (2D), bottom-up (1D), and bitset.

4. The complexity of DP problems is **NOT** always **O(size of memoization array)**. It can be higher. For example, the memoization array can be **O(N)** but the worst-case runtime **O(N²)**.  
   - Example: [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

5. Top-down approach can be converted to bottom-up approach just by mimicking the recursion and base case (even for DP questions that require us to bring previous state variables into the current state, like [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)). If the top-down base cases are good, the same structure works for bottom-up too.

6. What are **WEAK** and **TIGHT** base case(s)?  
   Weak base cases generally fill many cells of a memoization array, whereas tighter base cases tend to minimise how many cells you touch.
    - **Weak base case**: In [Edit Distance](https://leetcode.com/problems/edit-distance/), for a state (recursion) when `index1 == n1` and `index2` is much less than `n2`, all the **insert** branches still open until `index2 == n2` and then return. You can imagine this as filling the memoization array's last row cell-by-cell.
    - **Tight base case**: In [Edit Distance](https://leetcode.com/problems/edit-distance/), for a state (recursion) where `index1 == n1` and `index2` is much less than `n2`, we **do not open** insert branches (avoiding filling some last-row cells) and instead return `(n2 - index2)` immediately.

7. [DP - Merge Intervals](https://leetcode.com/list/55aj8s16/) / [Interval DP](https://leetcode.com/discuss/general-discussion/592146/dynamic-programming-summary) pattern is not trivial and requires good amount of practice.

8. **Memory optimization DP**: problems in which we have to optimise memory while keeping the same DP logic.  
   - Examples: [Maximum score from performing multiplication operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/) | [Ones & Zeroes](https://leetcode.com/problems/ones-and-zeroes/)

## Practice

- [Leetcode - Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)
- Good questions (not in leetcode):
    - [Potions](https://www.interviewbit.com/problems/potions/)

## References
1. [Leetcode - How to approach Dynamic Programming](https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems) by [@heroes3001](https://leetcode.com/heroes3001)
2. [Leetcode - Dynamic Programming is simple-I | How to approach DP questions explained using easy example](https://leetcode.com/discuss/study-guide/1490172/Dynamic-programming-is-simple) by [@omgitspavel](https://leetcode.com/omgitspavel)
3. [Leetcode - Dynamic Programming is simple-II | How to approach DP questions explained using hard example](https://leetcode.com/discuss/study-guide/1508238/Dynamic-programming-is-simple-2) by [@omgitspavel](https://leetcode.com/omgitspavel)
4. [Leetcode - Dynamic Programming is simple-III | How to approach DP questions on which the above pattern doesn't apply](https://leetcode.com/discuss/study-guide/1527916/Dynamic-programming-is-simple-3-(multi-root-recursion)) by [@omgitspavel](https://leetcode.com/omgitspavel)
5. [Leetcode - Dynamic programming patterns](https://leetcode.com/discuss/general-discussion/458695/dynamic-programming-patterns) by [@aatalyk](https://leetcode.com/aatalyk)
6. [Leetcode - Dynamic programming problems patternwise-I](https://leetcode.com/discuss/general-discussion/592146/dynamic-programming-summary) by [@richenyunqi](https://leetcode.com/richenyunqi)
7. [Leetcode - Dynamic programming problems patternwise-II](https://leetcode.com/discuss/general-discussion/1050391/Must-do-Dynamic-programming-Problems-Category-wise) by [@mahesh_nagarwal](https://leetcode.com/mahesh_nagarwal)
8. [Leetcode - Dynamic programming problems patternwise-III](https://leetcode.com/discuss/general-discussion/662866/dp-for-beginners-problems-patterns-sample-solutions) by [@wh0ami](https://leetcode.com/wh0ami)
9. [All public DP problems of leetcode based on difficulty and category](https://chuka231.blogspot.com/2021/01/leetcode-all-dynamic-programming.html) by [@chuka231](https://leetcode.com/chuka231)
