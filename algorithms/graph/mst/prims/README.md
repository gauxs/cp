# Prim's Algorithm
The minimum spanning tree is built gradually by adding edges one at a time. At first the spanning tree consists only of a single vertex (chosen arbitrarily). Then the minimum weight edge outgoing from this vertex is selected and added to the spanning tree. After that the spanning tree already consists of two vertices. Now select and add the edge with the minimum weight that has **one end in an already selected vertex** (i.e. a vertex that is already part of the spanning tree), and the **other end in an unselected vertex**. And so on, i.e. every time we select and add the edge with minimal weight that connects one selected vertex with one unselected vertex. The process is repeated until the spanning tree contains all vertices (or equivalently until we have  edges).

In the end the constructed spanning tree will be minimal. If the graph was originally not connected, then there doesn't exist a spanning tree, so the number of selected edges will be **less than V-1**.

### Algorithm Analysis
```
V - number of graph nodes
E - number of edges

Time Complexity:         O((V + E)logV)
Space Complexity:        O(V)               // to store parent
```

## References
1. [CP Algorithms - Prims](https://cp-algorithms.com/graph/mst_prim.html)
2. [Hackerearth - Minimum Spanning Tree](https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/)
3. [GeeksForGeeks - Prims](https://www.geeksforgeeks.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/)