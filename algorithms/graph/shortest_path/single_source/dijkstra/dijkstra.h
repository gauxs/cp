#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

#include <set>
#include <vector>
#include <limits.h>
#include <algorithm>

#define INF INT_MAX

void dijkstra(
    std::vector<std::vector<std::pair<int, int>>> &adj,
        std::vector<int> &distances, std::vector<int> &predecessor, 
            std::vector<bool> &picked,
                int n, int source_vertex){

    for(int i=0; i<n; i++){         
        distances[i] = INF;
        predecessor[i] = -1;
    }

    distances[source_vertex] = 0;
    for(int i=0; i<n; i++){         
        int min_vertex = -1;
        for(int j=0; j<n; j++){     // finding the vertex with smallest distance from source_vertex
            if(!picked[j] &&
                (min_vertex==-1 || distances[j]<distances[min_vertex]))
            min_vertex = i;
        }

        if(distances[min_vertex]==INF)
            break;

        picked[min_vertex] = true;
        int edges = adj[min_vertex].size();
        for(int j=0; j<edges; j++){ 
            int to_vertex = adj[min_vertex][j].first;
            int weight = adj[min_vertex][j].second;
            if(distances[to_vertex]>(distances[min_vertex] + weight)){
                distances[to_vertex] = distances[min_vertex] + weight;
                predecessor[to_vertex] = min_vertex;
            }
        }
    }

    return;
}

void dijkstra_set(
    std::vector<std::vector<std::pair<int, int>>> &adj,
        std::vector<int> &distances,
            std::vector<int> &predecessor,
                int n, int source_vertex){

    for(int i=0; i<n; i++){
        distances[i] = INF;
        predecessor[i] = -1;
    }

    std::set<std::pair<int, int>> s;
    distances[source_vertex] = 0;
    s.insert({0, source_vertex});
    for(int i=0; i<n; i++){     
        int min_vertex = s.begin()->second;     // red-black tree - O(logN)
        s.erase(s.begin());                     // red-black tree - O(logN)

        int edges = adj[min_vertex].size();
        for(int j=0; j<edges; j++){ 
            int to_vertex = adj[min_vertex][j].first;
            int weight = adj[min_vertex][j].second;
            if(distances[to_vertex]>(distances[min_vertex] + weight)){
                s.erase({distances[to_vertex], to_vertex});
                distances[to_vertex] = distances[min_vertex] + weight;
                predecessor[to_vertex] = min_vertex;
                s.insert(distances[to_vertex], to_vertex);      // red-black tree - O(logN)
            }
        }
    }

    return;
}

std::vector<int> print_path(std::vector<int> &predecessor, int n, int source, int vertex){
    std::vector<int> path;
    
    while(vertex!=source){
        path.push_back(vertex);
        vertex = predecessor[vertex];
    }
    path.push_back(source);

    reverse(path.begin(), path.end());
    return path;
}

#endif // DIJKSTRA_H_INCLUDED