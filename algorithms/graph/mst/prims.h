#ifndef PRIMS_H_INCLUDED
#define PRIMS_H_INCLUDED

#include <vector>
#include <limits.h>

#define INF INT_MAX

/*
    Reference: https://cp-algorithms.com/graph/mst_prim.html
*/

struct edge{
    int weight;
    int to;
};

/*
    Time complexity: O(N^2)
    Space complexity: O(N)
*/
int prims_dense(std::vector<std::vector<int>> &adj, std::vector<bool> &selected, std::vector<edge> &min_edge, int n){
    int total_weight = 0;
    min_edge[0].weight = 0;

    for(int i=0; i<n; i++){
        int min_e_vertex = -1;
        for(int j=0; j<n; j++){
            if(!selected[j] && (min_e_vertex==-1 || (min_edge[j].weight<min_edge[min_e_vertex].weight)))
                min_e_vertex = j;
        }

        if(min_edge[min_e_vertex].weight==INF){
            return -1;
        }

        selected[min_e_vertex] = true;
        total_weight += min_edge[min_e_vertex].weight;

        for(int j=0; j<n; j++){
            if(min_edge[j].weight>adj[j][min_e_vertex])
                min_edge[j] = {adj[j][min_e_vertex], min_e_vertex};
        }
    }

    return total_weight;
}

/*
    Time complexity: O(M*log(N))
    Space complexity: O(N)
*/
int prims_sparse(){

}

#endif // PRIMS_H_INCLUDED
