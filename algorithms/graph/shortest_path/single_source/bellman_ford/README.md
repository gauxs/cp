---
kind: theory
title: Bellman-Ford
topic_id: algorithms/graph/shortest_path/single_source/bellman_ford
---

# Bellman-Ford Algorithm

The Bellman-Ford algorithm is a single-source shortest path algorithm that finds the shortest paths from a source vertex to all other vertices in a weighted directed graph. Unlike Dijkstra's algorithm, it can handle **negative weight edges** and detect **negative weight cycles**.

## Algorithm Overview

### Purpose
- **Single-source shortest path**: Find shortest distances from source to all vertices
- **Negative edge handling**: Works with graphs containing negative weights
- **Negative cycle detection**: Identifies if the graph contains negative weight cycles
- **Path reconstruction**: Can be extended to reconstruct actual shortest paths

### Key Characteristics
- **Relaxation-based**: Uses edge relaxation technique
- **Handles negative edges**: Unlike Dijkstra's algorithm
- **Detects negative cycles**: Can identify impossible shortest paths
- **Works on directed graphs**: Primarily designed for directed graphs

## How It Works

### Core Idea
The algorithm uses **relaxation** - repeatedly updating distance estimates by considering all edges. It performs V-1 iterations, where in each iteration, it relaxes all edges. If no negative cycles exist, the shortest paths are found after V-1 iterations.

### Algorithm Steps
1. **Initialize**: Set distance to source as 0, all others as infinity
2. **Relax**: For V-1 iterations, relax all edges
3. **Check**: After V-1 iterations, check for negative cycles
4. **Result**: Shortest distances found (if no negative cycles)

### Relaxation Process
For each edge (u, v) with weight w:
```
if distance[u] + w < distance[v]:
    distance[v] = distance[u] + w
    parent[v] = u
```

## Negative Cycle Detection

### Detection Method
After V-1 iterations, perform one more iteration. If any distance can still be improved, a negative cycle exists.

### Why It Works
- **V-1 iterations**: Sufficient to find shortest paths in graphs without negative cycles
- **Additional iteration**: If distances still improve, there's a negative cycle
- **Impossible paths**: Vertices reachable through negative cycles have distance = -∞

## Important Algorithm Observations

### Critical Thinking Questions
1. **Why does this algorithm work on negative edges?**
   - Unlike Dijkstra's greedy approach, Bellman-Ford considers all edges in each iteration
   - This allows it to "undo" previous decisions when negative edges provide better paths

2. **Will this work on undirected graphs with both negative and positive weights?**
   - **No** - negative edges in undirected graphs create negative cycles of length 2
   - Example: edge (u,v) with weight -5 creates cycle u→v→u with total weight -10

3. **Will this work on undirected graphs with only positive weights?**
   - **Yes** - no negative cycles exist, so algorithm works correctly

4. **If negative cycle exists, will the last relaxed vertex always be inside the cycle?**
   - **Not necessarily** - depends on the order of edge processing
   - The vertex that gets relaxed in the V-th iteration may not be directly in the cycle

5. **Why do we go back N times to find the negative cycle?**
   - Ensures we reach a vertex that's definitely part of the negative cycle
   - Going back N times guarantees we enter the cycle from any starting point

6. **After going back N times, will the previous edge always be negative?**
   - **Not always** - the edge might be positive, but the cycle as a whole has negative weight
   - The negative cycle detection relies on the total cycle weight, not individual edges

## Algorithm Analysis

| Aspect | Complexity | Notes |
|--------|------------|-------|
| **Time Complexity** | O(V × E) | V-1 iterations, each relaxing E edges |
| **Dense Graph** | O(V³) | When E ≈ V² |
| **Space Complexity** | O(V) | For distance and parent arrays |

### Complexity Breakdown
- **Initialization**: O(V) for distance array
- **Main algorithm**: O(V × E) for V-1 iterations
- **Negative cycle check**: O(E) for one additional iteration
- **Total**: O(V × E) dominates

## When to Use Bellman-Ford

**Best for:**
- **Negative edges**: Graph contains negative weights
- **Negative cycle detection**: Need to identify impossible paths
- **Small graphs**: When V × E is manageable
- **Single-source queries**: Need shortest paths from one source

**Not ideal for:**
- **Large graphs**: O(V × E) can be slow
- **Positive weights only**: Dijkstra's algorithm is more efficient
- **All-pairs queries**: Floyd-Warshall might be better

## Comparison with Other Algorithms

| Algorithm | Time Complexity | Handles Negative Edges | Detects Negative Cycles |
|-----------|----------------|----------------------|------------------------|
| **Dijkstra's** | O((V + E) log V) | No | No |
| **Bellman-Ford** | O(V × E) | Yes | Yes |
| **Floyd-Warshall** | O(V³) | Yes | Yes |

## Applications

- **Network routing**: Finding shortest paths in networks with negative costs
- **Arbitrage detection**: Finding profitable currency exchange cycles
- **Game theory**: Optimal strategies in games with negative outcomes
- **Circuit analysis**: Electrical networks with negative resistances
- **Financial modeling**: Risk analysis with negative correlations

## References

1. [CP Algorithms - Bellman-Ford](https://cp-algorithms.com/graph/bellman_ford.html) - Detailed algorithm explanation
2. [Wikipedia - Bellman-Ford Algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) - Mathematical properties
3. [GeeksforGeeks - Bellman-Ford](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/) - Implementation guide
