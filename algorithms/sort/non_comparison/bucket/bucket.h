#ifndef BUCKET_H_INCLUDED
#define BUCKET_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

struct BucketNode{
    float float_val;
    BucketNode *next;
    BucketNode(float v): float_val(v), next(NULL){}
    BucketNode(float v, BucketNode* n): float_val(v), next(n){}
};

void print_buckets(
        std::vector<BucketNode*>& buckets,
            int n){

    for(int i=0; i<n; i++){
        BucketNode* itr_node = buckets[i];
        while (itr_node!=NULL){
            std::cout<<itr_node->float_val<<std::endl;
            itr_node = itr_node->next;
        }
    }

    return;
}

void insert_into_bucket(
    std::vector<BucketNode*> &buckets,
        int bucket_position, float insert_val){

    BucketNode *itr = buckets[bucket_position];
    BucketNode *prev_itr = NULL;

    // <= makes this stable
    while(itr!=NULL && itr->float_val<=insert_val){
        prev_itr = itr;
        itr = itr->next;
    }

    if(itr==NULL){
        buckets[bucket_position] = new BucketNode(insert_val);
    }else{  // need to insert between two nodes
        if(prev_itr==NULL){
            buckets[bucket_position] = new BucketNode(insert_val, itr);
        }else{
            prev_itr->next = new BucketNode(insert_val, itr);
        }
    }

    return;
}

/*
    this will only work for values between [0, 1)
*/
void bucket_sort_small(
    std::vector<float>& input,
        std::vector<BucketNode*>& buckets){
    int n = buckets.size();
    int len = input.size();

    for(int i=0; i<len; i++){
        insert_into_bucket(buckets, n*input[i], input[i]);
    }

    return;
}

/* 
    this will work for both values between 0 and 1 and for values > 1 
*/
void bucket_sort(
        std::vector<float> &input,
            std::vector<BucketNode*> &buckets){

    float min=INT32_MAX, max=INT32_MIN;
    int num_buckets = buckets.size();
    int input_len = input.size();

    for(int i=0; i<input_len; i++){
        if(input[i]<min)
            min = input[i];

        if(input[i]>max)
            max = input[i];
    }

    float bucket_range = (max - min)/num_buckets;
    for(int i=0; i<input_len; i++)
        insert_into_bucket(buckets, (input[i] - min)/bucket_range, input[i]);

    return;
}

#endif // BUCKET_H_INCLUDED