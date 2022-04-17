## Cycle Decomposition

The process of breaking down the graph into cycles is called **cycle decomposition**. Cycle decomposition can be done by [cycle swapping](https://leetcode.com/problems/couples-holding-hands/discuss/113362/JavaC%2B%2B-O(N)-solution-using-cyclic-swapping), do read [cycle swapping](https://leetcode.com/problems/couples-holding-hands/discuss/113362/JavaC%2B%2B-O(N)-solution-using-cyclic-swapping) before attempting these questions.

## Practice

| **S.No** 	| **Warmup** 	|                                       **Challenging**                                      	|
|:--------:	|:----------:	|:------------------------------------------------------------------------------------------:	|
|     1    	|            	| [Leetcode - First missing positive](https://leetcode.com/problems/first-missing-positive/) 	|
|     2    	|            	|       [Leetcode - K similar strings](https://leetcode.com/problems/k-similar-strings)      	|
|     3    	|            	|  [Leetcode - Couples holding hands](https://leetcode.com/problems/couples-holding-hands/)  	|

**Note**: [Leetcode - K similar strings](https://leetcode.com/problems/k-similar-strings) can be solved in 3 ways:

- Generate a graph from each possible permutation of source string where each edge will represent 1 swap, then run bfs from start node to destination, the path length will be shortest swaps
- Swap the source at those position which will bring us to those permutation which can give us answer while discarding other needless permutation, also keep track of already visited permutations, [my submission](https://leetcode.com/submissions/detail/678713606/)
- The problem is essentially finding maximum number of cycles in the graph, number os edges in one cycle - 1 will give us the number of swaps to decompose one cycle. Finding this for all the cycles will be minimum number os swaps. Implementing this is a bit tricky

**Note**: [Leetcode - First missing positive](https://leetcode.com/problems/first-missing-positive/) and [Leetcode - Couples holding hands](https://leetcode.com/problems/couples-holding-hands/) we asked in phone screening round of Google :weary:
