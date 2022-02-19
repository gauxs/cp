#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED

#include <vector>
#include <stack>
#include <bits/stdc++.h>

void dfs(
    std::vector<std::vector<int>>& adj,
        std::vector<int>& time_in,
            std::vector<int>& time_out,
                std::vector<int>& color,
                    int n, int timer, int source){

    color[source] = 1;
    time_in[source] = timer++;
    for(int i=0; i<n; i++){
        if(adj[source][i]!=0 && color[i]==0){
            dfs(adj, time_in, time_out, color, n, timer, i);
        }
    }

    color[source] = 2;
    time_out[source] = timer++;

    return;
}

#endif // DFS_H_INCLUDED