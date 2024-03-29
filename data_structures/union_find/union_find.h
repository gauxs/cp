#ifndef DISJOINT_SET_UNION_H_INCLUDED
#define DISJOINT_SET_UNION_H_INCLUDED

#include <vector>

void initialize(std::vector<int> &parent, std::vector<int> &size, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        size[i] = 1;    
    }
}

/*
    creates a new set consisting of the new element
*/
void make_set(std::vector<int> &parent, std::vector<int> &size, int v){
    parent[v] = v;
    size[v] = 1;
}

/*
    returns the representative (also called leader) of the set that contains the element x 
*/
int find_set(std::vector<int> &parent, int x){
    while(parent[x]!=x){
        parent[x]=parent[parent[x]];
        x=parent[x];
    }

    return x;
}

/*
    merges the two specified sets (the set in which the element a is located, and the set in which the element b is located)
*/
void union_sets(std::vector<int> &parent, std::vector<int> &size, int a, int b){
    int parent_a = find_set(parent, a);
    int parent_b = find_set(parent, b);

    if(size[parent_a]<=size[parent_b]){
        parent[parent_a]=parent_b;
        size[parent_b]+=size[parent_a];
    }else{
        parent[parent_b]=parent_a;
        size[parent_a]+=size[parent_b];
    }
}

#endif // DISJOINT_SET_UNION_H_INCLUDED
