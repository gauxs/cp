# Lowest Common Ancestor
Given a tree G. Given queries of the form (v1,v2), for each query you need to find the lowest common ancestor (or least common ancestor), i.e. a vertex v that lies on the path from the root to v1 and the path from the root to v2, and the vertex should be the lowest.

In other words, the desired vertex v is the most bottom ancestor of v1 and v2. It is obvious that their lowest common ancestor lies on a shortest path from v1 and v2. Also, if v1 is the ancestor of v2, v1 is their lowest common ancestor.

## LCA - Without pre-processing (only single query)
This is trivial to solve. Try this question on leetcode - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

### Algorithm Analysis
```
N - number of graph nodes

Time Complexity:         O(N)   // when tree is skewed
Space Complexity:        O(N)   // when tree is skewed
```

## LCA - With pre-processing (multiple queries)
Before answering the queries, we need to preprocess the tree. 

### Algorithm Analysis
```
N - number of graph nodes
M - number of edges

Time Complexity:         O(N + M)
Space Complexity:        O(N)
```

### References
- https://cp-algorithms.com/graph/lca.html