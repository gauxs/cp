# Topological Sort

Topological sorting is an algorithm that finds a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge (u, v), vertex u comes before vertex v in the ordering. It's a fundamental algorithm for dependency resolution and scheduling problems.

## Algorithm Overview

### Purpose
- **Linear ordering**: Arrange vertices in a sequence respecting dependencies
- **Dependency resolution**: Ensure prerequisites come before dependents
- **Cycle detection**: Identify if the graph contains cycles (no valid ordering exists)
- **Scheduling**: Order tasks based on their dependencies

### Key Characteristics
- **Directed graphs only**: Works only on directed graphs
- **Acyclic requirement**: Graph must be a DAG (no cycles)
- **Non-unique solutions**: Multiple valid orderings may exist
- **Linear time complexity**: O(V + E) using DFS or BFS

## How It Works

### Core Concept
A topological order is a permutation of vertices where:
- For every directed edge (u, v), vertex u appears before vertex v
- All dependencies are satisfied in the ordering
- If cycles exist, no valid topological order exists

### Algorithm Approaches

#### DFS-based (Kahn's Algorithm)
1. **Initialize**: Calculate in-degree for each vertex
2. **Start**: Add all vertices with in-degree 0 to queue
3. **Process**: While queue is not empty:
   - Remove vertex from queue
   - Add to result
   - Decrease in-degree of all neighbors
   - Add neighbors with in-degree 0 to queue
4. **Check**: If result size ≠ V, cycle exists

#### BFS-based (DFS with Stack)
1. **DFS traversal**: Visit all vertices using DFS
2. **Stack**: Push vertices to stack after visiting all neighbors
3. **Result**: Pop from stack to get topological order
4. **Cycle detection**: Use colors (white/gray/black) to detect back edges

## Important Properties

### Uniqueness
- **Non-unique**: Multiple valid topological orders may exist
- **Example**: If vertices a, b, c have paths a→b and a→c but no path between b and c
- **Empty graph**: All permutations are valid topological orders

### Existence
- **May not exist**: If the graph contains cycles
- **Contradiction**: Cycle creates circular dependencies (a→b→c→a)
- **Detection**: Algorithm can identify when no valid ordering exists

### Common Problem Example
> There are n variables with unknown values. For some variables we know that one is less than the other. Check if constraints are contradictory, and if not, output variables in ascending order.

This is exactly the topological sorting problem where:
- Variables are vertices
- "Less than" relationships are directed edges
- Valid ordering represents a consistent assignment

## Algorithm Analysis

| Aspect | Complexity | Notes |
|--------|------------|-------|
| **Time Complexity** | O(V + E) | Each vertex and edge processed once |
| **Space Complexity** | O(V) | For in-degree array and queue/stack |
| **Cycle Detection** | O(V + E) | Built into the algorithm |

### Complexity Breakdown
- **In-degree calculation**: O(E) for all edges
- **Queue operations**: O(V) for all vertices
- **Edge processing**: O(E) for all edges
- **Total**: O(V + E) dominates

## When to Use Topological Sort

**Best for:**
- **Dependency resolution**: Task scheduling with prerequisites
- **Course scheduling**: Academic course prerequisites
- **Build systems**: Compilation order determination
- **Package management**: Software dependency resolution
- **Workflow management**: Process ordering with dependencies

**Not suitable for:**
- **Undirected graphs**: No inherent ordering in undirected graphs
- **Cyclic graphs**: Cycles prevent valid topological ordering
- **Unweighted problems**: Focuses on ordering, not optimization

## Applications

### Computer Science
1. **Logic synthesis**: Circuit design with component dependencies
2. **Data serialization**: Object serialization order
3. **Instruction scheduling**: CPU instruction ordering
4. **Symbol dependencies**: Linker dependency resolution
5. **Make files**: Compilation task ordering
6. **Spreadsheet formulas**: Cell evaluation order

### Real-world Examples
- **Course prerequisites**: Academic scheduling
- **Project management**: Task dependency ordering
- **Software installation**: Package dependency resolution
- **Workflow automation**: Process step ordering
- **Data pipeline**: ETL process ordering

## Implementation Considerations

### Data Structures
- **In-degree array**: Track incoming edges for each vertex
- **Queue/Stack**: For processing vertices
- **Adjacency list**: Graph representation
- **Result array**: Store topological order

### Edge Cases
- **Empty graph**: Any ordering is valid
- **Single vertex**: Trivial ordering
- **Disconnected components**: Each component can be ordered independently
- **Self-loops**: Create cycles, invalidate ordering

## References

1. [CP Algorithms - Topological Sort](https://cp-algorithms.com/graph/topological-sort.html) - Detailed algorithm explanation
2. [GeeksforGeeks - Topological Sort](https://www.geeksforgeeks.org/topological-sorting/) - Implementation guide
3. [Wikipedia - Topological Sorting](https://en.wikipedia.org/wiki/Topological_sorting) - Mathematical properties
4. [Khan Academy - Topological Sort](https://www.khanacademy.org/computing/computer-science/algorithms) - Educational content
