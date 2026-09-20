---
kind: theory
title: Kruskal's Algorithm
topic_id: algorithms/graph/mst/kruskal
---

# Kruskal's Algorithm

Kruskal's algorithm is a greedy algorithm that finds a minimum spanning tree by building the MST edge by edge, always choosing the smallest weight edge that doesn't create a cycle.

## Algorithm Overview

### Approach
1. **Initialize**: Start with a forest where each vertex is its own tree
2. **Sort**: Sort all edges by weight in non-decreasing order
3. **Build MST**: Iterate through sorted edges
   - If the edge connects two different trees, add it to the MST
   - Use Union-Find to efficiently check and merge trees
4. **Result**: After processing all edges, the selected edges form the MST

### Key Characteristics
- **Edge-based**: Focuses on edges rather than vertices
- **Global view**: Considers all edges at each step
- **Union-Find dependency**: Requires disjoint set data structure
- **Best for sparse graphs**: Efficient when E is small relative to V^2

## How It Works

The algorithm starts with V separate trees (one for each vertex) and gradually merges them by adding edges in order of increasing weight. The Union-Find data structure efficiently:
- Checks if two vertices belong to different trees
- Merges two trees when an edge is added

If the graph is disconnected, the algorithm will produce a minimum spanning forest, and the number of selected edges will be less than V-1.

## Algorithm Analysis

| Aspect | Complexity | Notes |
|--------|------------|-------|
| **Time Complexity** | O(E log E) | Dominated by sorting edges |
| **Equivalent** | O(E log V) | Since E ≤ V^2, log E = O(log V) |
| **Space Complexity** | O(V) | For Union-Find parent array |

### Complexity Breakdown
- **Sorting edges**: O(E log E)
- **Union-Find operations**: O(E α(V)) where α is inverse Ackermann (nearly constant)
- **Total**: O(E log E) dominates

## When to Use Kruskal's

**Best for:**
- **Sparse graphs**: When E is much smaller than V^2
- **Pre-sorted edges**: If edges are already sorted
- **Edge list representation**: When graph is stored as edge list

**Not ideal for:**
- **Dense graphs**: Prim's algorithm is better when E ≈ V^2
- **Adjacency matrix**: Prim's is more natural for this representation

## References

1. [CP Algorithms - Kruskal](https://cp-algorithms.com/graph/mst_kruskal.html) - Detailed algorithm explanation
2. [HackerEarth - Minimum Spanning Tree](https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/) - Tutorial with examples
3. [Wikipedia - Kruskal's Algorithm](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm) - Mathematical properties