# 0-1 BFS Algorithm

The 0-1 BFS algorithm is an optimized version of BFS that finds shortest paths in graphs where edges have weights of only 0 or 1. It achieves O(V + E) time complexity, making it more efficient than Dijkstra's algorithm for this specific case.

## Algorithm Overview

### Purpose
- **Single-source shortest path**: Find shortest distances from source to all vertices
- **Binary edge weights**: Optimized for graphs with edge weights 0 or 1
- **Linear time complexity**: O(V + E) instead of O((V + E) log V) for Dijkstra's
- **Unweighted graph interpretation**: Can be viewed as BFS on unweighted graphs

### Key Characteristics
- **Deque-based**: Uses double-ended queue for efficient insertion
- **Two-level queue**: Maintains vertices at distances x and x+1
- **Greedy approach**: Always processes vertices in order of increasing distance
- **Works on both directed and undirected graphs**

## How It Works

### Core Idea
The algorithm uses a **deque** (double-ended queue) where:
- **Weight 0 edges**: Add vertices to the **front** of the queue (same distance level)
- **Weight 1 edges**: Add vertices to the **back** of the queue (next distance level)

This ensures vertices are always processed in order of increasing distance from the source.

### Algorithm Steps
1. **Initialize**: Set distance to source as 0, all others as infinity
2. **Process**: While queue is not empty:
   - Remove vertex from front of deque
   - For each neighbor:
     - If edge weight is 0: add to front of deque
     - If edge weight is 1: add to back of deque
3. **Result**: Shortest distances found

### Why It Works
- **Distance levels**: At any moment, queue contains vertices at distances x and x+1 only
- **Ordering**: Front of queue has distance x, back has distance x+1
- **Optimality**: Always processes vertices in order of increasing distance

## Important Algorithm Observations

### Critical Thinking Questions
1. **Why does this algorithm work on both directed and undirected graphs?**
   - The algorithm only cares about edge weights (0 or 1), not direction
   - BFS traversal works on both graph types
   - Edge direction affects reachability but not the 0-1 weight property

2. **Why can't the queue have vertices at distance x+2 along with x?**
   - **Distance levels**: Queue maintains only two consecutive distance levels
   - **Processing order**: Vertices at distance x are processed before x+1
   - **No gaps**: If we reach distance x+2, all vertices at x and x+1 must be processed first

3. **Can this be used for edge weights 0 and x (x ≥ 0)?**
   - **No** - violates the two-level queue property
   - **Example**: Weights 0 and 5 would create gaps in distance levels
   - **Queue would have**: distances 0, 5, 10, 15... (not consecutive)

4. **Can this be used for edge weights x and x+1 (x ≥ 0)?**
   - **Yes** - maintains two consecutive distance levels
   - **Example**: Weights 2 and 3 create distances 2, 3, 4, 5...
   - **This is called 0-X BFS** where X = x+1

5. **Can this be used for edge weights x and y (x, y ≥ 0)?**
   - **No** - unless x and y are consecutive integers
   - **Example**: Weights 1 and 3 would create gaps (distances 1, 3, 4, 6...)
   - **Violates**: The consecutive distance level property

6. **Extension to Dial's Algorithm:**
   - **Generalization**: For edge weights ≤ K, use K+1 buckets
   - **Bucket management**: Cyclic shift when current bucket is empty
   - **Time complexity**: O(K × V + E) instead of O((V + E) log V)

## Algorithm Analysis

| Aspect | Complexity | Notes |
|--------|------------|-------|
| **Time Complexity** | O(V + E) | Each vertex and edge processed once |
| **Space Complexity** | O(V) | For distance array and deque |
| **Queue operations** | O(1) | Deque front/back operations are constant |

### Complexity Breakdown
- **Initialization**: O(V) for distance array
- **Main algorithm**: O(V + E) - each vertex processed once, each edge relaxed once
- **Queue operations**: O(1) for each insertion/removal
- **Total**: O(V + E) dominates

## When to Use 0-1 BFS

**Best for:**
- **Binary edge weights**: Graphs with only 0 and 1 weights
- **Unweighted graphs**: Can be viewed as weight 1 for all edges
- **Performance critical**: When O(V + E) vs O((V + E) log V) matters
- **Grid problems**: Many grid-based shortest path problems

**Not ideal for:**
- **General weights**: Use Dijkstra's for arbitrary positive weights
- **Negative weights**: Use Bellman-Ford algorithm
- **All-pairs queries**: Use Floyd-Warshall algorithm


## Applications

- **Grid shortest path**: Finding minimum steps in 2D grids
- **Network routing**: Binary cost networks
- **Game theory**: Turn-based games with binary costs
- **Image processing**: Binary image analysis
- **Maze solving**: Finding shortest path in mazes
- **Social networks**: Binary relationship graphs

## Implementation Tips

- **Use deque**: Double-ended queue for efficient front/back operations
- **Distance tracking**: Maintain distance array for shortest paths
- **Visited array**: Optional optimization to avoid reprocessing
- **Edge representation**: Ensure clear distinction between 0 and 1 weights

## References

1. [Codeforces - 01 BFS](http://codeforces.com/blog/entry/22276) - Detailed explanation with examples
2. [CP Algorithms - 01 BFS](https://cp-algorithms.com/graph/01_bfs.html) - Algorithm implementation
3. [GeeksforGeeks - 0-1 BFS](https://www.geeksforgeeks.org/0-1-bfs-shortest-path-binary-graph/) - Implementation guide
4. [Wikipedia - Breadth-First Search](https://en.wikipedia.org/wiki/Breadth-first_search) - BFS fundamentals
