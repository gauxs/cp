# Kruskal's Algorithm
Kruskal's algorithm initially places all the nodes of the original graph isolated from each other, to form a forest of single node trees, and then gradually merges these trees, combining at each iteration **any two** of all the trees with some edge of the original graph. Before the execution of the algorithm, all edges are sorted by weight (in non-decreasing order). Then begins the process of unification: pick all edges from the first to the last (in sorted order), and if the ends of the currently picked edge belong to different subtrees, these subtrees are combined, and the edge is added to the answer. After iterating through all the edges, all the vertices will belong to the same sub-tree, and we will get the minimum spanning tree.

In the end the constructed spanning tree will be minimal. If the graph was originally not connected, then there doesn't exist a spanning tree, so the number of selected edges will be **less than V-1**.

### Algorithm Analysis
```
V - number of graph nodes
E - number of edges

Time Complexity:         O(ElogE) ≈ O(ElogV)    // E = V^2
Space Complexity:        O(V)                   // to store parent
```

## Practice
1. Practice questions - [Leetcode - Minimum Spanning trees](https://leetcode.com/tag/minimum-spanning-tree/)
2. Good questions - 

## References
1. [CP Algorithms - Kruskal](https://cp-algorithms.com/graph/mst_kruskal.html)
2. [Hackerearth - Minimum Spanning Tree](https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/)