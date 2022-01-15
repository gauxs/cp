#ifndef KADANE_H_INCLUDED
#define KADANE_H_INCLUDED

#include <vector>
#include <bits/stdc++.h>

// Time complexity: O(N)
// Space complexity: O(1)
// Returns the maximum sum subarray's sum
int kadane(std::vector<int>& nums, int n){
    if(n==0)
        return 0;

    int curMaxSum=nums[0], maxSum = INT_MIN;
    for(int i=0; i<n; i++){
        curMaxSum = std::max(curMaxSum + nums[i], nums[i]);
        maxSum = std::max(maxSum, curMaxSum);
    }

    return maxSum;
}

#endif // KADANE_H_INCLUDED
