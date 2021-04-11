#include <vector>
#include <iostream>

#include "utils/basic.h"

#ifndef BUCKET_BASIC_H_INCLUDED
#define BUCKET_BASIC_H_INCLUDED

/*
    Bucket sort is mainly useful when input is uniformly distributed over a range.

    Pusedo-code:
    1.  Create n empty buckets (Or lists).
    2.  Do following for every array element arr[i].
        2.1.    Insert arr[i] into bucket[n*array[i]]
    3.  Sort individual buckets using insertion sort.
    4.  Concatenate all sorted buckets.

    Time complexity:     
    1.  Worst: O(n)
    2.  Average: O(n)
    3.  Best: O(n)

    Space complexity: O(n)

    Inplace sorting: No
    Stable sorting: 
        
    Reference: https://www.geeksforgeeks.org/bucket-sort-2/
*/

void bucket_basic(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<int> input{5, 2, 4, 3, -2, -4, 1};
    // bucket_basic_sort(input, input.size()-1);

    myutils::myprint::print(input, input.size());
}

#endif // BUCKET_BASIC_H_INCLUDED