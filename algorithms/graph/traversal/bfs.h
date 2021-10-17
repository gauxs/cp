#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED

#include <vector>
#include <queue>
#include <bits/stdc++.h>


/*
    The path found by breadth first search to any node is the shortest path to that node, i.e the path that
    contains the smallest number of edges in unweighted graphs.

    V-total number of nodes in the graph
    E-total number of edges in the graph

    Time complexity:    O(V+E)
    Space complexity:   O(V)        when first node is connected to all the other unvisited nodes.

    NOTES: Must read "Applications of BFS" in the reference provided below.

    Reference:  https://cp-algorithms.com/graph/breadth-first-search.html

    Quetions:
    https://leetcode.com/problems/evaluate-division/
    - Unique:
      - https://leetcode.com/problems/jump-game-iv/
*/

void bfs(std::vector<std::vector<int>> &adj, int n, std::vector<int> &parents,
            std::vector<int> &distance, std::vector<bool> &picked, int source){

    std::queue<int> q;
    picked[source] = true;
    parents[source] = -1;
    q.push(source);
    while(!q.empty()){
        int curVertex = q.front();
        q.pop();
        for(int i=0; i<n; i++){
            if(!picked[i] && adj[curVertex][i]!=0){
                picked[i] = true;
                parents[i] = curVertex;
                distance[i] = distance[curVertex] + 1;
                q.push(i);
            }
        }
    }

    return;
}

std::vector<int> get_path(std::vector<int> &parents, std::vector<bool> &picked, int v){
    std::vector<int> path;
    if(picked[v]){
        while(v!=-1){
            path.push_back(v);
            v = parents[v];
        }
    }

    reverse(path.begin(), path.end());
    return path;
}

#endif // BFS_H_INCLUDED