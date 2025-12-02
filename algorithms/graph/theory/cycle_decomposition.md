## Cycle Decomposition

Cycle decomposition is the process of breaking a permutation or graph into disjoint cycles so that each cycle can be handled independently. Many array/permutation problems reduce to counting or transforming these cycles. A common technique is **cycle swapping**, described in the [Couples Holding Hands editorial](https://leetcode.com/problems/couples-holding-hands/discuss/113362/JavaC%2B%2B-O(N)-solution-using-cyclic-swapping). Read that explanation before attempting the practice problems.

### Key Idea: Cycle Swapping
1. Model the permutation as a graph where indices are connected to their target positions.
2. Each connected component forms a cycle.
3. The cost to fix a cycle of length `k` is typically `k - 1` swaps.
4. Solve the problem by repeating this process for all cycles (or by strategically swapping within each cycle).

### Practice
- **Challenging**
  1. [LeetCode - First Missing Positive](https://leetcode.com/problems/first-missing-positive/)
  2. [LeetCode - Couples Holding Hands](https://leetcode.com/problems/couples-holding-hands/)

### Notes
- [LeetCode - K Similar Strings](https://leetcode.com/problems/k-similar-strings) **looks** like a cycle-decomposition problem (you are transforming one permutation into another), but it is **not** solved by a simple "each cycle of length `k` costs `k - 1` swaps" formula.
  - The standard approaches treat each permutation as a node and run BFS / DFS with pruning over the state space to find the minimum number of swaps.
  - Cycle-decomposition is useful only as intuition here; the real toolkit you need is graph search on permutations.
- [First Missing Positive](https://leetcode.com/problems/first-missing-positive/) and [Couples Holding Hands](https://leetcode.com/problems/couples-holding-hands/) appeared in Google phone screenings.
- Need more intuition buildup in this topic.
