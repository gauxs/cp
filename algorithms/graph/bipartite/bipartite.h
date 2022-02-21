#ifndef BIPARTITE_H_INCLUDED
#define BIPARTITE_H_INCLUDED

#include <vector>
#include <queue>
#include <bits/stdc++.h>

bool is_bipartite(
    std::vector<std::vector<int>> &adj,
        std::vector<bool> &picked,
            std::vector<char> &color,
                int n, int source){

    std::queue<int> q;
    picked[source] = true;
    color[source] = 1;
    q.push(source);
    while(!q.empty()){
        int cur_vertex = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(i!=cur_vertex && color[i]==color[cur_vertex])
                return false;

            if(!picked[i] && adj[cur_vertex][i]!=0){
                picked[i] = true;
                color[i] = color[cur_vertex]==1?2:1;
                q.push(i);
            }
        }
    }

    return true;
}

#endif // BIPARTITE_H_INCLUDED