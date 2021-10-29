#ifndef MERGE_SORT_H_INCLUDED
#define MERGE_SORT_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

void merge_array(std::vector<int> &arr, int left, int mid, int right){
    int n = right-left+1;
    int left_pos=left, right_pos=mid+1;
    std::vector<int> temp_arr(right-left+1);

    for(int i=0; i<n; i++){
        if(left_pos>mid){                           // left array is exhausted, blindly copy right array 
            temp_arr[i]=arr[right_pos];
            right_pos++;
        }else if(right_pos>right){                  // right array is exhausted, blindly copy left array 
            temp_arr[i]=arr[left_pos];
            left_pos++;
        }else if(arr[left_pos]<=arr[right_pos]){
            temp_arr[i]=arr[left_pos];
            left_pos++;
        }else{
            temp_arr[i]=arr[right_pos];
            right_pos++;
        }
    }

    for(int i=0; i<n; i++)
        arr[left++]=temp_arr[i];

    return;
}

void merge_sort(std::vector<int> &arr, int left, int right){
    if(left<right){
        int mid = left+(right-left)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge_array(arr, left, mid, right);
    }

    return;
}

#endif // MERGE_SORT_H_INCLUDED