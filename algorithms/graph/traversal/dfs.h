#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED

#include <vector>
#include <stack>
#include <bits/stdc++.h>


/*
    Depth First Search finds the lexicographical first path in the graph from a source vertex u to each vertex. 
    Depth First Search will also find the shortest paths in a tree (because there only exists one simple path), 
    but on general graphs this is not the case.

    V-total number of nodes in the graph
    E-total number of edges in the graph

    Time complexity:    O(V+E)
    Space complexity:   O(V)        when first node is connected to all the other unvisited nodes.

    NOTES: Must read "Applications of DFS" in the reference provided below.

    Reference:  https://cp-algorithms.com/graph/depth-first-search.html
*/

void dfs(std::vector<std::vector<int>> &adj, int n, std::vector<int> &time_in,
            std::vector<int> &time_out, std::vector<int> &color, int timer, int source){

    color[source] = 1;
    time_in[source] = timer++;

    for(int i=0; i<n; i++){
        if(adj[source][i]!=0 && color[i]==0){
            dfs(adj, n, time_in, time_out, color, timer, i);
        }
    }

    color[source] = 2;
    time_out[source] = timer++;

    return;
}

#endif // DFS_H_INCLUDED