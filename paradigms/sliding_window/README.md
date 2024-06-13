# Sliding Window

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

## Practice Problems

1. Warmup
   - https://leetcode.com/problems/max-consecutive-ones-iii/
   - https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
2. Quality
   - https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
   - https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
3. All Problems: https://leetcode.com/tag/sliding-window/
4. Problem which **_seems_** like a sliding window but **_isn't_**
   - [Contiguous Array](https://leetcode.com/problems/contiguous-array/)

## References

1. [Sliding Window algorithm template to solve all the Leetcode substring search problem](https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92007/Sliding-Window-algorithm-template-to-solve-all-the-Leetcode-substring-search-problem.) by [@chaoyanghe](https://leetcode.com/chaoyanghe/)
2. ~~[Sliding window for beginners template](https://leetcode.com/discuss/general-discussion/657507/sliding-window-for-beginners-problems-template-sample-solutions/) by [@wh0ami](https://leetcode.com/wh0ami/)~~
