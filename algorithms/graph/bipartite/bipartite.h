#ifndef BIPARTITE_H_INCLUDED
#define BIPARTITE_H_INCLUDED

#include <vector>
#include <queue>
#include <bits/stdc++.h>

bool is_bipartite(std::vector<std::vector<int>> &adj, int n)
{
    std::vector<char> color(n, 0); // 0 = uncolored, 1/2 = colors

    for (int start = 0; start < n; start++)
    {
        if (color[start] != 0)
            continue;

        std::queue<int> q;
        q.push(start);
        color[start] = 1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                if (color[v] == 0)
                {
                    color[v] = (color[u] == 1 ? 2 : 1);
                    q.push(v);
                }
                else if (color[v] == color[u])
                {
                    return false;
                }
            }
        }
    }

    return true;
}

#endif // BIPARTITE_H_INCLUDED