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

void propogate_update(
        std::vector<int>& seg_tree,
            std::vector<bool>& has_lazy_update,
                int seg_index){

    if(has_lazy_update[seg_index]){
        has_lazy_update[seg_index] = false;
        has_lazy_update[2*seg_index+1] = true;
        has_lazy_update[2*seg_index+2] = true;
        seg_tree[2*seg_index+1] = seg_tree[seg_index];
        seg_tree[2*seg_index+2] = seg_tree[seg_index];
    }
}

/*
    Updates that segment tree with new_val which represent the range [upd_l,upd_r] and also propogates previous
    updates(lazy propogation)

    has_lazy_update -   true if there is an assignment update in this node which need to be propogated to children
    upd_l, upd_r    -   input range which needs to be assigned to new_val
*/
void lazy_assignment(
        std::vector<int>& seg_tree,
            std::vector<bool>& has_lazy_update,
                int seg_index, int seg_l, int seg_r,
                    int upd_l, int upd_r, int new_val){

    if(upd_l>upd_r)
        return;

    if(seg_l==upd_l && seg_r==upd_r){
        seg_tree[seg_index] = new_val;
        has_lazy_update[seg_index] = true;
    }else {
        int mid = seg_l+(seg_r-seg_l)/2;
        propogate_update(seg_tree, has_lazy_update, seg_index);
        lazy_assignment(seg_tree, has_lazy_update, 2*seg_index+1, seg_l, mid, upd_l, std::min(mid, upd_r), new_val);
        lazy_assignment(seg_tree, has_lazy_update, 2*seg_index+2, mid+1, seg_r, std::max(upd_l, mid), upd_r, new_val);
    }
}

/*
    input_len       -   length of the input on which segment tree is built
    q_l, q_r        -   query ranges
    seg_l, seg_r    -   segment tree range which is represented by 'seg_index'
    seg_index       -   current index of segment tree
    has_lazy_update -   true if there is an assignment update in this node which need to be propogated to children
*/
int get(
        std::vector<int>& seg_tree,
            std::vector<bool>& has_lazy_update,
                int q_l, int q_r, int seg_l,
                    int seg_r, int seg_index){

    // completely inside range
    if(q_l<=seg_l && q_r>=seg_r)
        return seg_tree[seg_index];

    // completely out of range.
    if(q_l>seg_r || q_r<seg_l)
        return 0;

    propogate_update(seg_tree, has_lazy_update, seg_index);

    // partially in range
    int mid = seg_l+(seg_r-seg_l)/2;
    return get(seg_tree, has_lazy_update, q_l, q_r, seg_l, mid, 2*seg_index+1) + 
                get(seg_tree, has_lazy_update, q_l, q_r, mid+1, seg_r, 2*seg_index+2);
}

/*
    Builds a sum segment tree

    input           -   data on which segement tree is to be build
    seg_tree        -   segment tree on the input data
    left,right      -   range of input for which segment tree is to be build
    seg_node_index  -   index of segment tree which represents [left,right] of input
*/
int build(
        std::vector<int>& input,
            std::vector<int>& seg_tree,
                int left, int right,
                    int seg_node_index){

    if(left == right){
        seg_tree[seg_node_index] = input[left];
        return seg_tree[seg_node_index];
    }

    int mid = left+(right-left)/2;
    seg_tree[seg_node_index] = build(input, seg_tree, left, mid, 2*seg_node_index+1) +
                                        build(input, seg_tree, mid+1, right, 2*seg_node_index+2);

    return seg_tree[seg_node_index];
}

#endif // SEGMENT_TREE_H_INCLUDED
