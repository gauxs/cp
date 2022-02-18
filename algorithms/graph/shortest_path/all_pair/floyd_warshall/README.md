# Floyd Warshall
Given a **directed** or an **undirected** weighted graph with vertices. The task is to find the length of the shortest path between each pair of vertices. The graph may have negative weight edges, but **NO** negative weight cycles.

This algorithm can also be used to detect the presence of negative cycles. **The graph has a negative cycle if at the end of the algorithm, the distance from a vertex v to itself is negative.**

For the pair of vertices for which the answer does not exist (due to the presence of a negative cycle in the path between them), the Floyd algorithm will store any number (perhaps highly negative, but not necessarily) in the distance matrix. However it is possible to improve the Floyd-Warshall algorithm, so that it carefully treats such pair of vertices, and outputs them, for example as **−INF**.

This can be done in the following way: run the usual Floyd-Warshall algorithm for a given graph. Then a shortest path between vertices **i** and **j** does not exist, if and only if, there is a vertex **t** that is reachable from **i** and also from **j**, for which **distances[t][t]<0**.

### Finding negative cycle
Run Floyd-Warshall algorithm on the graph. Initially **distances[v][v]=0** for each **v**. But after running the algorithm **distances[v][v]** will be smaller than 0 if there exists a negative length path from **v** to **v**.

We can use this to also find all pairs of vertices that don't have a shortest path between them. We iterate over all pairs of vertices **(i,j)** and for each pair we check whether they have a shortest path between them.

To do this try all possibilities for an intermediate vertex **t**. **(i,j)** doesn't have a shortest path, if one of the intermediate vertices **t** has **distances[t][t]<0** (i.e. t is part of a cycle of negative weight), **t** can be reached from **i** and **j** can be reached from **t**. Then the path from **i** to **j** can have arbitrarily small weight. We will denote this with **-INF**.

Following are some important observation on the algorithm:
1. Before k-th phase, for any vertices **i** and **j** stores the length of the shortest path between the vertex **i** and vertex **j**, which contains only the vertices **1,2,3,4....k-1** as internal vertices in the path. **This means the outer most loop will be **k**, and inner loop will be i and j.**

### Algorithm Analysis
```
V - number of graph nodes

Time Complexity:    O(V^3)
Space Complexity:   O(V^2)      // if storing ancestors
```

## References
- [CP Algorithms - Floyd Warshall](https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html)
- [CP Algorithms - Finding -ve cycle via Floyd Warshall](https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html)

## Pending
- [ ] Fix the logic of `print_path`
- [ ] How to print negative cycle vertices in `floyd_warshal`? We only found -ve length path exists from v to v iff d[v][v]<0, so v is present on a negative cycle but we dont the path itslef.