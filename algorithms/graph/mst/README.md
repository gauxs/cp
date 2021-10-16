# Minimum spanning trees
Given a ***weighted, undirected graph*** G with n vertices and m edges. You want to find a spanning tree of this graph which connects all vertices and has the least weight (i.e. the sum of weights of edges is minimal). 

A ***spanning tree*** is a set of edges such that any vertex can reach any other by exactly one simple path. The spanning tree with the least weight is called a minimum spanning tree. Any spanning tree will necessarily contain n−1 edges.

## Prim's Algorithm
`greedy`

### Algorithm Analysis
```
N - number of graph nodes
M - number of edges

Time Complexity:         O((N + M)logV)
Space Complexity:        O(N)           // to store parent
```

### References
- https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/
- https://www.geeksforgeeks.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/


## Kruskal’s Algorithm

### Algorithm Analysis
```
N - number of graph nodes
M - number of edges

Time Complexity:         O(N + M)
Space Complexity:        O(N)           // to store color and parent
```

### References
- https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/