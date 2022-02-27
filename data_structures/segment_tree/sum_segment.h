#ifndef SEGMENT_TREE_H_INCLUDED
#define SEGMENT_TREE_H_INCLUDED

#include <vector>
#include <cmath>

/*
    Utility to find the size of the segment tree needed
    to represent data of size 'input_len'

    Number of leaf nodes has to be in the power of two.
    If N=10, then number of leaf nodes of segment tree will be next power of 2 i.e.16
    by this logic total number of nodes of sement tree (leaf + non-leaf) will be ((2*(16)-1) 
    or (2*(2^(height)))-1 or (2*(2^(log(N)))-1) where N is input size
*/
int find_tree_size(int input_len){
    int tree_height = (int)ceil(log2(input_len));
    return 2*(pow(2, tree_height))-1;
}

void single_update_seg(
    std::vector<int> &seg_tree,
        int seg_l, int seg_r,
            int update_index, int diff,
                int seg_index){

    // update_index not in the range of current seg_tree node
    if(update_index<seg_l || update_index>seg_r)
        return;

    seg_tree[seg_index] += diff;
    if(seg_l!=seg_r){
        int mid = seg_l+(seg_r-seg_l)/2;
        single_update_seg(seg_tree, seg_l, mid, update_index, diff, 2*seg_index+1);
        single_update_seg(seg_tree, mid+1, seg_r, update_index, diff, 2*seg_index+2);
    }
}

/*
    index   -   index of input which will be updated
*/
void single_update_input(
        std::vector<int> &input,
            std::vector<int> &seg_tree,
                int index, int new_val){

    int diff = new_val-input[index];
    input[index] = new_val;
    single_update_seg(seg_tree, 0, seg_tree.size()-1, index, diff, 0);
}

/*
    input_len       -   length of the input on which segment tree is built
    q_l, q_r        -   query ranges
    seg_l, seg_r    -   segment tree range which is represented by 'seg_index'
    seg_index       -   current index of segment tree
*/
int get(
    std::vector<int> &seg_tree,
        int q_l, int q_r,
            int seg_l, int seg_r,
                int seg_index){

    // completely inside range
    if(q_l<=seg_l && q_r>=seg_r)
        return seg_tree[seg_index];

    // completely out of range.
    if(q_l>seg_r || q_r<seg_l)
        return 0;

    // partially in range
    int mid = seg_l+(seg_r-seg_l)/2;
    return get(seg_tree, q_l, q_r, seg_l, mid, 2*seg_index+1) + 
                get(seg_tree, q_l, q_r, mid+1, seg_r, 2*seg_index+2);
}

/*
    input           -   data on which segement tree is to be build
    seg_tree        -   segment tree on the input data
    left,right      -   range of input for which segment tree is to be build
    seg_node_index  -   index of segment tree which represents [left,right] of input
*/
int construct_tree(
    std::vector<int> &input,
        std::vector<int> &seg_tree,
        int left, int right,
            int seg_node_index){

    if(left == right){
        seg_tree[seg_node_index] = input[left];
        return seg_tree[seg_node_index];
    }

    int mid = left+(right-left)/2;
    seg_tree[seg_node_index] = construct_tree(input, seg_tree, left, mid, 2*seg_node_index+1) +
                                        construct_tree(input, seg_tree, mid+1, right, 2*seg_node_index+2);

    return seg_tree[seg_node_index];
}

#endif // SEGMENT_TREE_H_INCLUDED
