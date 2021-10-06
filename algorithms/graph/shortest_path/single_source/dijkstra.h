#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

#include <vector>
#include <limits.h>
#include <bits/stdc++.h>

#define INF INT_MAX

/*
    You are given a directed or undirected weighted graph with n vertices and m edges. The weights of all edges
    are non-negative. You are also given a starting vertex s. Find the lengths of the shortest paths from a starting
    vertex 's' to all other vertices, and output the shortest paths themselves.

    This problem is also called single-source shortest paths problem.

    NOTE: The weights of all edges are assumed non-negative.

    Reference: https://cp-algorithms.com/graph/dijkstra.html
*/

/*
    1 - adj[i].first = other vertex
        adj[i].second = edge weight

    Time complexity:    O(N^2 + M)  // for dense graph M ≈ N^2
    Space complexity:   O(N)
*/
void dijkstra(std::vector<std::vector<std::pair<int, int>>> &adj,
                std::vector<int> &distances, std::vector<int> &predecessor, std::vector<bool> &picked,
                    int n, int source_vertex){
    // O(n)
    for(int i=0; i<n; i++){
        distances[i] = INF;
        predecessor[i] = -1;
    }

    distances[source_vertex] = 0;
    // O(n)
    for(int i=0; i<n; i++){
        int min_vertex = -1;
        // find the vertex with smallest distance from source_vertex - O(n)
        for(int j=0; j<n; j++){
            if(!picked[j] &&
                (min_vertex==-1 || distances[j]<distances[min_vertex]))
            min_vertex = i;
        }

        if(distances[min_vertex]==INF)
            break;

        picked[min_vertex] = true;
        int edges = adj[min_vertex].size();
        // O(m)
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


/*
    It is clear, that the complexity of dijkstra() is optimal for a dense graph, i.e. when M ≈ N^2. However in sparse graphs, when M 
    is much smaller than the maximal number of edges N^2, the complexity gets less optimal because of the first term.
    Thus it is necessary to improve the execution time of "finding minimum distance vertex".

    To accomplish that we can use a variation of multiple auxiliary data structures like set, priority queue, fibonacci heaps.

    1 - Since we need to store vertices ordered by their values d[], it is convenient to store actual pairs: 
        the distance and the index of the vertex. As a result in a set pairs are automatically sorted by their distances.

    2 - We don't need the vector<bool> picked. We will use the set to store that information, and also find the vertex with 
        the shortest distance with it.

    NOTE: The weights of all edges are assumed non-negative.

    Time complexity:    O(Nlog(N) + Mlog(N)) = O(Mlog(N))  // for dense graph M ≈ N^2
    Space complexity:   O(N)
*/
void dijkstra_set(std::vector<std::vector<std::pair<int, int>>> &adj,
                std::vector<int> &distances, std::vector<int> &predecessor, int n,
                int source_vertex){
    std::set<std::pair<int, int>> s;

    // O(n)
    for(int i=0; i<n; i++){
        distances[i] = INF;
        predecessor[i] = -1;
    }

    distances[source_vertex] = 0;
    s.insert({0, source_vertex});
    // O(n)
    for(int i=0; i<n; i++){
        int min_vertex = s.begin()->second;
        s.erase(s.begin());

        int edges = adj[min_vertex].size();
        // O(m)
        for(int j=0; j<edges; j++){
            int to_vertex = adj[min_vertex][j].first;
            int weight = adj[min_vertex][j].second;
            if(distances[to_vertex]>(distances[min_vertex] + weight)){
                s.erase({distances[to_vertex], to_vertex});
                distances[to_vertex] = distances[min_vertex] + weight;
                predecessor[to_vertex] = min_vertex;
                s.insert(distances[to_vertex], to_vertex);
            }
        }
    }

    return;
}

#endif // DIJKSTRA_H_INCLUDED