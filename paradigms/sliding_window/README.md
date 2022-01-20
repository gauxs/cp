# Sliding Window
Basic template to solve sliding window problems:
1. Keep a left and right pointer, the elements inside left and right pointer will represent a window. We need to slide this window
2. Have a counter or hash-map to count specific array input and keep on increasing the window toward right using outer loop
2. Have a while loop inside to reduce the window side by sliding toward right. Movement will be based on constraints of problem
3. Store the current maximum window size or minimum window size or number of windows based on problem requirement

Problem which ***seems*** like a sliding window but ***isn't***: [Contiguous Array](https://leetcode.com/problems/contiguous-array/)

## Practice Problems
1. Warmup problems
    - https://leetcode.com/problems/max-consecutive-ones-iii/
    - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
2. Quality problems
    - https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
    - https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
3. Complete List: https://leetcode.com/tag/sliding-window/

## References
1. [Sliding window for beginners template](https://leetcode.com/discuss/general-discussion/657507/sliding-window-for-beginners-problems-template-sample-solutions/) by [@wh0ami](https://leetcode.com/wh0ami/)
2. [Sliding Window algorithm template to solve all the Leetcode substring search problem](https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem.) by [@chaoyanghe](https://leetcode.com/chaoyanghe/)