#ifndef PRIORITY_QUEUE_H_INCLUDED
#define PRIORITY_QUEUE_H_INCLUDED

#include <vector>

void min_heapify(std::vector<int>& heap, int n, int cur_index){
    int left_index = (2 * cur_index) + 1;
    int right_index = (2 * cur_index) + 2;
    int smallest_index = cur_index;

    if(left_index<n && heap[smallest_index]>heap[left_index])
        smallest_index = left_index;

    if(right_index<n && heap[smallest_index]>heap[right_index])
        smallest_index = right_index;

    if(smallest_index!=cur_index){
        std::swap(heap[cur_index], heap[smallest_index]);
        min_heapify(heap, n, smallest_index);
    }

    return;
}

// modifies the "cur_heap_size"
void add_to_min_heap(std::vector<int>& heap, int heap_capacity, int val, int& cur_heap_size){
    if(cur_heap_size==heap_capacity)
        return;

    int last_index = cur_heap_size;
    heap[last_index] = val;
    while(last_index>=0 && heap[(last_index-1)/2]>heap[last_index]){
        std::swap(heap[(last_index-1)/2], heap[last_index]);
        last_index = (last_index-1)/2;
    }

    cur_heap_size += 1;
    return;
}

void extract_min(std::vector<int>& heap, int heap_capacity, int& cur_heap_size){
    int min_val = heap[0];

    std::swap(heap[0], heap[cur_heap_size-1]);
    cur_heap_size -= 1;
    min_heapify(heap, cur_heap_size, 0);
    return;
}

void build_min_heap(std::vector<int>& num, int n){
    for(int i=(n/2)-1; i>=0; i--){
        min_heapify(num, n, i);
    }

    return;
}

#endif // PRIORITY_QUEUE_H_INCLUDED
