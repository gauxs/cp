#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

void max_heapify(std::vector<int> &arr, int n, int i){
    int left_child = (2*i)+1;
    int right_child = (2*i)+2;
    int largest = i;

    if(left_child<n && arr[left_child]>arr[i])
        largest=left_child;

    if(right_child<n && arr[right_child]>arr[largest])
        largest=right_child;

    if(largest!=i){
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
    return;
}

void min_heapify(std::vector<int> &arr, int n, int i){
    int left_child = (2*i)+1;
    int right_child = (2*i)+2;
    int smallest = i;

    if(left_child<n && arr[left_child]<arr[i])
        smallest=left_child;

    if(right_child<n && arr[right_child]<arr[smallest])
        smallest=right_child;

    if(smallest!=i){
        std::swap(arr[i], arr[smallest]);
        min_heapify(arr, n, smallest);
    }
    return;
}

void heap_sort(std::vector<int> &arr, int n){
    for(int i=n/2-1; i>=0; i--)
        max_heapify(arr, n, i);

    for(int i=n-1; i>=0; i--){
        std::swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
    
    return;
}

#endif // HEAP_H_INCLUDED