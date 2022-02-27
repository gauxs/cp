#ifndef DIFFERENCE_ARRAY_H_INCLUDED
#define DIFFERENCE_ARRAY_H_INCLUDED

#include <vector>
#include <iostream>

std::vector<int> initializeDiffArray(std::vector<int> &inp, int n){
    std::vector<int> diffArray(n+1);
    diffArray[0]=inp[0];
    diffArray[n]=0;
    for(int i=1; i<n; i++){
        diffArray[i]=inp[i]-inp[i-1];
    }
    return diffArray;
}

void update(std::vector<int> &diffArr, int l, int r, int x){
    diffArr[l]+=x;
    diffArr[r+1]-=x;
    return;
}

void updArr(std::vector<int> &arr, std::vector<int> &diffArr, int n){
    arr[0]=diffArr[0];
    for(int i=1; i<n; i++){
        arr[i]=diffArr[i]+arr[i-1];
    }
    return;
}

void printDiffArr(std::vector<int> &arr, std::vector<int> &diffArr, int n){
    std::cout<<diffArr[0]<<" ";

    for(int i=1; i<n; i++){
        std::cout<<diffArr[i]+arr[i-1]<<" ";
    }
    std::cout<<std::endl;
    return;
}

#endif // DIFFERENCE_ARRAY_H_INCLUDED
