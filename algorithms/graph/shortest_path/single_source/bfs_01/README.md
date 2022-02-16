# 0-1 BFS
We can find the shortest paths between a single source and all other vertices in O(M) using Breadth First Search in an unweighted graph, i.e. the distance is the minimal number of edges that you need to traverse from the source to another vertex.

We can interpret such a graph also as a weighted graph, where every edge has the weight 1 or 0. If not all edges in graph have the same weight, then we need a more general algorithm, like Dijkstra.

### Algorithm Analysis
```
N - number of graph nodes
M - number of edges

Time Complexity:    O(N + M) = O(M)     // for dense graph M ≈ N^2
Space Complexity:   O(N)
```

## References
- [CP Algorithms - 01 BFS](https://cp-algorithms.com/graph/01_bfs.html)
- [Codeforces - 01 BFS Tutorial](http://codeforces.com/blog/entry/22276)