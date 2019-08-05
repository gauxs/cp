#ifndef MERGEBASIC_H_INCLUDED
#define MERGEBASIC_H_INCLUDED

void merge_array(std::vector<int> &arr, int left, int mid, int right){
    int left_pos=left, right_pos=mid+1, k=0;
    std::vector<int> temp_arr(right-left+1);
    for(int i=left_pos; i<=right; i++){
        if(left_pos>mid){
            temp_arr[k]=arr[right_pos];
            k++;
            right_pos++;
        }else if(right_pos>right){
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

void merge_basic_sort(std::vector<int> &arr, int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        merge_basic_sort(arr, left, mid);
        merge_basic_sort(arr, mid+1, right);
        merge_array(arr, left, mid, right);
    }
    return;
}

#endif // MERGEBASIC_H_INCLUDED
