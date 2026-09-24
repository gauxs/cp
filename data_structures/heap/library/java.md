---
kind: library
lang: java
title: Heap - PriorityQueue
topic_id: data_structures/heap
---

# Heap - `PriorityQueue`

- Does not permit `null`.
- Head is the least element (min-heap by default).
- `add` / `poll` are $O(\log N)$.

```java
PriorityQueue<Integer> pq = new PriorityQueue<>();
pq.add(1);
pq.add(2);
pq.add(3);

System.out.println(pq.poll()); // 1
System.out.println(pq.peek()); // 2

PriorityQueue<Integer> maxPQ = new PriorityQueue<>(Collections.reverseOrder());
maxPQ.add(1);
maxPQ.add(2);
maxPQ.add(3);

System.out.println(maxPQ.poll()); // 3
```

## References

1. [GeeksforGeeks - PriorityQueue](https://www.geeksforgeeks.org/priority-queue-class-in-java/)
