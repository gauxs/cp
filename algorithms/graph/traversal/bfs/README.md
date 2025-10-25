# Breadth-First Search (BFS)

Breadth-First Search is one of the fundamental graph traversal algorithms that explores vertices level by level, starting from a source vertex. It's particularly useful for finding shortest paths in unweighted graphs and exploring graphs in a systematic, breadth-first manner.

## Algorithm Overview

### Purpose
- **Level-by-level traversal**: Explore vertices in order of their distance from source
- **Shortest path finding**: Guarantees shortest path in unweighted graphs
- **Connected components**: Find all reachable vertices from a source
- **Systematic exploration**: Visit all vertices at distance k before distance k+1

### Key Characteristics
- **Queue-based**: Uses FIFO queue for vertex processing
- **Level order**: Processes vertices level by level
- **Shortest path guarantee**: In unweighted graphs, finds shortest paths
- **Works on both directed and undirected graphs**

## How It Works

### Core Concept
BFS can be visualized as a **fire spreading** on the graph:
- **Step 0**: Only the source vertex is "on fire"
- **Each step**: Fire spreads to all neighbors of burning vertices
- **Ring expansion**: The "ring of fire" expands by one unit each iteration

### Algorithm Steps
1. **Initialize**: Add source vertex to queue, mark as visited
2. **Process**: While queue is not empty:
   - Remove vertex from front of queue
   - Process the vertex
   - Add all unvisited neighbors to back of queue
   - Mark neighbors as visited
3. **Result**: All reachable vertices processed in level order

### Why It Works
- **Level order**: Ensures vertices are processed by distance from source
- **Queue property**: FIFO ensures level k vertices processed before level k+1
- **Visited tracking**: Prevents revisiting vertices and infinite loops

## Important Algorithm Observations

### Queue Property
**The queue holding vertices to be visited next can only have vertices from current and next level (or previous and current level). The queue will never hold vertices from more than two levels.**

**Why this matters:**
- **Level consistency**: Maintains the level-by-level exploration property
- **Shortest path**: Ensures we find shortest paths in unweighted graphs
- **Efficiency**: Prevents unnecessary vertex processing

## Algorithm Analysis

| Aspect | Complexity | Notes |
|--------|------------|-------|
| **Time Complexity** | O(V + E) | Each vertex and edge processed once |
| **Space Complexity** | O(V) | Queue and visited array |
| **Queue operations** | O(1) | Enqueue/dequeue are constant time |

### Complexity Breakdown
- **Vertex processing**: O(V) - each vertex processed once
- **Edge processing**: O(E) - each edge examined once
- **Queue operations**: O(V) - each vertex enqueued/dequeued once
- **Total**: O(V + E) dominates

## When to Use BFS

**Best for:**
- **Unweighted graphs**: Finding shortest paths
- **Level-order traversal**: Processing vertices by distance
- **Connected components**: Finding all reachable vertices
- **Shortest path problems**: When path length = number of edges

**Not ideal for:**
- **Weighted graphs**: Use Dijkstra's or other algorithms
- **Deep exploration**: DFS might be more memory efficient
- **Path reconstruction**: DFS with backtracking might be better

## Applications

### Core Applications
1. **Shortest path**: Find shortest path from source to all vertices in unweighted graphs
2. **Connected components**: Find all connected components in O(V + E) time
3. **Game solving**: Find solution with least number of moves (state space search)
4. **Binary weighted graphs**: Shortest path with weights 0,1 (see [0-1 BFS](https://github.com/gauxs/cp/blob/master/algorithms/graph/shortest_path/single_source/bfs_01))
5. **Cycle detection**: Find shortest cycle in directed unweighted graphs

### Advanced Applications
6. **Shortest path edges**: Find all edges on shortest paths between vertices (a,b)
7. **Shortest path vertices**: Find all vertices on shortest paths between vertices (a,b)
8. **Even length paths**: Find shortest path of even length from s to t

### Real-world Examples
- **Social networks**: Find shortest connection path between people
- **Network routing**: Find shortest route in unweighted networks
- **Puzzle solving**: Find minimum moves to solve puzzles
- **Web crawling**: Systematic exploration of web pages
- **Game AI**: Find optimal moves in turn-based games

## Implementation Considerations

### Data Structures
- **Queue**: FIFO queue for vertex processing
- **Visited array**: Track processed vertices
- **Adjacency list**: Graph representation
- **Distance array**: Optional, for shortest path tracking

### Common Patterns
- **Multi-source BFS**: Start from multiple vertices simultaneously
- **BFS with state**: Include additional state information
- **Level tracking**: Process vertices level by level
- **Path reconstruction**: Build paths while traversing

## References

1. [CP Algorithms - BFS](https://cp-algorithms.com/graph/breadth-first-search.html) - Detailed algorithm explanation
2. [Wikipedia - Breadth-First Search](https://en.wikipedia.org/wiki/Breadth-first_search) - Mathematical properties
3. [GeeksforGeeks - BFS](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/) - Implementation guide
