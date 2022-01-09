# Monotonic Queue/Stack
Monotonic Queue is a data structure that keeps it’s elements either entirely in non-increasing, or entirely in non-decreasing order. For some problems just a stack can be of use, although for a more standardized approach we can apply queue (or deque).

## Learnings
1. A monotonic decreasing stack is a stack that will produce, when popping its elements a sequence that:
    - is monotonically decreasing
    - respects the FIFO ordering of the input
    - includes the last item stacked (i.e. it can purge items greater than it).
2. A monotonic queue, also known as a double-ended queue, refers to a data structure in which each element monotonically increases or decreases with its subscript. The elements can be deleted at both the beginning and end of the queue, but they can only be inserted at the end. Since the elements are monotonic, the head element is either the maximum or minimum value depending on which monotonic queue you are constructing (decreasing or increasing order, *see elements from front to end of the queue*). Due to the nature of the double-ended queue, each element is enqueued once and dequeued at most once. Thus, the computational complexity of maintaining a monotonic queue is O(n).

## Practice Problems
1. Warmup problems
    - https://leetcode.com/problems/daily-temperatures/
2. Quality problems
    - https://leetcode.com/problems/sliding-window-maximum/
    - https://leetcode.com/problems/largest-rectangle-in-histogram/
3. [My monotonic queue questions list](https://leetcode.com/list/9i2dcaum)

## References
- [Monotonic Queues and Monotonic Optimization in Dynamic Programming](https://activities.tjhsst.edu/sct/lectures/1920/2020_2_21_Monotonic_Queues.pdf)
- [Medium article on monotonic queue](https://1e9.medium.com/monotonic-queue-notes-980a019d5793)
- [Applications of Monotonous Increasing stack](https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step) by [@wxd_sjtu](https://leetcode.com/wxd_sjtu/)
- [Monotonic Queue Summary](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/204290/Monotonic-Queue-Summary) by [@luxy622](https://leetcode.com/luxy622/)