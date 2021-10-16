# Single Pair Shortest Path Algorithms

You are given a directed or undirected weighted graph with n vertices and m edges. You are also given a starting vertex s. Find the lengths of the shortest paths from a starting vertex 's' to all other vertices, and output the shortest paths.

This problem is also called single-source shortest paths problem.


## Dijkstra
The weights of all edges are assumed to be non-negative.

It is clear, that the complexity of first algorithm i.e. dijkstra() is optimal for a dense graph, i.e. when M ≈ N^2. However in sparse graphs, when M 
is much smaller than the maximal number of edges N^2, the complexity gets less optimal because of the first term. Thus it is necessary to improve the execution time of "finding minimum distance vertex".

To accomplish this we can use a variation of multiple auxiliary data structures like set (implemented in dijkstra_set()), priority queue, fibonacci heaps.

1 - Since we need to store vertices ordered by their values d[], it is convenient to store actual pairs: the distance and the index of the vertex.
    As a result in a set, pairs are automatically sorted by their distances.

2 - We don't need the vector<bool> picked. We will use the set to store that information, and also find the vertex with 
    the shortest distance with it.

### Algorithm Analysis
```
N - number of graph nodes
M - number of edges

Time Complexity - dijkstra:         O(N^2 + M)                              // for dense graph M ≈ N^2
Space Complexity - dijkstra:        O(N)

Time Complexity - dijkstra_set:     O(Nlog(N) + Mlog(N)) = O(Mlog(N))       // for dense graph M ≈ N^2
Space Complexity - dijkstra_set:    O(N)
```

### References
- https://cp-algorithms.com/graph/dijkstra.html


## Bellman Ford
Given a weighted directed graph G with n vertices and m edges, and some specified vertex v, find the length of shortest paths from vertex v to every other vertex.

Unlike the Dijkstra algorithm, this algorithm can also be applied to graphs containing negative weight edges.

If the graph contains a negative cycle, then, clearly, the shortest path to some vertices may not exist (due to the fact that the weight of the shortest path must be equal to minus infinity), however this algorithm can be modified to signal the presence of a cycle of negative weight, or even deduce this cycle.

### Algorithm Analysis
```
N - number of graph nodes
M - number of edges

Time Complexity:    O(N * M) = O(N^3)     // for dense graph M ≈ N^2
Space Complexity:   O(N)
```

### References
- https://cp-algorithms.com/graph/bellman_ford.html


## 0-1 BFS
We can find the shortest paths between a single source and all other vertices in O(M) using Breadth First Search in an unweighted graph, i.e. the distance is the minimal number of edges that you need to traverse from the source to another vertex.

We can interpret such a graph also as a weighted graph, where every edge has the weight 1 or 0. If not all edges in graph have the same weight, then we need a more general algorithm, like Dijkstra.

### Algorithm Analysis
```
N - number of graph nodes
M - number of edges

Time Complexity:    O(N + M) = O(M)     // for dense graph M ≈ N^2
Space Complexity:   O(N)
```

### References
- https://cp-algorithms.com/graph/01_bfs.html
- Good Tutorial - http://codeforces.com/blog/entry/22276