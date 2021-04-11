#include <vector>
#include <iostream>

#include "utils/basic.h"

#ifndef BUBBLE_BASIC_H_INCLUDED
#define BUBBLE_BASIC_H_INCLUDED

/*
    Psuedo-code:
    1.  swap adjacent elements if they apear in wrong order
    2.  repeat
    3.  stop if a pass goes without any swap

    Time complexity:
    1.  Worst: O(n*n)
    2.  Average: O(n*n)
    3.  Best: O(n)   - when the input is sorted

    Space complexity: O(1)

    Inplace sorting: yes
    Stable sorting: yes 

    NOTES:
    1.  one pass gives an impression of bringing the largest(smallest if sorting in decreasing order)
        element towards the end of the list(if we traverse from 0).
    2.  after first pass we know that last index element is at right place.  

    Reference:  https://www.geeksforgeeks.org/bubble-sort/
*/

void bubble_sort_basic(std::vector<int> &arr, int n){
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

void bubble_basic(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<int> input{5, 2, 4, 3, -2, -4, 1};
    bubble_sort_basic(input, input.size());

    myutils::myprint::print(input, input.size());
}

#endif // BUBBLE_BASIC_H_INCLUDED
