#ifndef FLOYD_WARSHALL_H_INCLUDED
#define FLOYD_WARSHALL_H_INCLUDED

#include <vector>
#include <limits.h>

#define INF INT_MAX

/*
    It is assumed that if there is no edge between any two vertices i and j, ditances[i][j] contains a large number
    (large enough so that it is greater than the length of any path in this graph).
*/
void floyd_warshal(
    std::vector<std::vector<int>> &distances, 
        std::vector<std::vector<int>> &ancestors, 
            int n){
                
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // stops from performing transitions using paths that don't exist
                if(distances[i][k]<INF && distances[k][j]<INF){ 
                    distances[i][j] = std::min(distances[i][j], (distances[i][k] + distances[k][j]));
                    ancestors[i][j] = k;
                }
            }
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // if distances[k][k]<0 i.e.is part of a cycle of negative weight, k
                // can be reached from i and j can be reached from . Then the path from
                // i to j can have arbitrarily small weight. We will denote this with -INF.
                if(distances[i][k]<INF && distances[k][k]<0 && distances[k][j]<INF){    
                    distances[i][j] = -INF;                                             
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