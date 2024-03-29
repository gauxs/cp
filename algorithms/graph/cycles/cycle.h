#ifndef CYCLE_H_INCLUDED
#define CYCLE_H_INCLUDED

#include <vector>
#include <algorithm>

/*
    Using DFS
*/
bool has_cycle_directed(
        std::vector<std::vector<int>> &adj,
            std::vector<int> &color,
                std::vector<int> &parent,
                    int &cycle_start, int &cycle_end,
                        int cur_vertex){
    
    color[cur_vertex] = 1;
    for(int neighbor: adj[cur_vertex]){
        if(color[neighbor]==0){
            parent[neighbor] = cur_vertex;
            if(has_cycle_directed(adj, color, parent, cycle_start, cycle_end, neighbor))
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

std::vector<int> cycle_directed(
                    std::vector<std::vector<int>> &adj,
                        int n){

    std::vector<int> color(n);
    std::vector<int> parent(n, -1);
    int cycle_start = -1, cycle_end = -1;

    for(int i=0; i<n; i++){
        if(color[i]==0 && has_cycle_directed(adj, color, parent, cycle_start, cycle_end, i))
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

/* 
    using DFS
*/
bool has_cycle_undirected(
        std::vector<std::vector<int>> &adj,
            std::vector<bool> &visited,
                std::vector<int> &parent,
                    int &cycle_start, int &cycle_end,
                        int cur_vertex){
    
    visited[cur_vertex] = true;
    for(int neighbor: adj[cur_vertex]){
        if(neighbor==parent[cur_vertex])
            continue;

        if(visited[neighbor]){
            cycle_end = cur_vertex;
            cycle_start = neighbor;
            return true;
        }

        parent[neighbor] = cur_vertex;
        if(has_cycle_undirected(adj, visited, parent, cycle_start, cycle_end, neighbor))
            return true;
    }

    return false;
}

std::vector<int> find_cycle_undirected(
        std::vector<std::vector<int>> &adj,
            int n){

    std::vector<bool> visited(n);
    std::vector<int> parent(n, -1);
    int cycle_start = -1, cycle_end = -1;

    for(int i=0; i<n; i++){
        if(!visited[i] && has_cycle_undirected(adj, visited, parent, cycle_start, cycle_end, i))
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

#endif // CYCLE_H_INCLUDED