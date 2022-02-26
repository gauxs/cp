# Minimum spanning trees
Given a **weighted, undirected graph** **G** with **V** vertices and **E** edges, find a spanning tree of this graph which connects all vertices and has the least weight (i.e. the sum of weights of edges is minimal). 

A **spanning tree** is a set of edges such that any vertex can reach any other by exactly one simple path. The spanning tree with the least weight is called a **minimum spanning tree**. Any spanning tree will **necessarily** contain V−1 edges.

## Properties of the minimum spanning tree
1. A minimum spanning tree of a graph is unique, if the weight of all the edges are distinct. Otherwise, there may be multiple minimum spanning trees. (Specific algorithms typically output one of the possible minimum spanning trees).

2. Minimum spanning tree is also the tree with minimum product of weights of edges.

3. In a minimum spanning tree of a graph, the maximum weight of an edge is the minimum possible from all possible spanning trees of that graph.

4. The maximum spanning tree (spanning tree with the sum of weights of edges being maximum) of a graph can be obtained similarly to that of the minimum spanning tree, by changing the signs of the weights of all the edges to their opposite and then applying any of the minimum spanning tree algorithm.