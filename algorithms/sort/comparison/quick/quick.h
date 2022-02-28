#ifndef QUICK_H_INCLUDED
#define QUICK_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

int partition_rand(
        std::vector<int> &arr,
            int left, int right){

    int j=left+1;
    int pivot_pos = left+rand()%(right-left+1);
    int pivot_val = arr[pivot_pos];

    std::swap(arr[pivot_pos], arr[left]);
    for(int i=left+1; i<=right; i++){
        if(arr[i]<=pivot_val){
            std::swap(arr[j], arr[i]);
            j++;
        }
    }

    std::swap(arr[j-1], arr[left]);
    return j-1;
}

void quick_rand(
    std::vector<int> &arr,
        int left, int right){

    if(left<right){
        int pivot=partition_rand(arr, left, right);
        quick_rand(arr, left, pivot-1);
        quick_rand(arr, pivot+1, right);
    }

    return;
}

#endif // QUICK_H_INCLUDED