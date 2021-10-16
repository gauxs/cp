#ifndef BFS_01_H_INCLUDED
#define BFS_01_H_INCLUDED

#include <deque>
#include <vector>
#include <limits.h>

#define INF INT_MAX

void bfs_01(
    std::vector<std::vector<std::pair<int, int>>> &adj,
        std::vector<int> &distances,
            std::vector<int> &predecessor,
                int n, int source_vertex){

    for(int i=0; i<n; i++){
        distances[i] = INF;
        predecessor[i] = -1;
    }

    std::deque<int> q;
    distances[source_vertex] = 0;
    q.push_front(source_vertex);
    for(int i=0; i<n; i++){
        int min_vertex = q.front();
        q.pop_front();

        int edges = adj[min_vertex].size();
        for(int j=0; j<edges; j++){
            int to_vertex = adj[min_vertex][j].first;
            int weight = adj[min_vertex][j].second;
            if(distances[to_vertex]>(distances[min_vertex] + weight)){
                distances[to_vertex] = distances[min_vertex] + weight;
                predecessor[to_vertex] = min_vertex;
                if(weight==1)
                    q.push_back(to_vertex);
                else
                    q.push_front(to_vertex);
            }
        }
    }

    return;
}

#endif // BFS_01_H_INCLUDED