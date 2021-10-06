#ifndef BELLMAN_FORD_H_INCLUDED
#define BELLMAN_FORD_H_INCLUDED

#include <vector>
#include <limits.h>
#include <bits/stdc++.h>

#define INF INT_MAX

/*
    Suppose that we are given a weighted directed graph G with n vertices and m edges, and some specified vertex v.
    You want to find the length of shortest paths from vertex v to every other vertex.

    Unlike the Dijkstra algorithm, this algorithm can also be applied to graphs containing negative weight edges.
    However, if the graph contains a negative cycle, then, clearly, the shortest path to some vertices may not exist (due
    to the fact that the weight of the shortest path must be equal to minus infinity);
    
    However, this algorithm can be modified to signal the presence of a cycle of negative weight, or even deduce this cycle.

    Reference: https://cp-algorithms.com/graph/bellman_ford.html
*/

struct edge{
    int from, to, weight;
};

/*
    1 - This algorithm can also be applied to graphs containing negative weight edges.
    2 - Returns negative cycle if it exists.
    
    Time complexity:    O(N^M) = O(N^3)  // for dense graph M ≈ N^2
    Space complexity:   O(N)
*/
std::vector<int> bellman_ford(std::vector<edge> &edges, std::vector<int> &distances, std::vector<int> &predecessor, int n, int m, int vertex){
    for(int i=0; i<n; i++){
        distances[i] = INF;
        predecessor[i] = -1;
    }

    distances[vertex] = 0;
    int last_vertex_relaxed = -1;
    for(int i=0; i<n; i++){
        bool relaxation_done = false;
        last_vertex_relaxed = -1;
        for(int j=0; j<m; j++){
            if(distances[edges[j].from]<INF){    // is needed only if the graph contains negative weight edges
                if(distances[edges[j].to] > (distances[edges[j].from] + edges[j].weight)){
                    distances[edges[j].to] = distances[edges[j].from] + edges[j].weight;
                    predecessor[edges[j].to] = edges[j].from;
                    relaxation_done = true;
                    last_vertex_relaxed = edges[j].to; 
                }
            }
        }

        if(!relaxation_done)
            break;
    }

    std::vector<int> negative_cycle;
    // negative cycle exists
    if(last_vertex_relaxed != -1){
        int y = last_vertex_relaxed;
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

    return;
}

std::vector<int> print_path(std::vector<int> &distances, std::vector<int> &predecessor, int n, int source, int vertex){
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
