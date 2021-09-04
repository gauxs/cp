#ifndef COUNTING_SORT_H_INCLUDED
#define COUNTING_SORT_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

/*
    1 - Counting sort is a sorting technique based on keys between a specific range. It works by counting the
        number of objects having distinct key values (kind of hashing). Then doing some arithmetic to calculate
        the position of each object in the output sequence.
    2 - Can be used to sort a string since range is fixed i.e 26
    
    Reference: https://www.geeksforgeeks.org/counting-sort/
*/

/* 
    Time complexity: O(n+k) where, n is the number of elements in input array and k is the range of input. 
    Space complexity: O(n+k)
    Inplace sorting: No
    Stable sorting: Yes
*/
void counting_sort(std::vector<int> &input, int min_ele, int max_ele, std::vector<int> &output){
    // O(k)
    std::vector<int> count(max_ele-min_ele+1);
    int input_len = input.size();

    // O(n)
    for(int i=0; i<input_len; i++){
        count[input[i]-min_ele]++;
    }

    // O(k)
    for(int i=1; i<(max_ele-min_ele+1); i++){
        count[i] += count[i-1];
    }

    // its a stable algorithm since we are keeping
    // elements in the order they appeared in input
    // O(n)
    for(int i=0; i<input_len; i++){
        output[count[input[i]-min_ele]-1] = input[i];
        count[input[i]-min_ele]--;
    }

    return;
}

#endif // COUNTING_SORT_H_INCLUDED

// int main(){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     std::cout.tie(NULL);
    
//     std::vector<int> input{ 1, 4, 1, 2, 7, 5, 2};
//     std::vector<int> output(input.size());
//     counting_sort(input, 1, 7, output);

//     for(int i=0; i<output.size(); i++){
//         std::cout<<output[i]<<std::endl;
//     }

//     return 0;
// }