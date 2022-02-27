#ifndef BUBBLE_SORT_H_INCLUDED
#define BUBBLE_SORT_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

/*
    NOTES:
    1.  One pass gives an impression of bringing the largest(smallest if sorting in decreasing order)
        element towards the end of the list(if we traverse from 0).
    2.  After first pass we know that last index element is at right place.
    3.  In computer graphics it is popular for its capability to detect a very small error
        (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n).   

    Reference:  https://www.geeksforgeeks.org/bubble-sort/
*/

/*
    Time complexity:
    1.  Worst: O(n*n)
    2.  Average: O(n*n)
    3.  Best: O(n) - when the input is sorted

    Space complexity: O(1)
    Inplace sorting: yes
    Stable sorting: yes 
*/
void bubble_sort(std::vector<int> &arr, int n){
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

#endif // BUBBLE_SORT_H_INCLUDED

// int main(){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     std::cout.tie(NULL);

//     std::vector<int> input{5, 2, 4, 3, -2, -4, 1};
//     bubble_sort(input, input.size());

//     myutils::myprint::print(input, input.size());
// }