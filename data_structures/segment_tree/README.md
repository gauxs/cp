# Segment Tree
A Segment Tree is a data structure that allows answering range queries over an array effectively, while still being flexible enough to allow modifying the array. One important property of Segment Trees is that they require only a linear amount of memory. The standard Segment Tree requires 4*N vertices for working on an array of size N.

### Range updates
Segment Tree allows applying modification queries to an entire segment of contiguous elements, and perform the query in the same time O(log(N_S)). There is a method where we don't have to change all N_C (number of values to change) values, but only O(log(N_S)) many i.e. height of the segment tree.

For any queries (a modification or reading query) during the descent along the tree we should always push information from the current vertex into both of its children. We can understand this in such a way, that when we descent the tree we apply delayed modifications, but exactly as much as necessary (so not to degrade the complexity of O(log(N_S)).

### Data structure Analysis
```
    N -     size of input
    N_S -   size of segment tree

    N_S = (2*(2^(log(N)))-1)

    Time complexity:
        1. construct_tree:          O(N_S)
        2. get:                     O(log(N_S))
        3. single_update_input:     O(log(N_S))
        4. range_update_input:      O(log(N_S))

    Space complexity:
        1. Height of segment tree:  O(log(N_S))
        2. Space of segment tree:   O(N_S)
```

Why is the complexity of this algorithm logN? To show this complexity we look at each level of the tree. It turns out, that for each level we only visit not more than four vertices. And since the height of the tree is , we receive the desired running time. We can show that this proposition (at most four vertices each level) is true by induction.

>At the first level, we only visit one vertex, the root vertex, so here we visit less than four vertices. Now let's look at an arbitrary level. By induction hypothesis, we visit at most four vertices. If we only visit at most two vertices, the next level has at most four vertices. That trivial, because each vertex can only cause at most two recursive calls. So let's assume that we visit three or four vertices in the current level. From those vertices, we will analyze the vertices in the middle more carefully. Since the sum query asks for the sum of a continuous subarray, we know that segments corresponding to the visited vertices in the middle will be completely covered by the segment of the sum query. Therefore these vertices will not make any recursive calls. So only the most left, and the most right vertex will have the potential to make recursive calls. And those will only create at most four recursive calls, so also the next level will satisfy the assertion. We can say that one branch approaches the left boundary of the query, and the second branch approaches the right one.

## Practice
1. Practice questions - [Leetcode - Segment Tree](https://leetcode.com/tag/segment-tree/)
2. Good questions - 

## References
1. [CP Algorithms - Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)
2. [Leetcode - Segment tree with lazy propogation](https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/)