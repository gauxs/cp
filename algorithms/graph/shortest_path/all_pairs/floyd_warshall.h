#ifndef FLOYD_WARSHALL_H_INCLUDED
#define FLOYD_WARSHALL_H_INCLUDED

#include <vector>
#include <limits.h>

#define INF INT_MAX

void floyd_warshal(
    std::vector<std::vector<int>> &distances, 
        std::vector<std::vector<int>> &ancestors, 
            int n){
                
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(distances[i][k]<INF && distances[k][j]<INF){ // stops from performing transitions using paths that don't exist
                    distances[i][j] = std::min(distances[i][j], (distances[i][k] + distances[k][j]));
                    ancestors[i][j] = k;
                }
            }
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(distances[i][k]<INF && distances[k][k]<0 && distances[k][j]<INF){    // distances[k][k]<0 if there exists a negative length path from k to k
                    distances[i][j] = -INF;                                             // -INF denotes that no shortest path exists between (i, j)
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