#ifndef QUICKBASIC_H_INCLUDED
#define QUICKBASIC_H_INCLUDED

int rand_partition(vector<int> &arr, int left, int right){
    int pivot_pos=left+rand()%(right-left+1);
    int pivot=arr[pivot_pos];
    swap(arr[pivot_pos], arr[left]);
    int j=left+1;
    for(int i=left+1; i<=right; i++){
        if(arr[i]<=pivot){
            swap(arr[j], arr[i]);
            j++;
        }
    }

    swap(arr[j-1], arr[left]);
    return j-1;
}

void quick_rand_sort(vector<int> &arr, int left, int right){
    if(left<right){
        int pivot=rand_partition(arr, left, right);
        quick_basic_sort(arr, left, pivot-1);
        quick_basic_sort(arr, pivot+1, right);
    }
    return;
}

#endif // QUICKBASIC_H_INCLUDED
