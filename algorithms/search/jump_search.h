#ifndef JUMP_SEARCH_BASIC_H_INCLUDED
#define JUMP_SEARCH_BASIC_H_INCLUDED

#pragma GCC optimize("Ofast")
#include <vector>
#include <math.h>

/*
    1 - Works on sorted data.
    2 - Jumps by a fixed length(M) until we find an element > search element.
    3 - Then we perform linear search in that range.
    4 - Worst case we will do N/M jumps and when last checked value is > search element, then we perform linear search
        of (M-1) comparisons.
    5 - Total number of comparisons = ((N/M) + (M-1)), this is minimized when M = sqrt(N)
    6 - Time complexity is between Binary Search and Linear Search.
    7 - Binary Search is better than Jump Search, but Jump search has an advantage that we traverse back only once 
        (Binary Search may require up to O(Log n) jumps, consider a situation where the element to be searched is the
        smallest element or smaller than the smallest). So in a system where binary search is costly, we use Jump Search.
    
    Reference: https://www.geeksforgeeks.org/jump-search/
*/

// Time complexity: Big-O(sqrt(N))
// Space complexity: No extra space
// Returns the index of the element if found, else -1
int jump_search_iterative(std::vector<int> &input, int ele){
    int n = input.size();
    int m = sqrt(n);

    int search_index = 0;
    while(search_index<n && input[search_index]<ele){
        search_index += m;
    }
    
    if(search_index>=n){
        return -1;
    }
    
    int end = search_index;
    int start = search_index - m + 1;

    // when search_index is 0
    if(start<0){
        start=0;
    }

    for(int i=start; i<=end; i++){
        if(input[i]==ele){
            return i;
        }
    }

    return -1;
}

#endif // JUMP_SEARCH_BASIC_H_INCLUDED

// int main(){
//     std::vector<int> input{1, 4, 6, 19, 21, 34, 57, 64, 111, 145};
//     std::cout<<jump_search_iterative(input, 155)<<std::endl;
// 
//     return 0;
// }