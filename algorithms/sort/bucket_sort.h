#ifndef BUCKET_SORT_H_INCLUDED
#define BUCKET_SORT_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

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
struct BucketNode{
    float val;
    BucketNode *next;
};

void insert_into_bucket(std::vector<BucketNode*> &buckets, int bucket_position, BucketNode* node){
    BucketNode *itr = buckets[bucket_position];
    BucketNode *prev_itr=NULL;
    while(itr!=NULL && itr->val<node->val){
        prev_itr = itr;
        itr = itr->next;
    }

    if(itr==NULL){
        if(prev_itr==NULL){
            
        }else{

        }
    }else{

    }

    return;
}

void bucket_sort(std::vector<float> &input, int n){
    std::vector<BucketNode*> buckets(n, NULL);

    int len = input.size();
    for(int i=0; i<len; i++){
        BucketNode *newNode;
        newNode->val = input[i];
        insert_into_bucket(buckets, n*input[i], newNode);
    }

    return;
}

#endif // BUCKET_SORT_H_INCLUDED