# Breadth First Search
Breadth first search is one of the basic and essential searching algorithms on graphs. The algorithm works on both directed and undirected graph. The path found by breadth first search to any node is the **shortest path** to that node, i.e the path that contains the smallest number of edges in unweighted graphs.

The algorithm can be understood as a fire spreading on the graph: at the zeroth step only the source vertex is on fire. At each step, the fire burning at each vertex spreads to all of its neighbors. In one iteration of the algorithm, the **ring of fire** is expanded in width by one unit (hence the name of the algorithm).

Following are some important observation on the algorithm:
1. The queue holding the vertex to be visited next, can only have vertices from current and next level or previous and current level. Queue will never hold vertices from more than two levels.

## Algorithm Analysis
```
    V - number of vertices
    E - number of edges

    Time complexity:    O(V+E)
    Space complexity:   O(V)        // when first vertex is connected to all the other unvisited vertex
```

## Applications
1. Find the shortest path from a source to other vertices in an unweighted graph.

2. Find all connected components in an undirected graph in O(V+E) time.

3. Finding a solution to a problem or a game with the least number of moves, if each state of the game can be represented by a vertex of the graph, and the transitions from one state to the other are the edges of the graph.

4. Finding the shortest path in a graph with weights 0,1 or 0,x i.e. [01-BFS](https://github.com/gauxs/cp/blob/master/algorithms/graph/shortest_path/single_source/bfs_01)

5. Finding the shortest cycle in a directed unweighted graph.

6. Find all the edges that lie on any shortest path between a given pair of vertices (a,b).

7. Find all the vertices on any shortest path between a given pair of vertices (a,b).

8. Find the shortest path of even length from a source vertex **s** to a target vertex **t** in an unweighted graph.

## Practice
- [Leetcode - Breadth First Search](https://leetcode.com/tag/breadth-first-search/)
- Good questions - [Jump Game IV](https://leetcode.com/problems/jump-game-iv/) | [Perfect Squares](https://leetcode.com/problems/perfect-squares/)

## References
1. [CP Algorithms - BFS](https://cp-algorithms.com/graph/breadth-first-search.html)