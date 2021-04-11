#include <vector>
#include <iostream>

#include "utils/basic.h"

#ifndef HEAP_BASIC_H_INCLUDED
#define HEAP_BASIC_H_INCLUDED

/*
    Heap sort is a comparison based sorting technique based on Binary Heap data structure. It is similar to
    selection sort where we first find the minimum element and place the minimum element at the beginning.

    Pusedo-code:
    1.  Build a max heap from the input data. 
    2.  At this point, the largest item is stored at the root of the heap. Replace it with the last item of
        the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree. 
    3.  Repeat step 2 while size of heap is greater than 1.

    Time complexity:     
    1.  Worst: O(n * log(n))
    2.  Average: O(n * log(n))
    3.  Best: O(n * log(n))

    Space complexity: O(1)

    Inplace sorting: Yes
    Stable sorting: Typically No, but can be made stable(Reference: https://www.geeksforgeeks.org/stability-in-sorting-algorithms/) 
        
    Reference: https://www.geeksforgeeks.org/heap-sort/
*/

void max_heapify(std::vector<int> &arr, int n, int i){
    int left_child=2*i+1;
    int right_child=2*i+2;
    int largest=i;

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
    int left_child=2*i+1;
    int right_child=2*i+2;
    int smallest=i;

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

void heap_basic_sort(std::vector<int> &arr, int n){
    for(int i=n/2-1; i>=0; i--){
        max_heapify(arr, n, i);
    }

    for(int i=n-1; i>=0; i--){
        std::swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
    
    return;
}


void heap_basic(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<int> input{5, 2, 4, 3, -2, -4, 1};
    heap_basic_sort(input, input.size()-1);

    myutils::myprint::print(input, input.size());
}

#endif // HEAP_BASIC_H_INCLUDED
