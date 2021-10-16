# Finding cycles in a graph

## Find cycle in a graph
Consider a directed or undirected graph without loops and multiple edges. We have to check whether it is acyclic, and if it is not, then find any cycle.

<img src="https://github.com/gauxs/cp/blob/master/media/images/find_cycle_1.jpg?raw=true" width="600" height="400">

### Algorithm Analysis
```
N - number of graph nodes
M - number of edges

Time Complexity:         O(N + M)
Space Complexity:        O(N)           // to store color and parent
```
### References
- https://cp-algorithms.com/graph/finding-cycle.html


## Find negative cycle in graph
Negative cycles can be found using following methods:
- [Bellman Ford](https://github.com/gauxs/cp/blob/master/algorithms/graph/shortest_path/single_source/bellman_ford.h)
- [Floyd Warshall](https://github.com/gauxs/cp/blob/master/algorithms/graph/shortest_path/all_pairs/floyd_warshall.h)

### References
- https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html