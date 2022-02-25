#ifndef PRIMS_H_INCLUDED
#define PRIMS_H_INCLUDED

#include <set>
#include <vector>
#include <iostream>>
#include <limits.h>

#define INF INT_MAX

struct Edge{
    int weight = INF;
    int to_vertex = -1;
    bool operator< (Edge const& other) const{
        return std::make_pair(weight, to_vertex)<std::make_pair(other.weight, other.to_vertex);
    }
};

void prims(
        std::vector<std::vector<std::pair<int, int>>> &graph,
            std::vector<int> &parent,
                int n, int start_vertex, 
                    int &mst_cost){

    std::set<Edge> s;
    s.insert({0, start_vertex});
    std::vector<bool> visited(n);
    std::vector<Edge> min_edge(n);
    min_edge[start_vertex].weight=0;
    for(int i=0; i<n; i++){
        if(s.empty()){
            // no MST exists
            mst_cost = -1;
            return;
        }

        int cur_vertex = s.begin()->to_vertex;
        if(visited[cur_vertex])
            continue;
        
        visited[cur_vertex] = true;
        mst_cost += s.begin()->weight;
        s.erase(s.begin());

        // check for start vertex, as no parent edge exists for it
        if(min_edge[cur_vertex].to_vertex!=-1){
            // MST edge
            std::cout<<cur_vertex<<","<<min_edge[cur_vertex].to_vertex<<std::endl;
        }

        for(std::pair<int, int> edge: graph[cur_vertex]){  
            int neighbor = edge.second;
            int neighbor_weight = edge.first;
            // if this edge from "cur_vertex" has a weight to "neighbor" vertex
            // which is smaller than edge weight between "neighbor" and min_edge[neighbor].to
            // then store this new edge 
            if(!visited[neighbor] && min_edge[neighbor].weight>neighbor_weight){
                // delete the previously stored edge, if this is not done
                // set complexity will not be log(V)
                s.erase({min_edge[neighbor].weight, neighbor});
                // record the vertex from which minimum edge to "neighbor" was found
                min_edge[neighbor] = {neighbor_weight, cur_vertex};
                s.insert({neighbor_weight, neighbor});
            }
        }
    }

    return;
}

#endif // PRIMS_H_INCLUDED
