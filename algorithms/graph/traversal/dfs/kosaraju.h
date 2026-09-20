#ifndef KOSARAJU_H_INCLUDED
#define KOSARAJU_H_INCLUDED

#include <stack>
#include <vector>

/*
    Kosaraju — SCCs in a directed graph.

    Intuition: reversing edges keeps paths inside each SCC but severs paths between
    SCCs. Collapse each SCC to one node and the meta-graph is a DAG. Pass 1 orders
    vertices so stack-top lies in a source SCC of that DAG; reversing G flips upstream
    and downstream; pass 2 on G^T in that order traps one SCC per DFS.
*/

// Pass 1 on G: push u after its subtree — upstream SCC vertices finish later, so
// stack top is in a source component of the SCC condensation DAG.
void kosaraju_dfs1(
    int u,
    const std::vector<std::vector<int>>& adj,
    std::vector<char>& visited,
    std::stack<int>& finish_order) {

    visited[u] = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            kosaraju_dfs1(v, adj, visited, finish_order);
        }
    }
    finish_order.push(u);
}

// Pass 2 on G^T: from one seed, only vertices in the same SCC are reachable
// (that component is a sink in G^T, so DFS cannot escape to other components).
void kosaraju_dfs2(
    int u,
    const std::vector<std::vector<int>>& reversed,
    std::vector<char>& visited,
    std::vector<int>& component) {

    visited[u] = 1;
    component.push_back(u);
    for (int v : reversed[u]) {
        if (!visited[v]) {
            kosaraju_dfs2(v, reversed, visited, component);
        }
    }
}

std::vector<std::vector<int>> kosaraju_scc(std::vector<std::vector<int>> adj) {
    const int n = static_cast<int>(adj.size());

    // G^T: reverse every edge — sources of the condensation DAG become sinks.
    std::vector<std::vector<int>> reversed(n);
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            reversed[v].push_back(u);
        }
    }

    std::stack<int> finish_order;
    std::vector<char> visited(n, 0);
    for (int u = 0; u < n; ++u) {
        if (!visited[u]) {
            kosaraju_dfs1(u, adj, visited, finish_order);
        }
    }

    std::vector<std::vector<int>> components;
    std::fill(visited.begin(), visited.end(), 0);
    // Pop in reverse finish order; each unvisited pop starts one full SCC.
    while (!finish_order.empty()) {
        int u = finish_order.top();
        finish_order.pop();
        if (visited[u]) {
            continue;
        }
        std::vector<int> component;
        kosaraju_dfs2(u, reversed, visited, component);
        components.push_back(std::move(component));
    }

    return components;
}

#endif // KOSARAJU_H_INCLUDED
