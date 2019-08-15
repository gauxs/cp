#ifndef HEAPBASIC_H_INCLUDED
#define HEAPBASIC_H_INCLUDED

void max_heapify(vector<int> &arr, int n, int i){
    int left_child=2*i+1;
    int right_child=2*i+2;
    int largest=i;

    if(left_child<n && arr[left_child]>arr[i])
        largest=left_child;

    if(right_child<n && arr[right_child]>arr[largest])
        largest=right_child;

    if(largest!=i){
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
    return;
}

void min_heapify(vector<int> &arr, int n, int i){
    int left_child=2*i+1;
    int right_child=2*i+2;
    int smallest=i;

    if(left_child<n && arr[left_child]<arr[i])
        smallest=left_child;

    if(right_child<n && arr[right_child]<arr[smallest])
        smallest=right_child;

    if(smallest!=i){
        swap(arr[i], arr[smallest]);
        min_heapify(arr, n, smallest);
    }
    return;
}

void heap_basic_sort(vector<int> &arr, int n){
    for(int i=n/2-1; i>=0; i--){
        max_heapify(arr, n, i);
    }

    for(int i=n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
    return;
}

#endif // HEAPBASIC_H_INCLUDED
