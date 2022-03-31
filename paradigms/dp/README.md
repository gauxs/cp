# Dynamic Programming
Dynamic Programming is mainly an optimization over plain recursion. Wherever we see a recursive solution that has repeated calls for same inputs, we can optimize it using Dynamic Programming. The idea is to simply store the results of subproblems, so that we do not have to re-compute them when needed later. This simple optimization reduces time complexities from exponential to polynomial.

[A very important article describing how to look at (not how to solve) dynamic programming](https://stackoverflow.com/questions/6164629/what-is-the-difference-between-bottom-up-and-top-down)

Following are some important observation:
1. Some DP questions require us **NOT** to bring previous state(previous recursions result) to current recursion, instead always try to start fresh state from each recursion. Example: [Decode ways](https://leetcode.com/problems/decode-ways/)

2. While some DP questions **WANTS** us to bring previous state(previous recursions results) to current recursion and use it memoize. Example: [Partition equal subset sum](https://leetcode.com/problems/partition-equal-subset-sum/). Do go through [my submission](https://leetcode.com/submissions/detail/609838238/) for **Partition equal subset sum** question as it is very intuitive(compared to other solution), int this i have directly converted top-down to bottom-up without much modification, since deviation is less, chances of solving in interview is higher along with better intuition.

3. [Leetcode - Iterative subset sum approach](https://leetcode.com/problems/target-sum/discuss/97334/java-15-ms-c-3-ms-ons-iterative-dp-solution-using-subset-sum-with-explanation) by [@yuxiangmusic](https://leetcode.com/yuxiangmusic) and [Partition equal subset sum](https://leetcode.com/problems/partition-equal-subset-sum/) teaches important concept which require us to use previous state variables in memoizing current state. Its recommended to go through these question and all its solution i.e. top-dow, bottom-up(2d), bottom-up(1d) and bit set. 

4. The complexity of DP problems is **NOT** always **O(size of memoization array)**, it can sometimes be higher as it can be seen in following question, the memoization array is **O(N)** but the worst case runtime is still **O(N^2)**. Example: [Longest increasing subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)

5. Top-down approach can be converted to bottom-up approach just by mimicing the recursion and base case(even for DP questions which require us to bring previous state variables in current state like [Partition equal subset sum](https://leetcode.com/problems/partition-equal-subset-sum/)), if we have a weak base case(s) in top-down, same will work for bottom-up too.

6. What are **WEAK** and **TIGHT** base case(s)? Weak base case generally, fills all cells of a memoization array, whereas tighter base case(s) tends to minimise filling all the cells.
    - **Weak base case**: In [Edit Distance](https://leetcode.com/problems/edit-distance/) for a state(recursion) when index1==n1 && index2 is much lesser than n2, then all the **insert** branches will still open till index2==n2 and then return. Another way of Imagine filling the memoization array's last row moving column by column.
        ```cpp
        int answer(string& word1, int n1, int index1, string& word2, int n2, int index2, vector<vector<int>>& mem){
            if(index1==n1 && index2==n2)
                return 0;

            if(index1>n1 || index2>n2)
                return 10000;
            ...
            ...
            if(word1[index1]==word2[index2]){
                min_edit_distance = min(min_edit_distance, answer(word1, n1, index1+1, word2, n2, index2+1, mem));
            }else{
                // insert
                min_edit_distance = min(min_edit_distance, answer(word1, n1, index1, word2, n2, index2+1, mem) + 1);
                // delete
                min_edit_distance = min(min_edit_distance, answer(word1, n1, index1+1, word2, n2, index2, mem) + 1);
                // replace
                min_edit_distance = min(min_edit_distance, answer(word1, n1, index1+1, word2, n2, index2+1, mem) + 1);
            ...
            ...
        }
        ```
    - **Tight base case**: In [Edit Distance](https://leetcode.com/problems/edit-distance/) for a state(recursion) index1==n1 && index2 is much lesser than n2, in this base case we **don't open** insert branches(i.e. avoids filling some of the last row cells) but instead return (n2-index2).
        ```cpp
        int answer(string& word1, int n1, int index1, string& word2, int n2, int index2, vector<vector<int>>& mem){
            if(index1==n1 && index2==n2)
                return 0;
            if(index1!=n1 && index2==n2)
                return n1-index1;
            if(index1==n1 && index2!=n2)
                return n2-index2;
            ...
            ...
            if(word1[index1]==word2[index2]){
                min_edit_distance = min(min_edit_distance, answer(word1, n1, index1+1, word2, n2, index2+1, mem));
            }else{
                // insert
                min_edit_distance = min(min_edit_distance, answer(word1, n1, index1, word2, n2, index2+1, mem) + 1);
                // delete
                min_edit_distance = min(min_edit_distance, answer(word1, n1, index1+1, word2, n2, index2, mem) + 1);
                // replace
                min_edit_distance = min(min_edit_distance, answer(word1, n1, index1+1, word2, n2, index2+1, mem) + 1);
            ...
            ...
        }
        ```

6. [DP - Merge Intervals](https://leetcode.com/list/55aj8s16/) / [Interval DP](https://leetcode.com/discuss/general-discussion/592146/dynamic-programming-summary) pattern is not trivial and requires good amount of practice.

7. **Memory optimization DP**, problems in which we have to optimise memory - [Maximum score from performing multiplication operations](https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/) | [Ones & Zeroes](https://leetcode.com/problems/ones-and-zeroes/)

## Practice
- [Leetcode - Dynamic Programming](https://leetcode.com/tag/dynamic-programming/)
- Good questions - [Last Stone Weight-II](https://leetcode.com/problems/last-stone-weight-ii/) | [Paint House-II](https://www.lintcode.com/problem/516) | [Maximum profit in job scheduling](https://leetcode.com/problems/maximum-profit-in-job-scheduling/) | [Burst Balloons](https://leetcode.com/problems/burst-balloons/) | [Russian doll envelopes](https://leetcode.com/problems/russian-doll-envelopes/) | [Interviewbit - Potions](https://www.interviewbit.com/problems/potions/)

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
