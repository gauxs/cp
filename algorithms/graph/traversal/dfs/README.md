# Depth First Search
Depth First Search finds the lexicographical first path in the graph from a source vertex u to each vertex. Depth First Search will also find the shortest paths in a tree (because there only exists one simple path), but on general graphs this is not the case.

## Algorithm Analysis
```
    V - number of vertices
    E - number of edges

    Time complexity:    O(V+E)
    Space complexity:   O(V)   
```

## Applications
1. Find any path in the graph from source vertex **s** to all vertices.

2. Find lexicographical first path in the graph from source **s** to all vertices.

3. Check if a vertex in a tree is an ancestor of some other vertex:

4. Find the lowest common ancestor (LCA) of two vertices.

5. Topological sorting.

6. Find strongly connected components in a directed graph

7. Find bridges in an undirected graph

## Classification of edges
We can classify the edges using the entry and exit time of the end nodes **u** and **v** of the edges **(u, v)**. These classifications are often used for problems like finding **bridges** and **finding articulation points**. We perform a DFS and classify the encountered edges using the following rules:

## Practice
- [Leetcode - Depth First Search](https://leetcode.com/tag/depth-first-search/)
- Good questions - 

## References
1. [CP Algorithms - DFS](https://cp-algorithms.com/graph/depth-first-search.html)