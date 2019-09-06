#ifndef PRIMS_MST_H_INCLUDED
#define PRIMS_MST_H_INCLUDED

/*#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct node {
    bool visited;
    vector<pair<int, int> > neighbors;
};

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
//    cin>>t;

    int n, m, x, y, w;
    for(int i=0; i<t; i++){
        cin>>n>>m;
        int totalCost=0;
        pair<int, int> p;
        struct node chosen_node;
        vector<struct node> graph(n+1);
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap;

        for(int j=0; j<m; j++){
            cin>>x>>y>>w;
            p = make_pair(w, y);
            graph[x].neighbors.push_back(p);
            p = make_pair(w, x);
            graph[y].neighbors.push_back(p);
        }

        heap.push(make_pair(0, 1));
        while(!heap.empty()){
            p=heap.top();
            heap.pop();
            if(graph[p.second].visited)
                continue;
            totalCost+=p.first;
            graph[p.second].visited=true;
            chosen_node=graph[p.second];
            for(int j=0; j<graph[p.second].neighbors.size(); j++){
                if(!graph[graph[p.second].neighbors[j].second].visited){
                    heap.push(graph[p.second].neighbors[j]);
                }
            }
        }
        cout<<totalCost<<endl;
    }

    return 0;
}
*/

#endif // PRIMS_MST_H_INCLUDED
