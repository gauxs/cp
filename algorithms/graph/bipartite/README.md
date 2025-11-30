# Bipartite Graph

A bipartite graph is a graph whose vertices can be divided into two disjoint sets so that every edge connects two vertices from different sets (i.e. there are no edges which connect vertices from the same set). These sets are usually called **sides** or **partitions**.

## Key Properties

### Definition
- **Bipartite**: A graph is bipartite if and only if it is **two-colorable**
- **No odd cycles**: A graph is bipartite if and only if all its cycles have even length
- **Vertex coloring**: Can be colored with exactly 2 colors such that no adjacent vertices have the same color

### Examples
- **Bipartite**: Tree, even-length cycle, complete bipartite graph (K_{m,n})
- **Not Bipartite**: Odd-length cycle, any graph with odd-length cycle

## Algorithm Analysis

| Aspect | Complexity | Notes |
|--------|------------|-------|
| **Time Complexity** | O(V + E) | DFS/BFS traversal |
| **Space Complexity** | O(V) | For recursion stack and color array |
| **Approach** | Graph Coloring | Two-color the graph using DFS/BFS |

## Bipartite Matching Algorithms

### Why Bipartite Structure Enables Efficient Matching

The bipartite structure (two distinct partitions) enables specialized algorithms that are much more efficient than general graph matching:

1. **Clear partition separation**: Left and right partitions are distinct, enabling directional algorithms
2. **No odd cycles**: Ensures augmenting paths can be found efficiently
3. **Natural flow structure**: Left→Right flow is well-defined
4. **Matrix representation**: Can represent as cost/adjacency matrix

### Algorithm Comparison

| Algorithm | Type | Complexity | When to Use |
|-----------|------|------------|-------------|
| **Hopcroft-Karp** | Unweighted | O(√V × E) | Fastest for unweighted bipartite matching |
| **Hungarian** | Weighted | O(V³) | Optimal weighted bipartite matching |
| **Network Flow** | Both | O(V²E) or O(VE²) | Flexible, works for both weighted/unweighted |
| **DFS-based** | Unweighted | O(VE) | Simple implementation, good for small graphs |

**Key point**: These algorithms are specifically designed for bipartite graphs and would not work efficiently (or at all) for general graphs.

## Practice Problems

### Complete Problem Set: [LeetCode - Graph Bipartite](https://leetcode.com/tag/bipartite/)

## Applications

### 1. Maximum Bipartite Matching
**Problem**: Find maximum edges with no shared vertices (one-to-one matching).

**Why bipartite?** Matching problems are naturally bipartite - you match entities from one partition to another. The bipartite structure enables efficient algorithms.

#### Hopcroft-Karp Algorithm (Unweighted Bipartite Matching)
**How it works for bipartite graphs:**
1. **Alternating paths**: Find paths that alternate between matched and unmatched edges
2. **Augmenting paths**: Find paths from unmatched left vertex to unmatched right vertex
3. **BFS from left**: Start BFS from all unmatched left vertices
4. **Flip edges**: When augmenting path found, flip matched↔unmatched edges
5. **Repeat**: Until no more augmenting paths exist

**Why bipartite structure helps:**
- Clear left/right separation enables efficient BFS exploration
- Alternating paths are well-defined (left→right→left→right)
- Can find multiple augmenting paths in one BFS pass

**Complexity**: O(√V × E) - much faster than general graph matching

#### Hungarian Algorithm (Weighted Bipartite Matching)
**How it works for bipartite graphs:**
1. **Cost matrix**: Left partition (rows) × Right partition (columns)
2. **Row/column operations**: Subtract minimum from rows/columns to create zeros
3. **Cover zeros**: Find minimum lines to cover all zeros
4. **Augment matching**: If lines < n, adjust costs and repeat
5. **Optimal matching**: When n lines cover all zeros, matching is optimal

**Why bipartite structure helps:**
- Cost matrix naturally represents left→right relationships
- Row/column operations exploit bipartite structure
- Guaranteed to find optimal matching in polynomial time

**Complexity**: O(V³) - efficient for weighted bipartite matching

#### Network Flow Approach
**Transformation for bipartite graphs:**
1. Add source → connect to all left partition vertices
2. Add sink → connect all right partition vertices to sink
3. Set all original edge capacities to 1
4. Run max-flow algorithm (Ford-Fulkerson, Edmonds-Karp, Dinic's)
5. Maximum flow = maximum matching size

**Why bipartite structure helps:**
- Natural source-sink separation (left = sources, right = sinks)
- Simple capacity assignment (all edges = 1)
- Max-flow algorithms are highly optimized

**Use Cases**: Job assignment (workers→tasks), dating apps (users→matches), resource allocation

**Key insight**: These algorithms are specifically designed for bipartite graphs and exploit the two-partition structure for efficiency.

### 2. Minimum Vertex Cover
**Problem**: Find minimum vertices to cover all edges.

**Algorithm**: Use **König's Theorem** - minimum vertex cover = maximum matching size
- Find max matching → derive min vertex cover
- **Complexity**: O(√V × E) via Hopcroft-Karp

**Use Cases**: Network security (min nodes to monitor), resource optimization, facility location

**Why bipartite helps**: König's theorem provides polynomial-time solution (NP-hard in general graphs)

### 3. Constraint Satisfaction / 2-Coloring
**Problem**: Determine if graph can be 2-colored (no adjacent vertices same color).

**Algorithm**: DFS/BFS coloring - O(V + E)
- Alternate colors during traversal
- Conflict detection = not bipartite

**Use Cases**: Scheduling conflicts, team assignment, constraint satisfaction problems

**Why bipartite helps**: 2-colorability = bipartiteness (fundamental equivalence)

### 4. Network Flow Transformation
**Problem**: Convert bipartite problems to max-flow for efficient solving.

**Transformation**: Source → Left partition → Right partition → Sink
- Set edge capacities based on constraints
- Solve using Ford-Fulkerson, Edmonds-Karp, or Dinic's

**Use Cases**: Maximum matching, assignment problems, transportation optimization

**Why bipartite helps**: Natural source-sink separation simplifies flow network construction

## References

### Comprehensive Guides
- [CP Algorithms - Bipartite](https://cp-algorithms.com/graph/bipartite-check.html) - Detailed algorithm explanation
- [GeeksForGeeks - Bipartite Graph](https://www.geeksforgeeks.org/bipartite-graph/) - Implementation and examples
- [VisuAlgo - Bipartite Graph](https://visualgo.net/en/bipartite) - Interactive visualization

### Algorithm Properties & Theory
- [Wikipedia - Bipartite Graph](https://en.wikipedia.org/wiki/Bipartite_graph) - Mathematical properties
- [Khan Academy - Graph Theory](https://www.khanacademy.org/computing/computer-science/algorithms/graph-representation) - Graph theory fundamentals
- [MIT OpenCourseWare - Graph Algorithms](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-006-introduction-to-algorithms-fall-2011/) - Advanced graph algorithms

### Implementation Resources
- [LeetCode - Bipartite Problems](https://leetcode.com/tag/bipartite/) - Practice problems
- [Codeforces - Bipartite Matching](https://codeforces.com/blog/entry/17066) - Competitive programming perspective
- [TopCoder - Bipartite Graphs](https://www.topcoder.com/thrive/articles/Bipartite%20Graphs) - Advanced techniques