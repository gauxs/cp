#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

#include <set>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <data_structures/union_find/union_find.h>

#define INF INT_MAX

struct Edge{
    int u, v;
    int weight;

    bool operator< (Edge const& other) const{
        return weight<other.weight;
    }
};

void kruskal(
    std::vector<Edge>& edges,
        int n, int e, int& mst_cost){

    std::vector<int> size(n);
    std::vector<int> parent(n);
    
    initialize(parent, size, n);
    std::sort(edges.begin(), edges.end());
    for(int i=0; i<e; i++){
        int set_u = find_set(parent, edges[i].u);
        int set_v = find_set(parent, edges[i].v);
        if(set_u!=set_v){
            mst_cost += edges[i].weight;
            union_sets(parent, size, edges[i].u, edges[i].v);
        }
    }

    return;
}

#endif // KRUSKAL_H_INCLUDED
