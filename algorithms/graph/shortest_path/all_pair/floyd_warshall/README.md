---
kind: theory
title: Floyd-Warshall
topic_id: algorithms/graph/shortest_path/all_pair/floyd_warshall
---

# Floyd-Warshall Algorithm

The Floyd-Warshall algorithm is a dynamic programming approach that finds the shortest paths between all pairs of vertices in a weighted graph. It works on both **directed** and **undirected** graphs and can handle negative weight edges, but **NOT** negative weight cycles.

## Algorithm Overview

### Purpose
- **All-pairs shortest path**: Find shortest distance between every pair of vertices
- **Negative cycle detection**: Identify if the graph contains negative weight cycles
- **Path reconstruction**: Can be extended to reconstruct actual shortest paths

### Key Characteristics
- **Dynamic Programming**: Uses optimal substructure property
- **Handles negative edges**: Unlike Dijkstra's algorithm
- **Detects negative cycles**: Can identify impossible shortest paths
- **Dense graph friendly**: O(V³) complexity makes it suitable for dense graphs

## How It Works

### Core Idea
The algorithm uses the principle of **relaxation through intermediate vertices**. For each pair of vertices (i, j), it considers all possible intermediate vertices k and updates the shortest path if going through k yields a better result.

### Algorithm Steps
1. **Initialize**: Create distance matrix with direct edge weights
2. **Relaxation**: For each intermediate vertex k, update all pairs (i, j)
3. **Update rule**: `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`

### Important Observation
Before the k-th phase, the distance matrix stores the shortest path between vertices i and j that contains only vertices **1, 2, 3, ..., k-1** as internal vertices. This means:
- **Outer loop**: k (intermediate vertices)
- **Inner loops**: i and j (all pairs)

## Negative Cycle Detection

### Detection Method
Run Floyd-Warshall algorithm on the graph. Initially `distances[v][v] = 0` for each vertex v. After running the algorithm, `distances[v][v] < 0` if there exists a negative length path from v to v.

### Finding Affected Pairs
For pairs of vertices where shortest path doesn't exist (due to negative cycles):
1. Run the usual Floyd-Warshall algorithm
2. A shortest path between vertices i and j doesn't exist if and only if there's a vertex t that is:
   - Reachable from i
   - Can reach j  
   - Has `distances[t][t] < 0` (part of negative cycle)

### Handling Impossible Paths
For vertices affected by negative cycles, the algorithm can be improved to output **-INF** instead of arbitrary negative values. This indicates that the path can have arbitrarily small weight.

## Algorithm Analysis

| Aspect | Complexity | Notes |
|--------|------------|-------|
| **Time Complexity** | O(V³) | Three nested loops over all vertices |
| **Space Complexity** | O(V²) | Distance matrix storage |
| **Path Reconstruction** | O(V²) additional | If storing parent/ancestor information |

### Complexity Breakdown
- **Initialization**: O(V²) for distance matrix
- **Main algorithm**: O(V³) for three nested loops
- **Negative cycle check**: O(V) additional
- **Total**: O(V³) dominates

## When to Use Floyd-Warshall

**Best for:**
- **Dense graphs**: When E ≈ V²
- **All-pairs queries**: Need shortest path between many pairs
- **Negative edges**: Graph contains negative weights
- **Negative cycle detection**: Need to identify impossible paths

**Not ideal for:**
- **Sparse graphs**: Dijkstra's or Bellman-Ford more efficient
- **Single-source queries**: Dijkstra's algorithm is better
- **Large graphs**: O(V³) can be prohibitive

## Applications

- **Network routing**: Finding optimal routes between all nodes
- **Social network analysis**: Shortest connection paths
- **Game theory**: Optimal strategies in graph-based games
- **Circuit analysis**: Electrical network analysis
- **Image processing**: Distance transforms

## References

1. [CP Algorithms - Floyd-Warshall](https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html) - Detailed algorithm explanation
2. [CP Algorithms - Finding Negative Cycles](https://cp-algorithms.com/graph/finding-negative-cycle-in-graph.html) - Negative cycle detection
3. [Wikipedia - Floyd-Warshall Algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) - Mathematical properties
4. [GeeksforGeeks - Floyd-Warshall](https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/) - Implementation guide

## Implementation Notes

### Pending Improvements
- [ ] Fix the logic of `print_path` function
- [ ] Implement negative cycle vertex detection: Currently we only detect if negative cycle exists (d[v][v] < 0), but need to find the actual cycle vertices and path