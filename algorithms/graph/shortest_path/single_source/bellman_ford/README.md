# Bellman Ford
Given a weighted directed graph G with **V** vertices and **E** edges, and some specified vertex **s**, find the length of shortest paths from vertex **s** to every other vertex.

Unlike the Dijkstra algorithm, this algorithm can also be applied to graphs containing **negative weight edges**.

If the graph contains a **negative cycle**, then, clearly, the shortest path to some vertices may not exist (due to the fact that the weight of the shortest path must be equal to minus infinity), however this algorithm can be modified to signal the presence of a cycle of negative weight, or even deduce this cycle.

Following are some important observation on the algorithm:
1. **Think, why does this algorithm work on -ve edges?**
2. **Think, will this algorithm work on graph with undirected edges if edges can have both -ve and +ve weights? If not, why?**
3. **Think, will this algorithm work on graph with undirected edges if edges have only +ve weights?**
4. **If -ve cycle exists, after N iterations will the last_relaxed_vertex always be inside the -ve cycle? If not, why?**
5. **While finding -ve cycle, we go back N times to come inside the -ve cycle? Why does this work?**
6. **After going back N times, the vertex on which we land, will its previous edge always be -ve? If not, why?**

### Algorithm Analysis
```
V - number of graph nodes
E - number of edges

Time Complexity:    O(V * E) = O(V^3)     // for dense graph E ≈ V^2
Space Complexity:   O(V)
```

## Practice
1. Practice questions - [Network delay time](https://leetcode.com/problems/network-delay-time/)
2. Good questions - 

## References
1. [CP Algorithms - Bellman Ford](https://cp-algorithms.com/graph/bellman_ford.html)
