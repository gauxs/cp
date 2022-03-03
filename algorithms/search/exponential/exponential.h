#ifndef EXPONENTIAL_H_INCLUDED
#define EXPONENTIAL_H_INCLUDED

#include <vector>
#include <algorithms/search/binary/binary.h>

/*
    Returns the index of the element if found, else -1
*/
int exponential(
        std::vector<int> &input,
            int n, int ele){

    if(input[0]==ele)
        return 0;

    int itr=1;
    while(itr<n && input[itr]<ele)
        itr *= 2;

    if(itr<n)
        return binary_iterative(input, itr/2, itr, ele);

    return -1;
}

#endif // EXPONENTIAL_H_INCLUDED