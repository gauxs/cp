# Graph Traversal Algorithms

Graph traversal algorithms are fundamental techniques for exploring and visiting all vertices in a graph. The two main approaches are Breadth-First Search (BFS) and Depth-First Search (DFS), each with distinct characteristics and use cases.

## Algorithm Comparison

| Aspect | BFS | DFS |
|--------|-----|-----|
| **Approach** | Level-by-level | Deep exploration |
| **Data Structure** | Queue (FIFO) | Stack (LIFO) |
| **Memory Usage** | O(V) | O(depth) |
| **Shortest Path** | Guaranteed in unweighted | Not guaranteed |
| **Path Finding** | Level-order | Any path |
| **Cycle Detection** | Possible | Natural fit |
| **Tree Traversal** | Level-order | Pre/In/Post-order |

## When to Choose Which Algorithm

### Choose **BFS** when:
- **Shortest path needed**: In unweighted graphs
- **Level-order processing**: Need to process by distance
- **Connected components**: Finding all reachable vertices
- **Game solving**: Minimum moves problems
- **Network analysis**: Shortest connection paths

### Choose **DFS** when:
- **Path finding**: Any path between vertices
- **Cycle detection**: Finding cycles in graphs
- **Topological sorting**: Dependency ordering
- **Tree problems**: Natural fit for tree structures
- **Backtracking**: Problems requiring exploration and undo
- **Memory efficiency**: Deep graphs with limited memory

## Complexity Analysis

| Algorithm | Time Complexity | Space Complexity | Best Use Case |
|-----------|----------------|------------------|---------------|
| **BFS** | O(V + E) | O(V) | Shortest paths, level-order |
| **DFS** | O(V + E) | O(depth) | Path finding, cycle detection |

## Implementation Patterns

### BFS Patterns
- **Basic traversal**: Level-by-level exploration
- **Shortest path**: Distance tracking
- **Multi-source**: Start from multiple vertices
- **State-based**: Include additional state information

### DFS Patterns
- **Backtracking**: Explore and undo decisions
- **Path reconstruction**: Build paths during traversal
- **Edge classification**: Tree, back, forward, cross edges
- **Component finding**: Mark connected components

## Practice Problems

For detailed practice problems organized by algorithm and difficulty:
- [BFS Practice](bfs/practice/) - Breadth-first search problems
- [DFS Practice](dfs/practice/) - Depth-first search problems

## References

- [BFS Algorithm](bfs/README.md) - Detailed BFS explanation
- [DFS Algorithm](dfs/README.md) - Detailed DFS explanation
- [CP Algorithms - Graph Traversal](https://cp-algorithms.com/graph/traversal-algorithms.html) - Comprehensive guide
