#ifndef INSERTION_H_INCLUDED
#define INSERTION_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

void insertion_sort(
    std::vector<int> &arr,
        int n){

    int key=-1, j=-1;
    for(int i=0; i<n; i++){
        key=arr[i];
        j=i-1;
        // replace this with binary search for binary insertion sort
        while (j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;   
    }

    return;
}

#endif // INSERTION_H_INCLUDED