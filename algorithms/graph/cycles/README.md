# Finding cycles in a graph

## Find cycle in a graph
Consider a directed or undirected graph without loops and multiple edges. We have to check whether it is acyclic, and if it is not, then find any cycle.

![Why 2 colors in undirected graph](https://github.com/gauxs/cp/blob/master/media/images/find_cycle_1.jpg?raw=true)

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
Before answering the queries, we need to preprocess the tree. 

### Algorithm Analysis
```
N - number of graph nodes
M - number of edges

Time Complexity:         O(N + M)
Space Complexity:        O(N)           // to store visited and parent
```

### References
- https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html