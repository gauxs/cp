# 0-1 BFS
We can find the shortest paths between a single source and all other vertices in O(E) using Breadth First Search in an unweighted graph, i.e. the distance is the minimal number of edges that you need to traverse from the source to another vertex. Another way of looking at this is, the unweighted edges can be assumed to have a weight of 1.

We can interpret such a graph also as a weighted graph, where every edge has the weight 1 or 0. If not all edges in graph have the same weight, then we need a more general algorithm, like Dijkstra. The basics and working of the algorithm can be learned from ***references*** below.

Following are some important observation on the algorithm:
1. At a particular moment, the queue can have only those vertex whose distance from source vertex are x or x+1. **Think, why can't queue have vertex x+2 along with x?**
2. **Can this algorithm be used in a graph where edge weight are 0 and x(x>=0)? Why so?**
3. **Can this algorithm be used in a graph where edge weight are x and x+1(x>=0)? Why so?**
4. **Can this algorithm be used in a graph where edge weight are x and y(x,y>=0)? Why so?**
5. We can extend this even further if we allow the weights of the edges to be even bigger. If every edge in the graph has a weight **<=K**, then the distances of vertices in the queue will differ by at most **K** from the source. So we can keep  buckets for the vertices in the queue, and whenever the bucket corresponding to the smallest distance gets empty, we make a cyclic shift to get the bucket with the next higher distance. This extension is called **Dial's algorithm**.

### Algorithm Analysis
```
V - number of graph nodes
E - number of edges

Time Complexity:    O(V + E) = O(E)     // for dense graph E ≈ V^2
Space Complexity:   O(V)
```

## References
1. [Codeforces - 01 BFS Tutorial](http://codeforces.com/blog/entry/22276)
2. [CP Algorithms - 01 BFS](https://cp-algorithms.com/graph/01_bfs.html)