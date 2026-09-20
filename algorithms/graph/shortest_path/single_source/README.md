---
kind: category
title: Single Source
topic_id: algorithms/graph/shortest_path/single_source
---

# Single-Source Shortest Path Algorithms

You are given a directed or undirected weighted graph with **V** vertices and **E** edges. You are also given a starting vertex **s**. Find the lengths of the shortest paths from a starting vertex **s** to all other vertices. This problem is also called **single-source shortest paths problem**.

## Algorithm Comparison

| Algorithm | Time Complexity | Space Complexity | Edge Weights | Negative Cycles | Best For |
|-----------|----------------|------------------|--------------|-----------------|----------|
| **BFS** | O(V + E) | O(V) | Unweighted (1) | No | Unweighted graphs |
| **0-1 BFS** | O(V + E) | O(V) | 0 and 1 | No | Binary weighted graphs |
| **Dijkstra's** | O((V + E) log V) | O(V) | Positive | No | General positive weights |
| **Bellman-Ford** | O(V × E) | O(V) | Any | Yes (detects) | Negative weights, cycle detection |

## Detailed Algorithm Analysis

### BFS (Breadth-First Search)
- **Use case**: Unweighted graphs or graphs where all edges have weight 1
- **Approach**: Level-by-level traversal using queue
- **Limitations**: Cannot handle arbitrary weights
- **Implementation**: Standard queue-based BFS

### 0-1 BFS
- **Use case**: Graphs with edge weights 0 or 1 only
- **Approach**: Deque-based with front/back insertion
- **Key insight**: Maintains vertices at distances x and x+1 only
- **Advantage**: Linear time complexity for binary weights
- **Implementation**: Double-ended queue (deque)

### Dijkstra's Algorithm
- **Use case**: Graphs with non-negative edge weights
- **Approach**: Greedy with priority queue
- **Key insight**: Always processes closest unvisited vertex first
- **Limitation**: Cannot handle negative weights
- **Implementation**: Priority queue (heap)

### Bellman-Ford Algorithm
- **Use case**: Graphs with any edge weights (including negative)
- **Approach**: Relaxation-based with V-1 iterations
- **Key insight**: Can detect negative cycles
- **Advantage**: Handles negative weights and detects cycles
- **Implementation**: Edge relaxation with distance array

## When to Choose Which Algorithm

### Choose **BFS** when:
- Graph is unweighted
- All edges have weight 1
- You need the shortest path in terms of number of edges

### Choose **0-1 BFS** when:
- Graph has only edge weights 0 and 1
- You need linear time complexity
- Grid-based problems with binary costs

### Choose **Dijkstra's** when:
- Graph has non-negative edge weights
- You need efficient shortest paths
- Graph is dense (E ≈ V²)

### Choose **Bellman-Ford** when:
- Graph has negative edge weights
- You need to detect negative cycles
- Graph is sparse (E << V²)

## Complexity Trade-offs

| Scenario | Best Algorithm | Reason |
|----------|----------------|---------|
| **Unweighted graph** | BFS | O(V + E) - optimal |
| **Binary weights (0,1)** | 0-1 BFS | O(V + E) - optimal |
| **Positive weights, dense** | Dijkstra's | O((V + E) log V) - efficient |
| **Positive weights, sparse** | Dijkstra's | O((V + E) log V) - still good |
| **Negative weights** | Bellman-Ford | O(V × E) - only option |
| **Negative cycle detection** | Bellman-Ford | O(V × E) - only option |

## Implementation Considerations

### Data Structures
- **BFS**: Queue
- **0-1 BFS**: Deque (double-ended queue)
- **Dijkstra's**: Priority queue (heap)
- **Bellman-Ford**: Array for distances

### Memory Usage
- All algorithms use O(V) space for distance tracking
- Dijkstra's uses additional O(V) for priority queue
- 0-1 BFS uses O(V) for deque

### Edge Cases
- **Disconnected graphs**: All algorithms handle gracefully
- **Negative cycles**: Only Bellman-Ford can detect
- **Self-loops**: All algorithms handle correctly
- **Multiple edges**: All algorithms handle correctly

## Practice Problems

For detailed practice problems organized by difficulty level, see:
- [Beginner Level](practice/1. beginner.md) - Basic shortest path problems
- [Intermediate Level](practice/2. intermediate.md) - Advanced shortest path variations
- [Advanced Level](practice/3. advanced.md) - Complex shortest path applications
- [Patterns & Techniques](practice/0. patterns.md) - Common patterns and problem-solving strategies