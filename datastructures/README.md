# Trie
Trie is an efficient information reTrieval data structure. Using Trie, search complexities can be brought to optimal limit (key length). 

If we store keys in binary search tree, a well balanced BST will need time proportional to M * log N, where M is maximum string length and N is number of keys in tree. Using Trie, we can search the key in O(M) time. However the penalty is on Trie storage requirements.

## Algorithm Analysis
The maximum number of children of a node is equal to the size of the alphabet.
```
L is the average length of key(s)
K is the number of unique symbols i.e. alphabets, digits, etc

Time Complexity:   
    1. Search:  O(L)
    2. Insert:  O(L)
    3. Delete:  O(L)

Space Complexity:   O(K^L)
```

## Advantages
- With Trie, we can insert and find strings in O(L) time where L represent the length of a single word. This is obviously faster than BST. This is also faster than Hashing because of the ways it is implemented. We do not need to compute any hash function. No collision handling is required (like we do in open addressing and separate chaining)
- Another advantage of Trie is, we can easily print all words in alphabetical order which is not easily possible with hashing.
- We can efficiently do prefix search (or auto-complete) with Trie.

## Disadvantages
- The main disadvantage of tries is that they need a lot of memory for storing the strings. For each node we have too many node pointers(equal to number of characters of the alphabet)

## Alternatives
- If space is a concern, then Ternary Search Tree can be preferred for dictionary implementations.
- In Ternary Search Tree, the time complexity of search operation is O(h) where h is the height of the tree.
- Ternary Search Trees also supports other operations supported by Trie like prefix search, alphabetical order printing, and nearest neighbor search.

## References
- https://www.geeksforgeeks.org/trie-insert-and-search/
- https://www.geeksforgeeks.org/trie-delete/
- https://www.geeksforgeeks.org/advantages-trie-data-structure/

## Warmup Problems
1. https://leetcode.com/problems/word-break/

## Quality Problems
1. 


# Heap(Priority Queue)

## Warmup Problems
1. https://leetcode.com/problems/kth-largest-element-in-an-array/

## Quality Problems
1. 