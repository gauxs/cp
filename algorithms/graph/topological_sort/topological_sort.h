#ifndef TOPOLOGY_SORT_H_INCLUDED
#define TOPOLOGY_SORT_H_INCLUDED

#include <vector>
#include <algorithm>

void dfs(
    std::vector<std::vector<int>> &adj,
        std::vector<bool> visited,
            std::vector<int> &topological_order,
                int cur_vertex){

    visited[cur_vertex] = true;
    for(int neighbor: adj[cur_vertex]){
        if(!visited[neighbor])
            dfs(adj, visited, topological_order, neighbor);
    }

    topological_order.push_back(cur_vertex);
    return;
}

void topological_sort(
    std::vector<std::vector<int>> &adj,
        std::vector<int> &topological_order,
        int n){

    std::vector<bool> visited(n);
    for(int i=0; i<n; i++){
        if(!visited[i])
            dfs(adj, visited, topological_order, i);
    }

    reverse(topological_order.begin(), topological_order.end());
    return;
}

#endif // TOPOLOGY_SORT_H_INCLUDED