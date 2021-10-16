#ifndef FIND_CYCLE_H_INCLUDED
#define FIND_CYCLE_H_INCLUDED

#include <vector>
#include <algorithm>

// using DFS algorithm
bool has_cycle(
        std::vector<std::vector<int>> &adj,
            std::vector<int> &color,
                std::vector<bool> &parent,
                    int &cycle_start, int &cycle_end,
                        int cur_vertex){
    
    color[cur_vertex] = 1;
    for(int neighbor: adj[cur_vertex]){
        if(color[neighbor]==0){
            parent[neighbor] = cur_vertex;
            if(has_cycle(adj, color, parent, cycle_start, cycle_end, neighbor))
                return true;
        }else if(color[neighbor]==1){
            cycle_end = cur_vertex;
            cycle_start = neighbor;
            return true;
        }
    }

    color[cur_vertex] = 2;
    return false;
}

std::vector<int> find_cycle_directed(
                    std::vector<std::vector<int>> &adj,
                        int n){

    std::vector<int> color(n);
    std::vector<bool> parent(n, -1);
    int cycle_start = -1, cycle_end = -1;

    for(int i=0; i<n; i++){
        if(color[i]==0 && has_cycle(adj, color, parent, cycle_start, cycle_end, i))
            break;
    }

    std::vector<int> cycle;
    if(cycle_start!=-1){
        while(cycle_end!=cycle_start){
            cycle.push_back(cycle_end);
            cycle_end = parent[cycle_end];
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
    }

    return cycle;
}

void find_cycle_undirected(){

}

#endif // FIND_CYCLE_H_INCLUDED