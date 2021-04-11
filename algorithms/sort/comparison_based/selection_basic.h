#include <vector>
#include <iostream>
#include <bits/stdc++.h>

#include "utils/basic.h"

#ifndef SELECTION_BASIC_H_INCLUDED
#define SELECTION_BASIC_H_INCLUDED

/*
    Sorts an array by repeatedly finding the minimum element (considering ascending order)
    from unsorted part and putting it at the beginning.

    Time complexity:
    1.  Worst: O(n*n)
    2.  Average: O(n*n)
    3.  Best: O(n*n)

    Space complexity: O(1)

    Inplace sorting: yes
    Stable sorting: No, but can be made stable.

    Stable selection sort:
    Selection sort can be made Stable if instead of swapping, the minimum element is placed in 
    its position without swapping i.e. by placing the number in its position by pushing every 
    element one step forward.
    Example: 4A 5 3 2 4B 1
        First minimum element is 1, now instead
        of swapping. Insert 1 in its correct place 
        and pushing every element one step forward
        i.e forward pushing.

    Reference:  https://www.geeksforgeeks.org/selection-sort/ 
*/

void selection_basic_sort(std::vector<int> &arr, int n){
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

void selection_basic(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<int> input{5, 2, 4, 3, -2, -4, 1};
    selection_basic_sort(input, input.size());

    myutils::myprint::print(input, input.size());
}

#endif // SELECTION_BASIC_H_INCLUDED
