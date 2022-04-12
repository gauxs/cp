# Graph Theory

## Connected Components

In graph theory, a component of an **undirected graph** is an induced subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the rest of the graph. For example, the graph shown in the illustration has three components.

A vertex with no incident edges is itself a component. A graph that is itself connected has exactly one component, consisting of the whole graph. Components are also sometimes called **connected components**. For undirected graphs there is the notion of connected components, which you find by performing a DFS on the undirected graph.

<img src="https://github.com/gauxs/cp/blob/master/media/images/component_graph.png?raw=true" width="600" height="300">

## Strongly Connected Components

A **directed graph** is called strongly connected if there is a path in each direction between each pair of vertices of the graph. That is, a path exists from the first vertex in the pair to the second, and another path exists from the second vertex to the first.

In a directed graph G that may not itself be strongly connected, a pair of vertices u and v are said to be strongly connected to each other if there is a path in each direction between them.

For directed graphs there is the notion of strongly connected components, for which multiple algorithms are available like **Kosaraju's algorithm**, **Tarjan’s Algorithm**, all slightly more complicated than a simple DFS.

## Cycle Decomposition

The process of break down the graph into cycles is called **cycle decomposition**.

## Practice

| **S.No** | **Warmup** | **Challenging**                                                                          |
| -------- | ---------- | ---------------------------------------------------------------------------------------- |
| 1        |            | [Leetcode - K similar strings](https://leetcode.com/problems/k-similar-strings)          |
| 2        |            | [Leetcode - Couples holding hands](https://leetcode.com/problems/couples-holding-hands/) |

**Note**:

1. [Leetcode - K similar strings](https://leetcode.com/problems/k-similar-strings) can be solved in 3 ways:
   - Generate a graph from each possible permutation of source string where each edge will represent 1 swap, then run bfs from start node to destination, the path length will be shortest swaps
   - Swap the source at those position which will bring us to those permutation which can give us answer while discarding other needless permutation, also keep track of already visited permutations, [my submission](https://leetcode.com/submissions/detail/678713606/)
   - The problem is essentially finding maximum number of cycles in the graph, number os edges in one cycle - 1 will give us the number of swaps to decompose one cycle. Finding this for all the cycles will be minimum number os swaps. Implementing this is a bit tricky
