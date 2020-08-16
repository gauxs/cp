#include <unordered_map>
#include "datastructures/priority_queue/heap/binary/SUBSFREQ/node.h"

#ifndef GENERIC_PRIORITY_QUEUE_H_INCLUDED
#define GENERIC_PRIORITY_QUEUE_H_INCLUDED

using namespace std;

class PriorityQueue{
private:
    int max_heap_size, current_heap_size;
    vector<Node*> heap_array;
    unordered_map<int, int> value_index_map;

    void heapify(Node* node);
    void copy_node(Node* src, Node* dst);
    // returns true if "a" has higher priority than "b", else false
    bool has_higher_priority(Node* a, Node* b);
public:
    PriorityQueue(int max_heap_size){
        this->max_heap_size = max_heap_size;
        this->current_heap_size = 0;
        this->heap_array = vector<Node*>(this->max_heap_size, NULL);
    }

    Node* top();
    Node* extract_top();
    void update_value_frequency(int value, int delta);
    Node* construct();

};

void PriorityQueue::heapify(Node* node, int position){
    parent = position/2;
    left = (2*position) + 1;
    right = (2*position) + 2;

    int to_be_heapified_next = position;
    if(!has_higher_priority(node, heap_array[parent])){
        to_be_heapified_next = parent;
        // swap current with parent
    }else{
        if(!has_higher_priority(node, heap_array[left])){
            to_be_heapified_next = left;
            // swap current with left
        }
        if(!has_higher_priority(to_be_heapified_next, heap_array[right])){
            to_be_heapified_next = left;
            // swap current with right
        }
    }

    if(to_be_heapified_next != position)
        heapify(to_be_heapified_next);
    return ;
}

void PriorityQueue::copy_node(Node* src, Node* dst){
    dst->value = src->value;
    dst->value_frequency = src->value_frequency;
    dst->left = src->left;
    dst->right = src->right;
    return;
}

bool PriorityQueue::has_higher_priority(Node* a, Node* b){
    if(a->value_frequency > b->value_frequency){
        return true;
    }else if(a->value_frequency == b->value_frequency){
        if(a->value < b->value){
            return true;
        }
    }
    return false;
}

Node* PriorityQueue::top(){
    if(!heap_array.empty()){
        return heap_array[0];
    }
    return NULL;
}

Node* PriorityQueue::extract_top(){
    if(heap_array.size()<=0){
        return NULL;
    }

    Node* temp;
    copy_node(heap_array[0], temp);
    value_index_map.erase(heap_array[0]->value);
    value_index_map[heap_array[current_heap_size-1]->value] = 0;

    heap_array[0]->value = heap_array[current_heap_size-1]->value;
    heap_array[0]->value_frequency = heap_array[current_heap_size-1]->value_frequency;

    delete heap_array[current_heap_size-1];
    heap_array[current_heap_size-1]=NULL;
    current_heap_size--;

    if(current_heap_size>0){
        heapify(heap_array[0], 0);
    }
    return temp;
}

void PriorityQueue::update_value_frequency(int value, int frequency_delta){
    unordered_map<int, int>::iterator itr = this->value_index_map.find(value);
    if(itr == this->value_index_map.end()){
        this->value_index_map.insert(pair<int, int>(value, delta));
    }else{
        this.heap_array[itr->second]->value_frequency += frequency_delta;
        // Frequency of this "value" drops below 0 then delete it from heap and value_index_map
        if(this.heap_array[itr->second]->value_frequency <= 0){

        }else{
            heapify(this.heap_array[itr->second], itr->second);
        }
    }
    return;
}

Node* PriorityQueue::construct(vector<int> input, int s, int e){
    for(int i=s; i<=e; i++){
        this->update_value_frequency(input[i], 1);
    }
    return;
}
#endif // GENERIC_PRIORITY_QUEUE_H_INCLUDED
