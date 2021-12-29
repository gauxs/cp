# Some learning on Dynamic Programming
1. [A very important article describing how to look at (not how to solve) dynamic programming](https://stackoverflow.com/questions/6164629/what-is-the-difference-between-bottom-up-and-top-down)
2. When memoizing we cannot bring previous state(previous recursion results) to current one(current recursion), instead always try to start fresh state from each recusrsion. Example: https://leetcode.com/problems/decode-ways/
3. The complexity of DP problems is ***NOT*** always O(size of memoization array), it can sometimes be higher as it can be seen in following question, the memoization array is O(n) but the worst case runtime is still O(n^2). Example: https://leetcode.com/problems/longest-increasing-subsequence/
4. When converting top-down to bottom-up, we have to be careful about certain things:
    - We can make our base case in top-down approach **WEAK**, this makes creating base case for bottom-up really difficult
    - Important thing to notice here is that the top-down solution gets easier if we make weaker base case but with a big caveat that if we are      aiming to further solve the problem in bottom-up approach, we will have to spend extra time in coming up with **TIGHTER** base case
    - Example: Top-down approach for [Edit Distance](https://leetcode.com/problems/edit-distance/)
        - Weaker base case:
        ```
        int func(string word1, string word2, int n, int m , int i, int j, vector<vector<int> >& dp) {
            if(i == n && j == m) {
                return 0;
            }
            
            if(i > n || j > m) {
                return 10000;   // This is weaker base case and will cause extra branches to open, which simplifies the solution though
            }
            
            if(dp[i][j] != 10000) {
                return dp[i][j];
            }
            ...
        }
        ```
        - Tighter base case: 
        ```
        int answer(string& word1, int n1, int index1, string& word2, int n2, int index2, vector<vector<int>>& mem){
            if(index1==n1 || index2==n2){
                if(index1==n1 && index2==n2)
                    return 0;
                if(index1!=n1 && index2==n2)
                    return n1-index1;
                if(index1==n1 && index2!=n2)
                    return n2-index2;
            }
            ...
        }
        ```

# Reference
1. [Leetcode - How to approach Dynamic Programming](https://leetcode.com/problems/house-robber/discuss/156523/From-good-to-great.-How-to-approach-most-of-DP-problems) by [@heroes3001](https://leetcode.com/heroes3001)
2. [Leetcode - Dynamic Programming is simple-I | How to approach DP questions explained using easy example](https://leetcode.com/discuss/study-guide/1490172/Dynamic-programming-is-simple) by [@omgitspavel](https://leetcode.com/omgitspavel)
3. [Leetcode - Dynamic Programming is simple-II | How to approach DP questions explained using hard example](https://leetcode.com/discuss/study-guide/1508238/Dynamic-programming-is-simple-2) by [@omgitspavel](https://leetcode.com/omgitspavel)
4. [Leetcode - Dynamic Programming is simple-III | How to approach DP questions on which the above pattern doesn't apply](https://leetcode.com/discuss/study-guide/1527916/Dynamic-programming-is-simple-3-(multi-root-recursion)) by [@omgitspavel](https://leetcode.com/omgitspavel)
5. [Leetcode - Iterative subset sum approach](https://leetcode.com/problems/target-sum/discuss/97334/java-15-ms-c-3-ms-ons-iterative-dp-solution-using-subset-sum-with-explanation) by [@yuxiangmusic](https://leetcode.com/yuxiangmusic)
6. [Leetcode - How to solve string DP?](https://leetcode.com/discuss/general-discussion/651719/how-to-solve-dp-string-template-and-4-steps-to-be-followed) by [@applefanboi](https://leetcode.com/applefanboi)
7. [Leetcode - Dynamic programming patterns](https://leetcode.com/discuss/general-discussion/458695/dynamic-programming-patterns) by [@aatalyk](https://leetcode.com/aatalyk)
8. [Leetcode - Dynamic programming problems patternwise-I](https://leetcode.com/discuss/general-discussion/592146/dynamic-programming-summary) by [@richenyunqi](https://leetcode.com/richenyunqi)
9. [Leetcode - Dynamic programming problems patternwise-II](https://leetcode.com/discuss/general-discussion/1050391/Must-do-Dynamic-programming-Problems-Category-wise) by [@mahesh_nagarwal](https://leetcode.com/mahesh_nagarwal)
10. [Leetcode - Dynamic programming problems patternwise-III](https://leetcode.com/discuss/general-discussion/662866/dp-for-beginners-problems-patterns-sample-solutions) by [@wh0ami](https://leetcode.com/wh0ami)
11. [All public DP problems of leetcode based on difficulty and category](https://chuka231.blogspot.com/2021/01/leetcode-all-dynamic-programming.html) by [@chuka231](https://leetcode.com/chuka231)