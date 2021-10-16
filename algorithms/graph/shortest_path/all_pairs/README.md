# All Pair Shortest Path Algorithms
Given a directed or an undirected weighted graph G with n vertices. The task is to find the length of the shortest path d[i][j] (d is the distance matrix) between each pair of vertices i and j. The graph may have negative weight edges, but ***no negative weight cycles***.

## Floyd Warshall
This algorithm can also be used to detect the presence of negative cycles. The graph has a negative cycle if at the end of the algorithm, the distance from a vertex v to itself is negative.

Formally, the Floyd-Warshall algorithm does not apply to graphs containing negative weight cycle(s). But for all pairs of vertices i and j for which there doesn't exist a path starting at i, visiting a negative cycle, and end at j, the algorithm will still work correctly.

For the pair of vertices for which the answer does not exist (due to the presence of a negative cycle in the path between them), the Floyd algorithm will store any number (perhaps highly negative, but not necessarily) in the distance matrix. However it is possible to improve the Floyd-Warshall algorithm, so that it carefully treats such pairs of vertices, and outputs them, for example as −INF.

This can be done in the following way: let us run the usual Floyd-Warshall algorithm for a given graph. Then a shortest path between vertices i and j does not exist, if and only if, there is a vertex t that is reachable from i and also from j, for which d[t][t]<0.

### Finding negative cycle
Run Floyd-Warshall algorithm on the graph. Initially d[v][v]=0 for each v. But after running the algorithm d[v][v] will be smaller than 0 if there exists a negative length path from v to v.

We can use this to also find all pairs of vertices that don't have a shortest path between them. We iterate over all pairs of vertices (i,j) and for each pair we check whether they have a shortest path between them.

To do this try all possibilities for an intermediate vertex t. (i,j) doesn't have a shortest path, if one of the intermediate vertices t has d[t][t]<0 (i.e. t is part of a cycle of negative weight), t can be reached from i and j can be reached from t. Then the path from i to j can have arbitrarily small weight. We will denote this with -INF.

### Algorithm Analysis
```
N - number of graph nodes

Time Complexity:    O(N^3)
Space Complexity:   O(N^2)      // if storing ancestors
```

### References
- https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
- https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html

### Pending
- [ ] Fix the logic of `print_path`
- [ ] How to print negative cycle vertices in `floyd_warshal`? We only found -ve length path exists from v to v iff d[v][v]<0, so v is present on a negative cycle but we dont the path itslef.