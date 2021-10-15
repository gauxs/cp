#ifndef FLOYD_WARSHALL_H_INCLUDED
#define FLOYD_WARSHALL_H_INCLUDED

#include <vector>
#include <limits.h>

#define INF INT_MAX

void floyd_warshal(std::vector<std::vector<int>> &distances, std::vector<std::vector<int>> &ancestors, int n){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // if there are negative weight edges in the graph, special measures have to be taken, 
                // Otherwise the resulting values in matrix may be of the form INF−1, INF−2.
                if(distances[i][k]<INF && distances[k][j]<INF){
                    distances[i][j] = std::min(distances[i][j], (distances[i][k] + distances[k][j]));
                    ancestors[i][j] = k;
                }
            }
        }
    }

    return;
}

// TODO: fix this logic
void print_path(std::vector<std::vector<int>> &ancestors, int u, int v, std::vector<int> &path){
    if(u == v)
        path.push_back(u);

    int t = ancestors[u][v];
    path.push_back(t);
    print_path(ancestors, u, t, path);
    print_path(ancestors, t, v, path);
}

#endif // FLOYD_WARSHALL_H_INCLUDED