# Topological Sort
Find a permutation of the vertices (topological order) which corresponds to the order defined by all edges of the graph.

Topological order can be ***non-unique*** (for example, if the graph is empty; or if there exist three vertices a, b, c for which there exist paths from a to b and from a to c but not paths from b to c or from c to b).

Topological order ***may not exist*** at all if the graph contains cycles (because there is a contradiction: there is a path from a to b and vice versa).

A common problem in which topological sorting occurs is the following:
```
There are n variables with unknown values. For some variables we know that one of them is less than the other. You have to check whether these constraints are contradictory, and if not, output the variables in ascending order (if several answers are possible, output any of them). It is easy to notice that this is exactly the problem of finding topological order of a graph with n vertices.
```

## Algorithm Analysis
```
N - number of graph nodes
M - number of edges

Time Complexity:         O(N + M)
Space Complexity:        O(N)
```

## Applications
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, applications of this type arise in:
- logic synthesis
- data serialization
- instruction scheduling
- resolving symbol dependencies in linkers\
- determining the order of compilation tasks to perform in make files
- ordering of formula cell evaluation when recomputing formula values in spreadsheets

## References
- https://cp-algorithms.com/graph/topological-sort.html
- https://www.geeksforgeeks.org/topological-sorting/