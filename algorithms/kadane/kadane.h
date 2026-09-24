#ifndef KADANE_H_INCLUDED
#define KADANE_H_INCLUDED

#include <algorithm>
#include <stdexcept>
#include <vector>

// Returns the maximum sum of a non-empty contiguous subarray.
// Time: O(N), auxiliary space: O(1).
inline long long kadane(const std::vector<int>& nums) {
    if (nums.empty()) {
        throw std::invalid_argument("kadane requires a non-empty array");
    }

    long long ending_here = nums.front();
    long long best = ending_here;

    for (std::size_t i = 1; i < nums.size(); ++i) {
        ending_here = std::max<long long>(nums[i], ending_here + nums[i]);
        best = std::max(best, ending_here);
    }

    return best;
}

#endif  // KADANE_H_INCLUDED
