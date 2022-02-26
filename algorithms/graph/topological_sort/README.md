# Topological Sort
Find a permutation of the vertices (topological order) which corresponds to the order defined by all edges of the graph.

1. Topological order can be **non-unique** (for example, if the graph is empty; or if there exist three vertices a, b, c for which there exist paths from a to b and from a to c but not paths from b to c or from c to b).

2. Topological order **may not exist** at all if the graph contains cycles (because there is a contradiction: there is a path from a to b and vice versa).

A common problem in which topological sorting occurs is the following:
```
There are n variables with unknown values. For some variables we know that one of them is less than the other. You have to check whether these constraints are contradictory, and if not, output the variables in ascending order (if several answers are possible, output any of them). It is easy to notice that this is exactly the problem of finding topological order of a graph with n vertices.
```

### Algorithm Analysis
```
V - number of graph nodes
E - number of edges

Time Complexity:         O(V + E)
Space Complexity:        O(V)
```

### Applications
Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, applications of this type arise in:
1. Logic synthesis
2. Data serialization
3. Instruction scheduling
4. Resolving symbol dependencies in linkers\
5. Determining the order of compilation tasks to perform in make files
6. Ordering of formula cell evaluation when recomputing formula values in spreadsheets

## Practice
1. Practice questions - [Leetcode - Topological Sort](https://leetcode.com/tag/topological-sort/)
2. Good questions - 

## References
1. [CP Algorithms - Topological sort](https://cp-algorithms.com/graph/topological-sort.html)
2. [GeeksForGeeks - Topological sort](https://www.geeksforgeeks.org/topological-sorting/)