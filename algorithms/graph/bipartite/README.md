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

## Practice Problems

### Beginner Level
1. [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/) - Basic bipartite checking
2. [Possible Bipartition](https://leetcode.com/problems/possible-bipartition/) - Bipartite with constraints

### Intermediate Level
1. [Divide Array Into Equal Pairs](https://leetcode.com/problems/divide-array-into-equal-pairs/) - Bipartite matching concept
2. [Minimum Number of Vertices to Reach All Nodes](https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/) - Graph partitioning

### Advanced Level
1. [Maximum Bipartite Matching](https://www.geeksforgeeks.org/maximum-bipartite-matching/) - Advanced bipartite algorithms
2. [Minimum Vertex Cover](https://www.geeksforgeeks.org/vertex-cover-problem-set-1-introduction-approximate-algorithm-2/) - Bipartite graph applications

### Complete Problem Set: [LeetCode - Graph Bipartite](https://leetcode.com/tag/bipartite/)

## Applications

### Real-World Use Cases
- **Social Networks**: Modeling relationships between two distinct groups
- **Job Assignment**: Matching workers to tasks
- **Resource Allocation**: Assigning resources to users
- **Network Flow**: Maximum flow problems
- **Scheduling**: Time slot assignments

### Algorithmic Applications
- **Maximum Bipartite Matching**: Find maximum number of edges with no shared vertices
- **Minimum Vertex Cover**: Find minimum vertices to cover all edges
- **Network Flow**: Convert to flow network problems
- **Graph Coloring**: Two-coloring problems

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