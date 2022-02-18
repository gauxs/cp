# Bellman Ford
Given a weighted directed graph G with **V** vertices and **E** edges, and some specified vertex **s**, find the length of shortest paths from vertex **s** to every other vertex.

Unlike the Dijkstra algorithm, this algorithm can also be applied to graphs containing **negative weight edges**.

If the graph contains a **negative cycle**, then, clearly, the shortest path to some vertices may not exist (due to the fact that the weight of the shortest path must be equal to minus infinity), however this algorithm can be modified to signal the presence of a cycle of negative weight, or even deduce this cycle.

Following are some important observation on the algorithm:
1. **Think, why does this algorithm work on -ve edges?**
2. **Think, will this algorithm work on graph with undirected edges if edges can have both -ve and +ve weights? If not, why?**
3. **Think, will this algorithm work on graph with undirected edges if edges have only +ve weights?**

### Algorithm Analysis
```
V - number of graph nodes
E - number of edges

Time Complexity:    O(V * E) = O(V^3)     // for dense graph E ≈ V^2
Space Complexity:   O(V)
```

## References
1. [CP Algorithms - Bellman Ford](https://cp-algorithms.com/graph/bellman_ford.html)
