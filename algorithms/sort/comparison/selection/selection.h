#ifndef SELECTION_H_INCLUDED
#define SELECTION_H_INCLUDED

#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include "utils/basic.h"

void selection_sort(
        std::vector<int> &arr,
            int n){
                
    for(int i=0; i<n; i++){
        int min_index=-1;
        int min_v=INT_MAX;
        for(int j=i; j<n; j++){
            if(arr[j]<min_v){
                min_v=arr[j];
                min_index=j;
            }
        }

        // replace swap with shifting to make this stable sort
        std::swap(arr[i], arr[min_index]);
    }
    return;
}

#endif // SELECTION_H_INCLUDED