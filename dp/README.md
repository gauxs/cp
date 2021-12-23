# Some learning on Dynamic Programming
1. When memoizing we cannot bring previous state(previous recursion results) to current one(current recursion), instead always try to start fresh state from each recusrsion. Example: https://leetcode.com/problems/decode-ways/

2. The complexity of DP problems is ***NOT*** always O(size of memoization array), it can sometimes be higher as it can be seen in following question, the memoization array is O(n) but the worst case runtime is still O(n^2). Example: https://leetcode.com/problems/longest-increasing-subsequence/

# Reference
1. [Leetcode - How to approach Dynamic Programming-I](https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems) by [@heroes3001](https://leetcode.com/heroes3001)
2. [Leetcode - How to approach Dynamic Programming-II](https://leetcode.com/discuss/study-guide/1490172/Dynamic-programming-is-simple) by [@omgitspavel](https://leetcode.com/omgitspavel)
3. [Leetcode - Dynamic programming patterns](https://leetcode.com/discuss/general-discussion/458695/dynamic-programming-patterns) by [@aatalyk](https://leetcode.com/aatalyk)
4. [Leetcode - How to solve string DP?](https://leetcode.com/discuss/general-discussion/651719/how-to-solve-dp-string-template-and-4-steps-to-be-followed) by [@applefanboi](https://leetcode.com/applefanboi)
5. [Leetcode - Dynamic programming problems patternwise-I](https://leetcode.com/discuss/general-discussion/662866/dp-for-beginners-problems-patterns-sample-solutions) by [@wh0ami](https://leetcode.com/wh0ami)
6. [Leetcode - Dynamic programming problems patternwise-II](https://leetcode.com/discuss/general-discussion/592146/dynamic-programming-summary) by [@richenyunqi](https://leetcode.com/richenyunqi)
7. [Leetcode - Dynamic programming problems patternwise-III](https://leetcode.com/discuss/general-discussion/1050391/Must-do-Dynamic-programming-Problems-Category-wise) by [@mahesh_nagarwal](https://leetcode.com/mahesh_nagarwal)
8. [All public DP problems of leetcode based on difficulty and category](https://chuka231.blogspot.com/2021/01/leetcode-all-dynamic-programming.html) by [@chuka231](https://leetcode.com/chuka231)