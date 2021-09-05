#ifndef SELECTION_SORT_H_INCLUDED
#define SELECTION_SORT_H_INCLUDED

#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include "utils/basic.h"

/*
    Sorts an array by repeatedly finding the minimum element (considering ascending order)
    from unsorted part and putting it at the beginning.

    NOTE:
    1 - The good thing about selection sort is it never makes more than O(n) swaps and can
        be useful when memory write is a costly operation. 

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

/*
    Time complexity:
    1.  Worst: O(n*n)
    2.  Average: O(n*n)
    3.  Best: O(n*n)

    Space complexity: O(1)
    Inplace sorting: yes
    Stable sorting: No, but can be made stable.
*/
void selection_sort(std::vector<int> &arr, int n){
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

#endif // SELECTION_SORT_H_INCLUDED

// int main(){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     std::cout.tie(NULL);

//     std::vector<int> input{5, 2, 4, 3, -2, -4, 1};
//     selection_sort(input, input.size());

//     myutils::myprint::print(input, input.size());

//     return 0;
// }