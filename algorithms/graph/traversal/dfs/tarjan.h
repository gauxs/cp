#ifndef TARJAN_H_INCLUDED
#define TARJAN_H_INCLUDED

#include <utility>
#include <vector>

/*
    Tarjan bridge-finding on an undirected graph.
    adj[u] lists neighbors of u. Edge (u, v) is a bridge when low[v] > disc[u].
*/
void tarjan_bridges_dfs(
    int u,
    int parent,
    const std::vector<std::vector<int>>& adj,
    std::vector<int>& disc,
    std::vector<int>& low,
    int& timer,
    std::vector<std::pair<int, int>>& bridges) {

    disc[u] = low[u] = timer++;

    for (int v : adj[u]) {
        if (v == parent) {
            continue;
        }
        if (disc[v] == -1) {
            tarjan_bridges_dfs(v, u, adj, disc, low, timer, bridges);
            low[u] = std::min(low[u], low[v]);
            if (low[v] > disc[u]) {
                bridges.emplace_back(u, v);
            }
        } else {
            // we have encountered an already visited node v, we have found a back edge directly connecting u to v.
            // we will check disc[v] and not low[v] because we want to record the discovery time of the node this back edge reaches,
            // not the lowest node reachable from that node.
            low[u] = std::min(low[u], disc[v]);
        }
    }
}

std::vector<std::pair<int, int>> tarjan_bridges(
    int n,
    const std::vector<std::vector<int>>& adj) {

    std::vector<int> disc(n, -1);
    std::vector<int> low(n, -1);
    int timer = 0;
    std::vector<std::pair<int, int>> bridges;

    for (int u = 0; u < n; ++u) {
        if (disc[u] == -1) {
            tarjan_bridges_dfs(u, -1, adj, disc, low, timer, bridges);
        }
    }

    return bridges;
}

#endif // TARJAN_H_INCLUDED
