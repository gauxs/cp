#ifndef JUMP_H_INCLUDED
#define JUMP_H_INCLUDED

#include <vector>
#include <math.h>

/*
    Returns the index of the element if found, else -1
*/
int jump_search_iterative(
        std::vector<int> &input,
            int n, int ele){

    int m = sqrt(n);

    int search_index = 0;
    while(search_index<n && input[search_index]<ele)
        search_index += m;
    
    if(search_index>=n)
        return -1;
    
    int end = search_index;
    int start = search_index - m + 1;

    // when search_index is 0
    if(start<0)
        start=0;

    for(int i=start; i<=end; i++){
        if(input[i]==ele){
            return i;
        }
    }

    return -1;
}

#endif // JUMP_H_INCLUDED