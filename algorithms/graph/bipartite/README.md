# Bipartite
A bipartite graph is a graph whose vertices can be divided into two disjoint sets so that every edge connects two vertices from different sets (i.e. there are no edges which connect vertices from the same set). These sets are usually called **sides**. You are given an undirected graph. Check whether it is bipartite, and if it is, output its sides.

There exists a theorem which claims that a **graph is bipartite if and only if all its cycles have even length**. However, in practice it's more convenient to use a different formulation of the definition: **a graph is bipartite if and only if it is two-colorable**.

## Algorithm Analysis
```
    V - number of vertices
    E - number of edges

    Time complexity:    O(V+E)
    Space complexity:   O(V)        // when first vertex is connected to all the other unvisited vertex
```

## Practice
1. Practice questions - [Possible bipartition](https://leetcode.com/problems/possible-bipartition/)

## References
1. [CP Algorithms - Bipartite](https://cp-algorithms.com/graph/bipartite-check.html)