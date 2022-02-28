#ifndef SHELL_H_INCLUDED
#define SHELL_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

void shell_sort(
    std::vector<int> &input,
        int n){

    // gap goes from [n/2, 1]
    for(int gap=n/2; gap>0; gap/=2){
        for(int i=gap; i<n; i++){
            int j;
            int temp = input[i];
            // j>=gap because we are checking input[j-gap]
            for(j=i; j>=gap && input[j-gap]>temp; j-=gap){
                input[j] = input[j-gap];
            }
            input[j] = temp;
        }
    }
    
    return;
}

#endif // SHELL_H_INCLUDED