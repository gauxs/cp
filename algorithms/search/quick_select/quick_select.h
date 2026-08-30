#ifndef QUICK_SELECT_H_INCLUDED
#define QUICK_SELECT_H_INCLUDED

#include <bits/stdc++.h>

#include <iostream>
#include <vector>

int partition(std::vector<int>& nums, int low, int high) {
    int j = low + 1;
    int pivot_pos = low + rand() % (high - low + 1);
    int pivot_val = nums[pivot_pos];

    std::swap(nums[pivot_pos], nums[low]);
    for (int i = low + 1; i <= high; i++) {
        if (nums[i] < pivot_val) {
            std::swap(nums[i], nums[j]);
            j++;
        }
    }

    std::swap(nums[low], nums[j - 1]);
    return j - 1;
}

int quick_select(std::vector<int>& nums, int k, int low, int high) {
    if (k > 0 && k <= high - low + 1) {
        int p = partition(nums, low, high);

        if ((p - low + 1) == (k))
            return nums[p];

        if ((p - low + 1) > k)
            return quick_select(nums, k, low, p - 1);

        return quick_select(nums, k - (p - low + 1), p + 1, high);
    }

    return -1;
}

#endif  // QUICK_SELECT_H_INCLUDED
