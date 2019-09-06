#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

#pragma GCC optimize("Ofast")
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template <typename T>
struct Heap{
    bool isMaxHeap;
    int *pos;
    int heap_size;
    int heap_capacity;
    T **heap_store;
};

template <typename T>
struct Heap<T>* createHeap(int capacity){
    struct Heap<T>* h=(struct Heap<T>*)malloc(sizeof(struct Heap<T>));
    h->pos=(int *)malloc(capacity*sizeof(int));
    h->heap_size=0;
    h->heap_capacity=capacity;
    h->heap_store=(T**)malloc(capacity*sizeof(T*));
    return h;
}

template <typename T>
void swapHeapNode(T** a, T** b){
    T* t = *a;
    *a = *b;
    *b = t;
}

template <typename T>
bool isInMinHeap(struct Heap<T> *heap, int v) {
   if (heap->pos[v] < heap->heap_size)
     return true;
   return false;
}

template <typename T>
void heapify(struct Heap<T>* h, int index){
    int smallest, left, right;
    smallest = index;
    left = (2*index)+1;
    right = (2*index)+2;

    if (left<h->heap_size &&
            h->heap_store[left]->dist < h->heap_store[smallest]->dist )
      smallest = left;

    if (right<h->heap_size &&
            h->heap_store[right]->dist < h->heap_store[smallest]->dist )
      smallest = right;

    if (smallest!=index){
        T* smallestNode = h->heap_store[smallest];
        T* idxNode = h->heap_store[index];

        h->pos[smallestNode->v] = index;
        h->pos[idxNode->v] = smallest;

        swapHeapNode(&h->heap_store[smallest], &h->heap_store[index]);
        heapify(h, smallest);
    }
}

template <typename T>
int isEmpty(struct Heap<T>* heap){
    return heap->heap_size == 0;
}

template <typename T>
T* extractMin(struct Heap<T>* heap){
    if (isEmpty(heap))
        return NULL;

    // Store the root node
    T* root = heap->heap_store[0];

    // Replace root node with last node
    T* lastNode = heap->heap_store[heap->heap_size - 1];
    heap->heap_store[0] = lastNode;

    // Update position of last node
    heap->pos[root->v] = heap->heap_size-1;
    heap->pos[lastNode->v] = 0;

    // Reduce heap size and heapify root
    --heap->heap_size;
    heapify(heap, 0);

    return root;
}

template <typename T>
void updateKey(struct Heap<T>* heap, int v, int dist){
    // Get the index of v in  heap array
    int i = heap->pos[v];

    // Get the node and update its dist value
    heap->heap_store[i]->dist = dist;

    // Travel up while the complete tree is not heapified.
    // This is a O(Logn) loop
    while (i && heap->heap_store[i]->dist < heap->heap_store[(i-1)/2]->dist){
        // Swap this node with its parent
        heap->pos[heap->heap_store[i]->v] = (i-1)/2;
        heap->pos[heap->heap_store[(i-1)/2]->v] = i;
        swapHeapNode(&heap->heap_store[i],  &heap->heap_store[(i-1)/2]);

        // move to parent index
        i=(i-1)/2;
    }
}

struct graph_node{
    int v;
    int dist;
    vector<pair<int,int> > neighbors;
};

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b, w;
    cin>>n>>m;

    struct Heap<struct graph_node>* hp = createHeap<struct graph_node>(n);

    for(int i=0; i<n+1; i++){
        hp->heap_store[i]=new struct graph_node();
    }

    for(int i=0; i<m; i++){
        cin>>a>>b>>w;
        a-=1;
        b-=1;
        hp->heap_store[a]->v=a;
        hp->heap_store[a]->dist=INT_MAX;
        hp->heap_store[a]->neighbors.push_back(make_pair(w, b));

        hp->heap_store[b]->v=b;
        hp->heap_store[b]->dist=INT_MAX;
        hp->heap_store[b]->neighbors.push_back(make_pair(w, a));
    }

    int src_node=0;
    updateKey(hp, src_node, 0);
    hp->heap_size=n;

    while(!isEmpty(hp)){
        struct graph_node* gn = extractMin(hp);
        for(int j=0; j<gn->neighbors.size(); j++){
            int v=gn->neighbors[j].second;
            int w=gn->neighbors[j].first;

            if((gn->dist+w)<hp->heap_store[v]->dist){
                updateKey(hp, v, (gn->dist+w));
            }
        }
    }

    return 0;
}


#endif // DIJKSTRA_H_INCLUDED
