#ifndef BELLMAN_FORD_H_INCLUDED
#define BELLMAN_FORD_H_INCLUDED

#include <vector>
#include <limits.h>
#include <algorithm>

struct edge{
    int from, to, weight;
};

/*
    returns negative cycle, if it exists
*/ 
std::vector<int> bellman_ford(
    std::vector<edge> &edges,
        std::vector<int> &distances,
            std::vector<int> &predecessor,
                int n, int m, int vertex){

    for(int i=0; i<n; i++){
        distances[i] = INT_MAX;
        predecessor[i] = -1;
    }

    distances[vertex] = 0;
    int last_vertex_relaxed = -1;
    for(int i=0; i<n; i++){
        last_vertex_relaxed = -1;
        for(int j=0; j<m; j++){
            // if the vertex is yet not relaxed then it's distance will be INT_MAX and should be skipped
            // if the graph has -ve weight, we can get distances like INT_MAX-1, INT_MAX-X etc. these 
            // invalid cases will also be skipped, because of this check
            if(distances[edges[j].from]<INT_MAX){    
                if(distances[edges[j].to] > (distances[edges[j].from] + edges[j].weight)){
                    distances[edges[j].to] = distances[edges[j].from] + edges[j].weight;
                    predecessor[edges[j].to] = edges[j].from;
                    last_vertex_relaxed = edges[j].to; 
                }
            }
        }

        if(last_vertex_relaxed==-1)
            break;
    }

    std::vector<int> negative_cycle;
    // negative cycle exists
    if(last_vertex_relaxed != -1){      
        int y = last_vertex_relaxed;
        
        // reaching(trying to come inside) the negative cycle
        for(int i=0; i<n; i++){ 
            y = predecessor[y];
        }

        for(int cur_v=y; ; cur_v = predecessor[cur_v]){
            negative_cycle.push_back(cur_v);
            if(cur_v==y && negative_cycle.size()>1)
                break;
        }

        reverse(negative_cycle.begin(), negative_cycle.end());
    }

    return negative_cycle;
}

std::vector<int> print_path(
    std::vector<int> &distances, 
        std::vector<int> &predecessor, 
            int n, int source, int vertex){

    std::vector<int> path;
    if(distances[vertex]!=INF){
        while(vertex!=-1){
            path.push_back(vertex);
            vertex = predecessor[vertex];
        }

        reverse(path.begin(), path.end());
    }

    return path;
}

#endif // BELLMAN_FORD_H_INCLUDED
