#ifndef BINARY_H_INCLUDED
#define BINARY_H_INCLUDED

#include <vector>

/*
    Returns the index of the element if found, else -1
*/
int binary_iterative(std::vector<int> &input, int low, int high, int ele){
    while(low<=high){   // for checking low==high cases
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

/*
    Returns the index of the element if found, else -1
*/
int binary_recursive(std::vector<int> &input, int left, int right, int ele){
    if(left<=right){
        int mid = left + (right - left)/2;
        if(input[mid] == ele){
            return mid;
        }else if(input[mid] > ele){
            return binary_recursive(input, left, mid-1, ele);
        }else{
            return binary_recursive(input, mid+1, right, ele);
        }
    }

    return -1;
}

#endif // BINARY_H_INCLUDED
