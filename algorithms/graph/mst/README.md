---
kind: theory
title: Minimum Spanning Tree
topic_id: algorithms/graph/mst
---

# Minimum Spanning Tree (MST)

A Minimum Spanning Tree is a subset of edges in a connected, weighted, undirected graph that connects all vertices together with the minimum possible total edge weight, without forming any cycles.

## Key Concepts

### Definition
Given a **weighted, undirected graph G** with **V** vertices and **E** edges, find a spanning tree that:
- Connects all vertices
- Has the minimum total weight (sum of edge weights)
- Contains exactly **V-1 edges**
- Forms no cycles

### Spanning Tree Properties
- **Spanning**: Includes all vertices in the graph
- **Tree**: Connected and acyclic (no cycles)
- **Minimum**: Among all possible spanning trees, has the smallest total weight

## Algorithm Comparison

| Algorithm | Time Complexity | Space Complexity | Approach | Best For |
|-----------|----------------|------------------|----------|----------|
| **Kruskal's** | O(E log E) | O(V) | Sort edges, use Union-Find | Sparse graphs |
| **Prim's** | O(E log V) | O(V) | Grow tree from vertex | Dense graphs |

## Properties of Minimum Spanning Trees

### 1. Uniqueness
- **Unique MST**: If all edge weights are distinct, the MST is unique
- **Multiple MSTs**: If some edges have equal weights, multiple MSTs may exist
- **Algorithm Output**: Most algorithms output one of the possible MSTs

### 2. Product Property
The MST is also the tree with the minimum product of edge weights (assuming all weights are positive).

### 3. Maximum Edge Property
In an MST, the maximum weight edge is the minimum possible among all spanning trees of that graph. This is known as the **minimax property**.

### 4. Cycle Property
For any cycle in the graph, the maximum weight edge in that cycle cannot be part of any MST.

### 5. Cut Property
For any cut (partition of vertices into two sets), the minimum weight edge crossing the cut must be in some MST.

### 6. Maximum Spanning Tree
To find the maximum spanning tree (MST with maximum total weight):
- Negate all edge weights
- Run any MST algorithm
- The result is the maximum spanning tree of the original graph

## Common Algorithms

### Kruskal's Algorithm
- **Approach**: Sort edges by weight, add edges greedily using Union-Find
- **Best for**: Sparse graphs (fewer edges)
- **Implementation**: [Kruskal's Algorithm](kruskal/)

### Prim's Algorithm
- **Approach**: Grow tree from a starting vertex, always add minimum weight edge
- **Best for**: Dense graphs (many edges)
- **Implementation**: [Prim's Algorithm](prims/)

## Applications

### Real-World Use Cases
- **Network Design**: Minimize cost of connecting computers, cities, or electrical grids
- **Telecommunications**: Optimize cable/fiber optic network layouts
- **Transportation**: Design efficient road or rail networks
- **Approximation Algorithms**: Used in TSP and Steiner tree approximations
- **Cluster Analysis**: Hierarchical clustering in data mining

### Algorithmic Applications
- **Network Optimization**: Minimize infrastructure costs
- **Graph Simplification**: Reduce graph to essential connections
- **Approximation**: Base for approximating NP-hard problems
- **Image Segmentation**: Computer vision applications

### Complete Problem Set: [LeetCode - Minimum Spanning Tree](https://leetcode.com/tag/minimum-spanning-tree/)

## References

### Comprehensive Guides
- [CP Algorithms - Minimum Spanning Tree](https://cp-algorithms.com/graph/mst_kruskal.html) - Detailed algorithm explanations
- [GeeksForGeeks - Minimum Spanning Tree](https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/) - Implementation examples
- [VisuAlgo - Minimum Spanning Tree](https://visualgo.net/en/mst) - Interactive visualization

### Algorithm Properties & Theory
- [Wikipedia - Minimum Spanning Tree](https://en.wikipedia.org/wiki/Minimum_spanning_tree) - Mathematical properties
- [Khan Academy - Greedy Algorithms](https://www.khanacademy.org/computing/computer-science/algorithms) - Algorithm fundamentals