#ifndef PRIMS_H_INCLUDED
#define PRIMS_H_INCLUDED

#include <vector>
#include <queue>
#include <limits.h>

#define INF INT_MAX

void prims(
        std::vector<std::vector<std::pair<int, int>>> &graph,
            std::vector<int> &parent,
                int n, int start_vertex, 
                    int &mst_cost){

    std::vector<int> parent(n, -1);
    std::vector<bool> visited(n, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<int>> pq;   // min priority queue

    pq.push(std::make_pair(0, start_vertex));
    while(!pq.empty()){
        std::pair<int, int> min_edge = pq.top();
        pq.pop();

        int vertex = min_edge.second;
        if(visited[vertex])
            continue;
        
        visited[vertex] = true;
        mst_cost += min_edge.first;
        int smallest_weight = INF;
        for(std::pair<int, int> edge: graph[vertex]){  
            int other_vertex = edge.second;
            if(!visited[other_vertex]){     // add one more state "picked" to avoid adding same vertex twice
                pq.push(edge);
                if(edge.first < smallest_weight){
                    parent[other_vertex] = vertex;
                    smallest_weight = edge.first;
                }
            }
        }
    }

    return;
}

#endif // PRIMS_H_INCLUDED
