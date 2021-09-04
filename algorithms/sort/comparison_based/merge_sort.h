#ifndef MERGE_SORT_H_INCLUDED
#define MERGE_SORT_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

/*
    Its's a Divide and Conquer algorithm. It divides the input array into two halves, calls itself for the two halves,
    and then merges the two sorted halves. The merge() function is used for merging two halves. The merge(arr, l, m, r)
    is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. 

    Drawbacks:
    1.  Slower comparative to the other sort algorithms for smaller tasks.
    2.  Merge sort algorithm requires additional memory space of 0(n) for the temporary array .
    3.  It goes through the whole process even if the array is sorted.

    Reference:  https://www.geeksforgeeks.org/merge-sort/ 
*/

void merge_array(std::vector<int> &arr, int left, int mid, int right){
    int left_pos=left, right_pos=mid+1, k=0;
    std::vector<int> temp_arr(right-left+1);
    // iterate for number of element in both the array
    for(int i=left_pos; i<=right; i++){
        if(left_pos>mid){                           // left array is exhausted, blindly copy right array 
            temp_arr[k]=arr[right_pos];
            k++;
            right_pos++;
        }else if(right_pos>right){                  // right array is exhausted, blindly copy left array 
            temp_arr[k]=arr[left_pos];
            k++;
            left_pos++;
        }else if(arr[left_pos]<=arr[right_pos]){
            temp_arr[k]=arr[left_pos];
            k++;
            left_pos++;
        }else{
            temp_arr[k]=arr[right_pos];
            k++;
            right_pos++;
        }
    }

    for(int i=0; i<k; i++){
        arr[left]=temp_arr[i];
        left++;
    }

    return;
}

/*
    Time complexity:    T(n) = 2T(n/2) + θ(n)
    1.  Worst: O(n * log(n))
    2.  Average: O(n * log(n))
    3.  Best: O(n * log(n))

    Space complexity: O(n)

    Inplace sorting: No
    Stable sorting: yes
*/
void merge_sort(std::vector<int> &arr, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge_array(arr, left, mid, right);
    }

    return;
}

#endif // MERGE_SORT_H_INCLUDED

// int main(){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     std::cout.tie(NULL);

//     std::vector<int> input{5, 2, 4, 3, -2, -4, 1};
//     merge_sort(input, 0, input.size()-1);

//     myutils::myprint::print(input, input.size());
// }