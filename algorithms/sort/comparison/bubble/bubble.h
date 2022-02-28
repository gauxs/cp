#ifndef BUBBLE_H_INCLUDED
#define BUBBLE_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

void bubble_sort(
    std::vector<int> &arr,
        int n){
            
    bool swapped = false;
    for(int i=n-1; i>0; i--){
        swapped = false;
        for(int j=0; j<i; j++){
            if(arr[j+1]<arr[j]){
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }

    return;
}

#endif // BUBBLE_H_INCLUDED