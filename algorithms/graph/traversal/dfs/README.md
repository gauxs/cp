# Depth First Search
Depth First Search finds the lexicographical first path in the graph from a source vertex u to each vertex. Depth First Search will also find the shortest paths in a tree (because there only exists one simple path), but on general graphs this is not the case.

### Algorithm Analysis
```
    V - number of vertices
    E - number of edges

    Time complexity:    O(V+E)
    Space complexity:   O(V)   
```

### Applications
1. Find any path in the graph from source vertex **s** to all vertices.
2. Find lexicographical first path in the graph from source **s** to all vertices.
3. Check if a vertex in a tree is an ancestor of some other vertex:
4. Find the lowest common ancestor (LCA) of two vertices.
5. Topological sorting.
6. Find strongly connected components in a directed graph
7. Find bridges in an undirected graph

### Classification of edges
We can classify the edges using the entry and exit time of the end nodes **u** and **v** of the edges **(u, v)**. These classifications are often used for problems like finding **bridges** and **finding articulation points**. We perform a DFS and classify the encountered edges using the following rules:

If **v** is not visited:

**Tree Edge** - If **v** is visited after **u** then edge (u,v) is called a tree edge. In other words, if **v** is visited for the first time and **u
** is currently being visited then (u,v) is called tree edge. These edges form a DFS tree and hence the name tree edges.

If **v** is visited before **u**:

**Back edges** - If **v** is an ancestor of **u**, then the edge (u,v) is a back edge. **v** is an ancestor exactly if we already entered , but not exited it yet. Back edges complete a cycle as there is a path from ancestor **v** to descendant **u** (in the recursion of DFS) and an edge from descendant **u** to ancestor **v** (back edge), thus a cycle is formed. Cycles can be detected using back edges.

**Forward Edges** - If **v** is a descendant of **u**, then edge (u,v) is a forward edge. In other words, if we already visited and exited **v** and time_in[u]<time_in[v] then the edge (u,v) forms a forward edge.

**Cross Edges** -  If **v** is neither an ancestor or descendant of **u**, then edge (u,v) is a cross edge. In other words, if we already visited and exited **v** and time_in[u]>time_in[v] then (u,v) is a cross edge.

**Note:** Forward edges and cross edges only exist in directed graphs.

### Practice
1. Practice questions - [Leetcode - Depth First Search](https://leetcode.com/tag/depth-first-search/)
2. Good questions - [Number of enclaves](https://leetcode.com/problems/number-of-enclaves/) | [Find eventual safe states](https://leetcode.com/problems/find-eventual-safe-states/)

## References
1. [CP Algorithms - DFS](https://cp-algorithms.com/graph/depth-first-search.html)
