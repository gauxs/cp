#ifndef QUICK_SELECT_H_INCLUDED
#define QUICK_SELECT_H_INCLUDED

#include <vector>
#include <iostream>
#include <bits/stdc++.h>

int partition(std::vector<int>& nums, int low, int high){
    int j = low + 1;
    int pivot_pos = low + rand() % (high - low + 1);
    int pivot_val = nums[pivot_pos];

    std::swap(nums[pivot_pos], nums[low]);
    for(int i=low+1; i<=high; i++){
        if(nums[i]<pivot_val){
            std::swap(nums[i], nums[j]);
            j++;
        }
    }

    std::swap(nums[low], nums[j-1]);
    return j-1;
}

int quick_select(std::vector<int>& nums, int n, int k, int low, int high){
    if(low<high){
        int p = partition(nums, low, high);

        // if() TODO
        quick_select(nums, n, k, low, p-1);
        quick_select(nums, n, k, p+1, high);
    }

    return INT_MAX;
}

#endif // QUICK_SELECT_H_INCLUDED
