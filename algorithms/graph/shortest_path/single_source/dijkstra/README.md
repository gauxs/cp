# Dijkstra
You are given a directed or undirected weighted graph with **V** vertices and **E** edges. The weights of all edges are **non-negative**. You are also given a starting vertex **s**. Find the lengths of the shortest paths from a starting vertex **s** to all other vertices. The basics and working of the algorithm can be learned from ***references*** below.

<img src="https://github.com/gauxs/cp/blob/master/media/images/dijkstra.jpg?raw=true" width="800" height="600">

Following are some important observation on the algorithm:
1. Once a vertex is **relaxed** it will not be picked again (by design and not by implementation). This means that algorithm is sure that there are no other **shorter path** to this vertex present in graph. Why can't we find a more shorter path?
2. If we modify this algorithm and pick any vertex(instead of minimum), the algorithm will still work but time complexity will increase. This is because we can keep finding **shorter paths** to this vertex in future iterations. Why will the complexity increase?
4. Why doesn't this algorithm work on *-ve edges* and on *-ve cycles*?
5. Why does this algorithm work on both directed and undirected graphs?

### Algorithm Analysis
```
N - number of graph nodes
M - number of edges

Time Complexity - dijkstra:         O(V^2 + E)                              // for dense graph E ≈ V^2
Space Complexity - dijkstra:        O(V)

Time Complexity - dijkstra_set:     O(Vlog(V) + Elog(V)) = O(Elog(V))       // for dense graph E ≈ V^2
Space Complexity - dijkstra_set:    O(V)
```

Dijkstra is a **greedy** algorithm. It is clear, that the complexity of first algorithm i.e. dijkstra() is optimal for a dense graph, i.e. when E ≈ V^2. However in sparse graphs, when **E** is much smaller than **V^2**, the complexity gets less optimal because of the first term **V^2**. Thus it is necessary to improve the execution time of **finding minimum distance vertex**.

To accomplish this we can use a variation of multiple auxiliary data structures like set (implemented in dijkstra_set()), priority queue, fibonacci heaps.
1. If we implement this algorithm via **min heap**, it will not be trivial to remove a vertex from min heap once its distance is further reduced. To do this we will have to implement **custom min heap** with delete operation, which is not trivial. When implementing this algorithm generally deleting a node which is further relaxed is **SKIPPED**, thus allowing us to use standard library implementations of min heap. These undeleted nodes are called **dead nodes**, and their existense in the min heap **practically** increases the complexity. **Think, how do we handle a case when a *dead node* is picked for relaxation?**

2. Since we need to store vertices ordered by their values **distances[]**, it is convenient to store actual pairs: the distance and the index of the vertex. As a result in set implementation, pairs are automatically sorted by their distances.

3. In set implementation, We don't need the vector **picked**. We will use the set to store that information, and also find the vertex with the shortest distance with it.

## Practice
| **S.No** 	|                                **Warmup**                               	|                                                  **Challenging**                                                  	|
|:--------:	|:-----------------------------------------------------------------------:	|:-----------------------------------------------------------------------------------------------------------------:	|
|     1    	| [Network delay time](https://leetcode.com/problems/network-delay-time/) 	|         [Cheapest flights within k stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/)         	|
|     2    	|                                                                         	| [Number of ways to arrive at destination](https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/) 	|

## References
1. [A noob's guide to Djikstra's algorithm](https://leetcode.com/discuss/general-discussion/1059477/A-noob's-guide-to-Djikstra's-Algorithm) by [@bliss14b](https://leetcode.com/bliss14b/)
2. [CP Algorithms - Dijkstra](https://cp-algorithms.com/graph/dijkstra.html)
