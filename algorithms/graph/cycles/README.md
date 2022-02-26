# Finding cycles in a graph
Consider a directed or undirected graph without loops and multiple edges. We have to check whether it is acyclic, and if it is not, then find any cycle.

We can use DFS to find cycles. But why do we need 2 colors in undirected graph but 3 color in directed graph?

<img src="https://github.com/gauxs/cp/blob/master/media/images/find_cycle_1.jpg?raw=true" width="600" height="400">

### Algorithm Analysis
```
V - number of vertex
E - number of edges

Time Complexity:         O(V + E)
Space Complexity:        O(V)           // to store color and parent
```

Negative cycles can be found using following methods:
1. [Bellman Ford](https://github.com/gauxs/cp/blob/master/algorithms/graph/shortest_path/single_source/bellman_ford.h)
2. [Floyd Warshall](https://github.com/gauxs/cp/blob/master/algorithms/graph/shortest_path/all_pairs/floyd_warshall.h)

## References
1. [CP Algorithms - Finding Cycle](https://cp-algorithms.com/graph/finding-cycle.html)
2. [CP Algorithm - Finding negative cycle in graph](https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html)