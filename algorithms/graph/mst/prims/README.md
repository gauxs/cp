---
kind: theory
title: Prim's Algorithm
topic_id: algorithms/graph/mst/prims
---

# Prim's Algorithm

Prim's algorithm is a greedy algorithm that finds a minimum spanning tree by growing the MST one vertex at a time, always adding the minimum weight edge that connects a vertex in the tree to a vertex outside the tree.

## Algorithm Overview

### Approach
1. **Initialize**: Start with an arbitrary vertex as the initial tree
2. **Grow tree**: Repeatedly add the minimum weight edge connecting:
   - One endpoint in the current tree (already selected)
   - Other endpoint outside the tree (not yet selected)
3. **Update**: After adding each edge, update the minimum edge weights to all unvisited vertices
4. **Result**: Continue until all vertices are in the tree

### Key Characteristics
- **Vertex-based**: Focuses on growing from vertices rather than considering all edges
- **Local view**: Only considers edges connected to current tree
- **Priority queue dependency**: Requires efficient minimum edge selection
- **Best for dense graphs**: Efficient when E is close to V^2

## How It Works

The algorithm maintains a growing tree that starts from a single vertex. At each step, it selects the minimum weight edge that expands the tree by one vertex. A priority queue (or set) efficiently tracks the minimum weight edge to each unvisited vertex.

If the graph is disconnected, the algorithm will only produce an MST for the connected component containing the starting vertex, and the number of selected edges will be less than V-1.

## Algorithm Analysis

| Aspect | Complexity | Notes |
|--------|------------|-------|
| **Time Complexity (with deletion)** | O((V + E) log V) | Using set/priority queue with edge deletion |
| **Time Complexity (without deletion)** | O((V + E) log E) | Allowing duplicate entries in priority queue |
| **Equivalent** | O(E log V) | For connected graphs, since E ≥ V-1 |
| **Space Complexity** | O(V) | For priority queue and distance tracking |

### Complexity Breakdown
- **Vertex selection**: V operations at O(log V) each
- **Edge relaxation**: E operations at O(log V) each
- **Total**: O((V + E) log V)

### Implementation Variants
1. **With edge deletion**: Remove/update edges when better paths found - O((V + E) log V)
2. **Without edge deletion**: Allow duplicates in queue, skip outdated entries - O((V + E) log E)
3. **Binary heap**: Standard priority queue implementation
4. **Fibonacci heap**: Theoretical O(E + V log V) but complex in practice

## When to Use Prim's

**Best for:**
- **Dense graphs**: When E is close to V^2
- **Adjacency matrix**: Natural fit for this representation
- **Starting from specific vertex**: When you want to build from a particular point

**Not ideal for:**
- **Sparse graphs**: Kruskal's is better when E is much smaller than V^2
- **Edge list representation**: Kruskal's is more natural

## Comparison with Kruskal's

| Aspect | Prim's | Kruskal's |
|--------|--------|-----------|
| **Approach** | Vertex-centric | Edge-centric |
| **Data structure** | Priority queue | Union-Find |
| **Best for** | Dense graphs | Sparse graphs |
| **Complexity** | O(E log V) | O(E log E) |

## References

1. [CP Algorithms - Prim's](https://cp-algorithms.com/graph/mst_prim.html) - Detailed algorithm explanation
2. [HackerEarth - Minimum Spanning Tree](https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/) - Tutorial with examples
3. [GeeksForGeeks - Prim's](https://www.geeksforgeeks.org/prims-mst-for-adjacency-list-representation-greedy-algo-6/) - Implementation guide
4. [Wikipedia - Prim's Algorithm](https://en.wikipedia.org/wiki/Prim%27s_algorithm) - Mathematical properties