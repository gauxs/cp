# Disjoint Set Union
Often it is also called **Union Find** because of its two main operations. This data structure provides the following capabilities. We are given several elements, each of which is a separate set. A DSU will have an operation to combine any two sets, and it will be able to tell in which set a specific element is. The classical version also introduces a third operation, it can create a set from a new element.

Thus the basic interface of this data structure consists of only three operations:
1. make_set
2. union_sets
3. find_set

**Applications** of this data structure are mentioned in one of the refrences.

## Algorithm Analysis
```
    N - number of elements

    Time complexity:
        1. make_set:                                    O(1)
        2. find_set(without path compression):          O(logN)
        3. find_set(with path compression):             O(1)

    Space complexity:   O(N)
```

## Practice
1. Practice questions - [Number of provinces](https://leetcode.com/problems/number-of-provinces/) | [Redundant connection](https://leetcode.com/problems/redundant-connection/)
2. Good questions - [Most stones removed with same row or column](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/) | [Satisfiability of equality equations](https://leetcode.com/problems/satisfiability-of-equality-equations/) | [Redundant connection-II](https://leetcode.com/problems/redundant-connection-ii/)

## References
1. [CP Algorithms - Disjoint set union](https://cp-algorithms.com/data_structures/disjoint_set_union.html)
