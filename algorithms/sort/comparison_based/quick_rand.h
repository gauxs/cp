#include <vector>
#include <iostream>

#include "utils/basic.h"

#ifndef QUICK_RAND_H_INCLUDED
#define QUICK_RAND_H_INCLUDED

/*
    Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and
    partitions the given array around the picked pivot. There are many different versions of quickSort
    that pick pivot in different ways. 
    1.  Always pick first element as pivot.
    2.  Always pick last element as pivot.
    3.  Pick a random element as pivot.
    4.  Pick median as pivot.
    The key process in quickSort is partition(). Target of partitions is, given an array and an element x
    of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x)
    before x, and put all greater elements (greater than x) after x. All this should be done in linear time. 

    Time complexity:    T(n) = T(k) + T(n-k-1) + θ(n)
    The first two terms are for two recursive calls, the last term is for the partition process. k is the number of
    elements which are smaller than pivot. The time taken by QuickSort depends upon the input array and partition 
    strategy. Following are three cases:   

    1.  Worst: T(n) = T(0) + T(n-1) + θ(n)  ->  θ(n * n)
    2.  Average: T(n) = To do average case analysis, we need to consider all possible permutation of array and calculate
        time taken by every permutation which doesn’t look easy. We can get an idea of average case by considering the
        case when partition puts O(n/9) elements in one set and O(9n/10) elements in other set.
        T(n/9) + T(9n/10) + θ(n)    ->  O(n * log(n))
    3.  Best: T(n) = 2T(n/2) + θ(n) ->  θ(n * log(n))

    Space complexity: O(n)

    Inplace sorting: Yes, it uses extra space only for storing recursive function calls but not for manipulating the input. 
    Stable sorting: No, however any sorting algorithm can be made stable by considering indexes as comparison parameter. 

    Notes:
    1.  Quick Sort is preferred over MergeSort for sorting Arrays.
    2.  MergeSort is preferred over QuickSort for Linked Lists.
    3.  QuickSort can be optimised so that it takes O(Log n) extra space(recursion i.e.stack frames) in worst case 
        scenario. https://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/
        
    Reference: https://www.geeksforgeeks.org/quick-sort/
*/

int rand_partition(std::vector<int> &arr, int left, int right){
    int pivot_pos=left+rand()%(right-left+1);
    int pivot=arr[pivot_pos];
    std::swap(arr[pivot_pos], arr[left]);
    int j=left+1;
    for(int i=left+1; i<=right; i++){
        if(arr[i]<=pivot){
            std::swap(arr[j], arr[i]);
            j++;
        }
    }

    std::swap(arr[j-1], arr[left]);
    return j-1;
}

void quick_rand_sort(std::vector<int> &arr, int left, int right){
    if(left<right){
        int pivot=rand_partition(arr, left, right);
        quick_rand_sort(arr, left, pivot-1);
        quick_rand_sort(arr, pivot+1, right);
    }

    return;
}

void quick_rand(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<int> input{5, 2, 4, 3, -2, -4, 1};
    quick_rand_sort(input, 0, input.size()-1);

    myutils::myprint::print(input, input.size());
}

#endif // QUICK_RAND_H_INCLUDED
