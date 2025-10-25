# Depth-First Search (DFS)

Depth-First Search is a fundamental graph traversal algorithm that explores as far as possible along each branch before backtracking. It finds the lexicographical first path from a source vertex to each vertex and is particularly useful for path finding, cycle detection, and topological sorting.

## Algorithm Overview

### Purpose
- **Deep exploration**: Explore as far as possible before backtracking
- **Path finding**: Find any path from source to target vertices
- **Lexicographical paths**: Find lexicographically first paths
- **Tree traversal**: Works well for tree structures

### Key Characteristics
- **Stack-based**: Uses recursion or explicit stack
- **Depth-first**: Explores deep before exploring wide
- **Backtracking**: Returns to previous vertices when stuck
- **Works on both directed and undirected graphs**

## How It Works

### Core Concept
DFS explores vertices by going as deep as possible along each path before backtracking:
1. **Start**: Begin from source vertex
2. **Explore**: Go to unvisited neighbor
3. **Recurse**: Continue from new vertex
4. **Backtrack**: Return when no unvisited neighbors
5. **Repeat**: Continue until all vertices visited

### Algorithm Steps
1. **Initialize**: Mark source as visited, add to path
2. **Process**: For current vertex:
   - Process the vertex
   - For each unvisited neighbor:
     - Mark as visited
     - Recursively call DFS
3. **Backtrack**: Remove from path when returning

### Why It Works
- **Exhaustive exploration**: Visits all reachable vertices
- **Path construction**: Builds paths as it explores
- **Memory efficient**: Uses O(depth) space instead of O(vertices)

## Algorithm Analysis

| Aspect | Complexity | Notes |
|--------|------------|-------|
| **Time Complexity** | O(V + E) | Each vertex and edge processed once |
| **Space Complexity** | O(V) | Recursion stack and visited array |
| **Path finding** | O(V + E) | May explore entire graph |

### Complexity Breakdown
- **Vertex processing**: O(V) - each vertex processed once
- **Edge processing**: O(E) - each edge examined once
- **Recursion depth**: O(V) in worst case (linear graph)
- **Total**: O(V + E) dominates

## When to Use DFS

**Best for:**
- **Path finding**: Finding any path between vertices
- **Cycle detection**: Detecting cycles in graphs
- **Topological sorting**: Ordering vertices with dependencies
- **Tree problems**: Natural fit for tree structures
- **Backtracking**: Problems requiring exploration and backtracking

**Not ideal for:**
- **Shortest path**: BFS is better for unweighted graphs
- **Level-order processing**: BFS processes by levels
- **Memory constraints**: Deep graphs may cause stack overflow

## Applications

### Core Applications
1. **Path finding**: Find any path from source to all vertices
2. **Lexicographical paths**: Find lexicographically first paths
3. **Tree operations**: Check if vertex is ancestor of another
4. **LCA finding**: Find lowest common ancestor of two vertices
5. **Topological sorting**: Order vertices with dependencies
6. **Strongly connected components**: Find SCCs in directed graphs
7. **Bridge detection**: Find bridges in undirected graphs

### Advanced Applications
- **Maze solving**: Find path through mazes
- **Puzzle solving**: Explore solution spaces
- **Game tree search**: Explore game states
- **Dependency resolution**: Resolve complex dependencies

## Edge Classification

DFS can classify edges based on entry and exit times, which is crucial for problems like finding bridges and articulation points:

### Classification Rules

#### 1. Tree Edge
- **Condition**: v is not visited when edge (u,v) is examined
- **Property**: v is visited for the first time from u
- **Result**: Forms the DFS tree structure
- **Use**: Building the DFS tree

#### 2. Back Edge
- **Condition**: v is an ancestor of u in DFS tree
- **Property**: v is already entered but not exited when (u,v) is examined
- **Result**: Creates a cycle (path from v to u + edge (u,v))
- **Use**: Cycle detection

#### 3. Forward Edge
- **Condition**: v is a descendant of u in DFS tree
- **Property**: v is already visited and exited, time_in[u] < time_in[v]
- **Result**: Direct path from ancestor to descendant
- **Use**: Path optimization

#### 4. Cross Edge
- **Condition**: v is neither ancestor nor descendant of u
- **Property**: v is already visited and exited, time_in[u] > time_in[v]
- **Result**: Connects different branches of DFS tree
- **Use**: Graph structure analysis

**Note**: Forward edges and cross edges only exist in directed graphs.

## Implementation Considerations

### Data Structures
- **Recursion stack**: Implicit stack for recursive calls
- **Visited array**: Track processed vertices
- **Path array**: Store current path (for backtracking)
- **Time arrays**: Entry/exit times for edge classification

### Common Patterns
- **Backtracking**: Explore and undo decisions
- **Path reconstruction**: Build paths during traversal
- **Cycle detection**: Use edge classification
- **Component finding**: Mark connected components

## Practice Problems

For detailed practice problems organized by difficulty level, see:
- [Beginner Level](practice/1. beginner.md) - Basic DFS traversal problems
- [Intermediate Level](practice/2. intermediate.md) - Advanced DFS applications
- [Advanced Level](practice/3. advanced.md) - Complex DFS variations
- [Patterns & Techniques](practice/0. patterns.md) - Common DFS patterns and problem-solving strategies

## References

1. [CP Algorithms - DFS](https://cp-algorithms.com/graph/depth-first-search.html) - Detailed algorithm explanation
2. [DFS for beginners](https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B) by [StefanPochmann](https://leetcode.com/StefanPochmann/) - Beginner-friendly guide
3. [Wikipedia - Depth-First Search](https://en.wikipedia.org/wiki/Depth-first_search) - Mathematical properties
4. [GeeksforGeeks - DFS](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/) - Implementation guide
