#ifndef SEGMENT_TREE_BASIC_H_INCLUDED
#define SEGMENT_TREE_BASIC_H_INCLUDED

/*
    Number of leaf nodes has to be in the power of two.
    If N=10, then number of leaf nodes will be next power of 2 i.e.16
    By this logic total number of nodes(leaf + non-leaf) will be 2*16-1.
    OR, (2*(2^(height)))-1 OR (2*(2^(log(N)))-1).
*/
int find_seg_tree_size(int num_of_nodes){
    int seg_tree_height = (int)ceil(log2(num_of_nodes));
    int seg_tree_size = 2*(pow(2, seg_tree_height))-1;
    //cout<<"Seg tree size: "<<seg_tree_size<<endl;
    return seg_tree_size;
}

void update_val_util(vector<int> &segment_tree, int segment_l, int segment_r,
                     int update_index, int diff, int segment_index){
    if(update_index<segment_l || update_index>segment_r){
        return;
    }
    segment_tree[segment_index] += diff;
    if(segment_l!=segment_r){
        int mid = segment_l+(segment_r-segment_l)/2;
        update_val_util(segment_tree, segment_l, mid, update_index, diff, 2*segment_index+1);
        update_val_util(segment_tree, mid+1, segment_r, update_index, diff, 2*segment_index+2);
    }
}

void update_val(vector<int> &input, vector<int> &segment_tree, int index, int new_val){
    int input_size = input.size();
    int segment_tree_size = segment_tree.size();
    if(index<0 || index>=input_size){
        return;
    }
    int diff = new_val-input[index];
    input[index] = new_val;
    update_val_util(segment_tree, 0, segment_tree_size-1, index, diff, 0);
    return;
}

int get_sum_util(vector<int> &segment_tree, int seg_tree_l, int seg_tree_r, int q_l, int q_r, int seg_index){
    //totally inside range.
    if(q_l<=seg_tree_l && q_r>=seg_tree_r){
        return segment_tree[seg_index];
    }
    //completely out of range.
    if(q_l>seg_tree_r || q_r<seg_tree_l){
        return 0;
    }
    //Partially in range.
    int mid = seg_tree_l+(seg_tree_r-seg_tree_l)/2;
    return get_sum_util(segment_tree, seg_tree_l, mid, q_l, q_r, 2*seg_index+1) +
            get_sum_util(segment_tree, mid+1, seg_tree_r, q_l, q_r, 2*seg_index+2);
}

int get_sum(vector<int> &segment_tree, int query_l, int query_r){
    int n = segment_tree.size();
    if(query_l<0 || query_r>=n || query_l>query_r){
        return -1;
    }
    return get_sum_util(segment_tree, 0, n-1, query_l, query_r, 0);
}

int construct_sum_segment_tree_util(vector<int> &input, int inp_node_start,
                                      int inp_node_end, vector<int> &segment_tree, int seg_node_index){
    if(inp_node_start == inp_node_end){
        segment_tree[seg_node_index] = input[inp_node_start];
        return segment_tree[seg_node_index];
    }

    int mid = inp_node_start+(inp_node_end-inp_node_start)/2;
    segment_tree[seg_node_index] = construct_sum_segment_tree_util(input, inp_node_start, mid, segment_tree, 2*seg_node_index+1) +
                                        construct_sum_segment_tree_util(input, mid+1, inp_node_end, segment_tree, 2*seg_node_index+2);

    return segment_tree[seg_node_index];
}

void construct_sum_segment_tree(vector<int> &input, vector<int> &segment_tree){
    construct_sum_segment_tree_util(input, 0, input.size()-1, segment_tree, 0);
    return;
}

//int main(){
//    std::ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int n;
//    cin>>n;
//    vector<int> input(n);
//    for(int i=0; i<n; i++){
//        cin>>input[i];
//    }
//
//    vector<int> seg_tree(find_seg_tree_size(n));
//    construct_sum_segment_tree(input, seg_tree);
//    cout<<get_sum(seg_tree, 0, seg_tree.size()-1)<<endl;
//
//    update_val(input, seg_tree, 3, 8);
//    cout<<get_sum(seg_tree, 0, seg_tree.size()-1)<<endl;
//    return 0;
//}

#endif // SEGMENT_TREE_BASIC_H_INCLUDED
