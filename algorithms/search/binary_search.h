#ifndef BINARY_SEARCH_BASIC_H_INCLUDED
#define BINARY_SEARCH_BASIC_H_INCLUDED

#include <vector>

/*
    1 - Why are we using mid=low+(high-low)/2? 
        Because if we use mid=(low+high)/2 it fails if the sum of low and high is greater than the maximum positive int value(2^31 – 1 )
*/

// Time complexity: Big-O(log(N))
// Space complexity: No extra space
// Returns the index of the element if found, else -1
int binary_search_iterative(std::vector<int> &input, int low, int high, int ele){
    while(low<=high){
        int mid=low+(high-low)/2;;
        if(input[mid]==ele){
            return mid;
        }else if(input[mid]<ele){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }

    return -1;
}

// Time complexity: Big-O(log(N))
// Space complexity: Stack space of Big-O(log(N))
// Returns the index of the element if found, else -1
int binary_search_recursive(std::vector<int> &input, int left, int right, int ele){
    if(left<=right){
        int mid = left + (right - left)/2;
        if(input[mid] == ele){
            return mid;
        }else if(input[mid] > ele){
            return binary_search_recursive(input, left, mid-1, ele);
        }else{
            return binary_search_recursive(input, mid+1, right, ele);
        }
    }

    return -1;
}

#endif // BINARY_SEARCH_BASIC_H_INCLUDED
