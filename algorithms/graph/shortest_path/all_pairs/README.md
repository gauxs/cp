# All Pair Shortest Path Algorithms

## Floyd Warshall
Given a directed or an undirected weighted graph G with n vertices. The task is to find the length of the shortest path d[i][j] between each pair of vertices i and j. The graph may have negative weight edges, but **no negative weight cycles**.

This algorithm can also be used to detect the presence of negative cycles. The graph has a negative cycle if at the end of the algorithm, the distance from a vertex v to itself is negative.

Formally the Floyd-Warshall algorithm does not apply to graphs containing negative weight cycle(s). But for all pairs of vertices i and j for which there doesn't exist a path starting at i, visiting a negative cycle, and end at j, the algorithm will still work correctly.

For the pair of vertices for which the answer does not exist (due to the presence of a negative cycle in the path between them), the Floyd algorithm will store any number (perhaps highly negative, but not necessarily) in the distance matrix. However it is possible to improve the Floyd-Warshall algorithm, so that it carefully treats such pairs of vertices, and outputs them,
for example as −INF.

This can be done in the following way: let us run the usual Floyd-Warshall algorithm for a given graph. Then a shortest path between vertices i and j does not exist, if and only if, there is a vertex t that is reachable from i and also from j, for which d[t][t]<0.

### Algorithm Analysis
```
N - number of graph nodes

Time Complexity:    O(N^3)
Space Complexity:   O(N^2)      // if storing ancestors
```