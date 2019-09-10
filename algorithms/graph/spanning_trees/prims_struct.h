#ifndef PRIMS_MST_H_INCLUDED
#define PRIMS_MST_H_INCLUDED

#pragma GCC optimize("Ofast")
#include <iostream>
#include <bits/stdc++.h>
#define GraphNode T
using namespace std;

struct Edge{
    int src_node;
    int weight;
    int dest_node;
    struct Edge* next_edge;
};

struct GraphNode{
    bool visited;
    int weight;
    int cur_node;
    struct Edge* edges_list_head;
};

// graph_nodes_list - This is "0" based.
struct Graph{
    int num_of_nodes;
    struct GraphNode* graph_nodes_list;
};

struct Edge* create_edge(int src, int weight, int dst){
    struct Edge* new_edge=(struct Edge*)malloc(sizeof(struct Edge));
    new_edge->src_node=src;
    new_edge->dest_node=dst;
    new_edge->weight=weight;
    new_edge->next_edge=NULL;
    return new_edge;
}

struct Graph* create_graph(int num_of_nodes){
    struct Graph* newGraph=(struct Graph*)malloc(sizeof(struct Graph));
    newGraph->num_of_nodes=num_of_nodes;
    newGraph->graph_nodes_list=(struct GraphNode*)malloc(num_of_nodes*sizeof(struct GraphNode));
    for(int i=0; i<num_of_nodes; i++){
        newGraph->graph_nodes_list[i].visited=false;
        newGraph->graph_nodes_list[i].weight=INT_MAX;
        newGraph->graph_nodes_list[i].edges_list_head=NULL;
    }
    return newGraph;
}

// src/dst - These are "0" based. If question is "1" based send "src-1".
struct Edge* add_graph_edge(struct Graph* graph, int src, int dst, int weight){
    struct GraphNode* src_node=&(graph->graph_nodes_list[src]);
    src_node->cur_node=src;
    struct Edge* edge=create_edge(src, weight, dst);
    edge->next_edge=src_node->edges_list_head;
    src_node->edges_list_head=edge;
    return edge;
}

// node_index - To uniquely identify each node, helpful in "update" operations.
// Heap->node_pos index and HeapNode->node_index are same.
struct HeapNode {
    int node_index;
    T* node;
};

struct Heap {
    bool is_max_heap;
    int heap_size;
    int heap_capacity;
    // specifies the position of nodes(index represent the nodes) in heap_array.
    int* node_pos;
    struct HeapNode** heap_array;
};

struct Heap* create_heap(bool is_max_heap, int capacity){
    struct Heap* heap=(struct Heap*)malloc(sizeof(struct Heap));
    heap->is_max_heap=is_max_heap;
    heap->heap_size=0;
    heap->heap_capacity=capacity;
    heap->node_pos=(int*)malloc(capacity*sizeof(int));
    heap->heap_array=(struct HeapNode**)malloc(capacity*sizeof(struct HeapNode*));
    return heap;
}

void swap_heap_nodes(struct HeapNode** node_a, struct HeapNode** node_b){
    struct HeapNode* temp=*node_a;
    *node_a=*node_b;
    *node_b=temp;
}

void heapify(struct Heap* heap, int index){
    int left=(2*index)+1;
    int right=(2*index)+2;

    if(!heap->is_max_heap){
        int smallest=index;
        // Change "weight" with your choice of comparison attribute.
        if(left<heap->heap_size && heap->heap_array[left]->node->weight<heap->heap_array[smallest]->node->weight){
            smallest=left;
        }

        // Change "weight" with your choice of comparison attribute.
        if(right<heap->heap_size && heap->heap_array[right]->node->weight<heap->heap_array[smallest]->node->weight){
            smallest=right;
        }

        if(smallest!=index){
            heap->node_pos[heap->heap_array[smallest]->node_index]=index;
            heap->node_pos[heap->heap_array[index]->node_index]=smallest;
            swap_heap_nodes(&(heap->heap_array[smallest]), &(heap->heap_array[index]));
            heapify(heap, smallest);
        }
    }else{
        int largest=index;
        // Change "weight" with your choice of comparison attribute.
        if(left<heap->heap_size && heap->heap_array[left]->node->weight>heap->heap_array[largest]->node->weight){
            largest=left;
        }

        // Change "weight" with your choice of comparison attribute.
        if(right<heap->heap_size && heap->heap_array[right]->node->weight>heap->heap_array[largest]->node->weight){
            largest=right;
        }

        if(largest!=index){
            heap->node_pos[heap->heap_array[largest]->node_index]=index;
            heap->node_pos[heap->heap_array[index]->node_index]=largest;
            swap_heap_nodes(&(heap->heap_array[largest]), &(heap->heap_array[index]));
            heapify(heap, largest);
        }
    }
}

bool is_heap_empty(struct Heap* heap){
    if(heap->heap_size==0){
        return true;
    }else{
        return false;
    }
}

struct HeapNode* extract_top(struct Heap* heap){
    if(is_heap_empty(heap)){
        return NULL;
    }

    struct HeapNode* root_node=heap->heap_array[0];
    struct HeapNode* last_node=heap->heap_array[heap->heap_size-1];

    heap->heap_array[0]=last_node;
    heap->node_pos[root_node->node_index]=heap->heap_size-1;
    heap->node_pos[last_node->node_index]=0;

    --(heap->heap_size);
    heapify(heap, 0);
    return root_node;
}

void print_heap(struct Heap* heap, int n){
    cout<<"Printing heap node positions: "<<endl;
    for(int i=0; i<n; i++){
        cout<<"Node: "<<i<<" ";
        cout<<"Node Pos: "<<heap->node_pos[i];
        cout<<endl;
    }
    cout<<"Printing Heap:"<<endl;
    for(int i=0; i<n; i++){
        cout<<"Node: "<<heap->heap_array[i]->node->cur_node<<" ";
        cout<<"Weight: "<<heap->heap_array[i]->node->weight;
        cout<<endl;
    }
}

void update_value(struct Heap* heap, int index, int new_value){
    int i=heap->node_pos[index];
    heap->heap_array[i]->node->weight=new_value;

    if(!heap->is_max_heap){
        while(i>0 && (heap->heap_array[i]->node->weight)<(heap->heap_array[(i-1)/2]->node->weight)){
            heap->node_pos[heap->heap_array[i]->node_index]=(i-1)/2;
            heap->node_pos[heap->heap_array[(i-1)/2]->node_index]=i;
            swap_heap_nodes(&heap->heap_array[i], &heap->heap_array[(i-1)/2]);
            i=(i-1)/2;
        }
    }else{
        while(i>0 && heap->heap_array[i]->node->weight>heap->heap_array[(i-1)/2]->node->weight){
            heap->node_pos[heap->heap_array[i]->node_index]=(i-1)/2;
            heap->node_pos[heap->heap_array[(i-1)/2]->node_index]=i;
            swap_heap_nodes(&(heap->heap_array[i]), &(heap->heap_array[(i-1)/2]));
            i=(i-1)/2;
        }
    }
}

//int main(){
//    std::ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int n, m, a, b, w;
//    cin>>n>>m;
//
//    struct Graph* graph=create_graph(n);
//    struct Heap* heap=create_heap(false, n);
//
//    struct HeapNode* hn;
//    for(int i=1; i<=n; i++){
//        hn=(struct HeapNode*)malloc(sizeof(struct HeapNode));
//        hn->node_index=i-1;
//        hn->node=&(graph->graph_nodes_list[i-1]);
//        heap->heap_size++;
//        heap->node_pos[i-1]=i-1;
//        heap->heap_array[i-1]=hn;
//    }
//
//    for(int i=1; i<=m; i++){
//        cin>>a>>b>>w;
//        add_graph_edge(graph, a-1, b-1, w);
//        add_graph_edge(graph, b-1, a-1, w);
//    }
//
//    for(int i=n/2-1; i>=0; i--){
//        heapify(heap, i);
//    }
//
//    update_value(heap, 0, 0);
//
//    int cost=0;
//    while(!is_heap_empty(heap)){
//        struct HeapNode* min_node=extract_top(heap);
//        graph->graph_nodes_list[min_node->node->cur_node].visited=true;
//        cost+=graph->graph_nodes_list[min_node->node->cur_node].weight;
//        for(struct Edge* ne=min_node->node->edges_list_head; ne!=NULL; ne=ne->next_edge){
//            if(!graph->graph_nodes_list[ne->dest_node].visited){
//                if(graph->graph_nodes_list[ne->dest_node].weight>ne->weight){
//                    update_value(heap, ne->dest_node, ne->weight);
//                }
//            }
//        }
//    }
//    cout<<cost<<endl;
//
//    return 0;
//}

#endif // PRIMS_MST_H_INCLUDED
