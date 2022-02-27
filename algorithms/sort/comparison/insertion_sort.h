#ifndef INSERTION_SORT_H_INCLUDED
#define INSERTION_SORT_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

/*
    The array is virtually split into a sorted and an unsorted part. Values from the unsorted part 
    are picked and placed at the correct position in the sorted part.

    NOTE:
    1.  Insertion sort is used when number of elements is small.
    2.  It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

    Binary insertion sort: Reduce comparison by performing binary search on the sorted part of the array.

    Reference:  https://www.geeksforgeeks.org/insertion-sort/
*/

/*
    Time complexity:
    1.  Worst: O(n*n) - sorted in reverse order
    2.  Average: O(n*n)
    3.  Best: O(n) - sorted in-order

    Space complexity: O(1)
    Inplace sorting: yes
    Stable sorting: yes
*/
void insertion_sort(std::vector<int> &arr){
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

#endif // INSERTION_SORT_H_INCLUDED

// int main(){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     std::cout.tie(NULL);

//     std::vector<int> input{5, 2, 4, 3, -2, -4, 1};
//     insertion_sort(input);

//     myutils::myprint::print(input, input.size());

//     return 0;
// }