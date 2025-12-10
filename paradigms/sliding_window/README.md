# Sliding Window

The sliding window technique is a method for efficiently solving problems involving contiguous subarrays or substrings. It maintains a "window" of elements and slides it across the array/string, typically using two pointers (left and right) to represent the window boundaries.

## Algorithm Overview

The sliding window technique works by:
1. **Expanding the window**: Move the right pointer to include new elements
2. **Updating state**: Track relevant information about elements in the current window (frequencies, sums, etc.)
3. **Shrinking the window**: Move the left pointer when the window violates the problem's constraints
4. **Recording results**: Update the answer when the window satisfies the condition

## Basic Template

Basic template to solve sliding window problems (below example is based on [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)):

```
class Solution {
public:
    // the condition to be satified by the window
    bool isOperationWithinLimit(vector<int>& freq, int k) {
        int maxFreq = 0;
        int totalFreq = 0;
        for (int i = 0; i < 26; i++) {
            maxFreq = max(maxFreq, freq[i]);
            totalFreq += freq[i];
        }

        return (totalFreq - maxFreq) <= k;
    }

    int characterReplacement(string s, int k) {
        // storage for all the occurrence in the current window
        vector<int> charFreq(26, 0);

        // left and right index representing the window
        int left = 0, right = 0, maxSubStrLen = 0;

        // start by increasing the window length by moving the right counter
        for (; right < s.length(); right++) {

            // the elements seen by right index will update the storage
            // according to the question
            charFreq[s[right] - 'A']++;

            // check if the current window represented by left/right index
            // satisfies the condition of the question, till this condition
            // is not satisfied keep moving the left index and decrease the
            // window size
            while (left <= right && !isOperationWithinLimit(freq, k)) {
                charFreq[s[left] - 'A']--;
                left++;
            }

            // at this point the window satisfies the condition
            // record the length of the window
            maxSubStrLen = max(maxSubStrLen, right - left + 1);
        }

        return maxSubStrLen;
    }
};
```

## Key Components

1. **Window State Storage**: Track relevant information about elements in the current window (e.g., character frequencies, running sum)
2. **Left and Right Pointers**: Represent the window boundaries
3. **Condition Function**: Determines if the current window satisfies the problem's constraints
4. **Expansion Logic**: Move right pointer to include new elements
5. **Shrinking Logic**: Move left pointer when window violates constraints

## When to Use Sliding Window

- Problems involving **contiguous subarrays/substrings**
- Need to find **longest/shortest** subarray satisfying a condition
- Need to count subarrays with certain properties
- Window size can be **fixed** or **variable**
- Condition has **monotonicity** (if window [i, j] is valid, then [i, j+1] might be valid)

## Practice Problems

For detailed practice problems organized by difficulty level, see:
- [Beginner Level](practice/1. beginner.md) - Basic sliding window problems
- [Intermediate Level](practice/2. intermediate.md) - Advanced sliding window applications
- [Advanced Level](practice/3. advanced.md) - Complex sliding window variations
- [Patterns & Techniques](practice/0. patterns.md) - Common sliding window patterns and problem-solving strategies

### Quick Reference
- **Warmup Problems**: [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/), [Number of Substrings Containing All Three Characters](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)
- **Quality Problems**: [Shortest Subarray with Sum at Least K](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/), [Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)
- **All Problems**: [LeetCode - Sliding Window Tag](https://leetcode.com/tag/sliding-window/)
- **Problem which seems like a sliding window but isn't**: [Contiguous Array](https://leetcode.com/problems/contiguous-array/) (uses prefix sum + hash map instead)

## References

1. [Sliding Window algorithm template to solve all the Leetcode substring search problem](https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem.) by [@chaoyanghe](https://leetcode.com/chaoyanghe/)
2. [Sliding window for beginners template](https://leetcode.com/discuss/general-discussion/657507/sliding-window-for-beginners-problems-template-sample-solutions/) by [@wh0ami](https://leetcode.com/wh0ami/)
