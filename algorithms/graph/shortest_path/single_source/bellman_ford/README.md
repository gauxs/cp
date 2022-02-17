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