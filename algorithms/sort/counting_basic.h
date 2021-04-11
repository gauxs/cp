#include <vector>
#include <iostream>

#include "utils/basic.h"

#ifndef COUNTING_BASIC_H_INCLUDED
#define COUNTING_BASIC_H_INCLUDED

/*
    Counting sort is a sorting technique based on keys between a specific range. It works by counting the
    number of objects having distinct key values (kind of hashing). Then doing some arithmetic to calculate
    the position of each object in the output sequence.

    For simplicity, consider the data in the range 0 to 9. 
    Input data: 1, 4, 1, 2, 7, 5, 2
    1) Take a count array to store the count of each unique object.
    Index:     0  1  2  3  4  5  6  7  8  9
    Count:     0  2  2  0   1  1  0  1  0  0

    2) Modify the count array such that each element at each index 
    stores the sum of previous counts. 
    Index:     0  1  2  3  4  5  6  7  8  9
    Count:     0  2  4  4  5  6  6  7  7  7

    The modified count array indicates the position of each object in 
    the output sequence.
    
    3) Output each object from the input sequence followed by 
    decreasing its count by 1.
    Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
    Put data 1 at index 2 in output. Decrease count by 1 to place 
    next data 1 at an index 1 smaller than this index.

    Time complexity: O(n+k) where n is the number of elements in input array and k is the range of input. 

    Space complexity: O(n+k)

    Inplace sorting: No
    Stable sorting: 
        
    Reference: https://www.geeksforgeeks.org/counting-sort/
*/

void counting_basic(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<int> input{5, 2, 4, 3, -2, -4, 1};
    // counting_basic_sort(input, input.size()-1);

    myutils::myprint::print(input, input.size());
}

#endif // COUNTING_BASIC_H_INCLUDED