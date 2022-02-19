# Breadth first search
Breadth first search is one of the basic and essential searching algorithms on graphs. The algorithm works on both directed and undirected graph. The path found by breadth first search to any node is the **shortest path** to that node, i.e the path that contains the smallest number of edges in unweighted graphs.

The algorithm can be understood as a fire spreading on the graph: at the zeroth step only the source vertex is on fire. At each step, the fire burning at each vertex spreads to all of its neighbors. In one iteration of the algorithm, the **ring of fire** is expanded in width by one unit (hence the name of the algorithm).

Following are some important observation on the algorithm:
1. The queue holding the vertex to be visited next, can only have vertices from current and next level or previous and current level. Queue will never hold vertices from more than two levels.

## Algorithm Analysis
```
    V - number of vertices
    E - number of edges

    Time complexity:    O(V+E)
    Space complexity:   O(V)        // when first node is connected to all the other unvisited nodes.
```

## Applications
1. 

## Practice
- [Leetcode - Breadth First Search](https://leetcode.com/tag/breadth-first-search/)
- Good questions - [Jump Game IV](https://leetcode.com/problems/jump-game-iv/) | [Perfect Squares](https://leetcode.com/problems/perfect-squares/)

## References
1. [CP Algorithms - BFS](https://cp-algorithms.com/graph/breadth-first-search.html)