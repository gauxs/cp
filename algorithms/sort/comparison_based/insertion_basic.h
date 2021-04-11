#include <vector>
#include <iostream>

#include "utils/basic.h"

#ifndef INSERTION_BASIC_H_INCLUDED
#define INSERTION_BASIC_H_INCLUDED

/*
    The array is virtually split into a sorted and an unsorted part. Values from the unsorted part 
    are picked and placed at the correct position in the sorted part.

    Pseudo-code:
    1:  Iterate from left to right over the array. 
    2:  Compare the current element (key) to its predecessor. 
    3:  If the key element is smaller than its predecessor, compare it to the elements before.
        Move the greater elements one position up to make space for the swapped element.

    Time complexity:
    1.  Worst: O(n*n) - sorted in reverse order
    2.  Average: O(n*n)
    3.  Best: O(n) - sorted in-order

    Space complexity: O(1)

    Inplace sorting: yes
    Stable sorting: yes

    NOTE:
    1.  Insertion sort is used when number of elements is small.
    2.  It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

    Binary insertion sort:
    Reduce comparison by performing binary search on the sorted part of the array.

    Reference:  https://www.geeksforgeeks.org/insertion-sort/
*/

void insertion_basic_sort(std::vector<int> &arr){
    int len = arr.size(), key=-1, j=-1;
    for(int i=0; i<len; i++){
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

void insertion_basic(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<int> input{5, 2, 4, 3, -2, -4, 1};
    insertion_basic_sort(input);

    myutils::myprint::print(input, input.size());
}

#endif // INSERTION_BASIC_H_INCLUDED
