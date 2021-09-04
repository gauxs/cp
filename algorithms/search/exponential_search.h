#ifndef EXPONENTIAL_SEARCH_BASIC_H_INCLUDED
#define EXPONENTIAL_SEARCH_BASIC_H_INCLUDED

#include <vector>
#include <algorithms/search/binary_search.h>

/*
    1 - Exponential Binary Search is particularly useful for unbounded searches, where size of array is infinite.
    2 - It works better than Binary Search for bounded arrays, and also when the element to be searched is closer to the first element.
    
    Reference: https://www.geeksforgeeks.org/exponential-search/
*/

// Time complexity: Big-O(log(N))
// Space complexity: No extra space
// Returns the index of the element if found, else -1
int exponential_search(std::vector<int> &input, int ele){
    int n = input.size();

    if(input[0]==ele){
        return 0;
    }

    int itr=1;
    while(itr<n && input[itr]<ele){
        itr *= 2;
    }

    if(itr<n){
        return binary_search_iterative(input, itr/2, itr, ele);
    }

    return -1;
}

#endif // EXPONENTIAL_SEARCH_BASIC_H_INCLUDED

// int main(){
//     std::vector<int> input{1, 4, 6, 19, 21, 34, 57, 64, 111, 145};
//     std::cout<<exponential_search(input, 21)<<std::endl;
// 
//     return 0;
// }