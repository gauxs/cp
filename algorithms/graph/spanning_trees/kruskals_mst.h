#ifndef KRUSKALS_MST_H_INCLUDED
#define KRUSKALS_MST_H_INCLUDED

/*
    Time complexity: O(E*log(V))
    Note: It takes log(V) find_parent operations to start finding parent in O(1)
*/

/*
#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
*/

struct edge {
    int a, w, b;
};

template <typename T>
T find_parent(vector<T> &parent, T x){
    while(parent[x]!=x){
        parent[x]=parent[parent[x]];
        x=parent[x];
    }
    return x;
}

template <typename T>
bool has_same_parent(T x, T y){
    if(find_parent(x)==find_parent(y)){
        return true;
    }else{
        return false;
    }
}

template <typename T>
void weighted_union_path_compression(vector<T> &parent, vector<T> &weight, T a, T b){
    T parent_a = find_parent(parent, a);
    T parent_b = find_parent(parent, b);

    if(weight[parent_a]<=weight[parent_b]){
        parent[parent_a]=parent_b;
        weight[parent_b]+=weight[parent_a];
    }else{
        parent[parent_b]=parent_a;
        weight[parent_a]+=weight[parent_b];
    }
    return;
}

template <typename T>
void initialize(vector<T> &parent, vector<T> &weight, T n){
    for(T i=0; i<n; i++){
        parent[i]=i;
        weight[i]=1;
    }
    return;
}

bool cust_comp(struct edge e1, struct edge e2){
    return e1.w<e2.w;
}

/*
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
//    cin>>t;

    int n, m, x, y, w;
    struct edge vertex;
    for(int i=0; i<t; i++){
        cin>>n>>m;
        vector<struct edge> graph(m+1);
        vector<int> parent(n+1);
        vector<int> weight(n+1);
        initialize(parent, weight, n+1);

        for(int j=0; j<m; j++){
            cin>>x>>y>>w;
            graph[j].a=x;
            graph[j].b=y;
            graph[j].w=w;
        }

        sort(graph.begin(), graph.end(), cust_comp);

        int totalCost=0;
        for(int j=0; j<m; j++){
            if(find_parent(parent, graph[j].a)!=find_parent(parent, graph[j].b)){
                totalCost+=graph[j].w;
                weighted_union_path_compression(parent, weight, graph[j].a, graph[j].b);
            }
        }
        cout<<totalCost<<endl;
    }

    return 0;
}
*/

#endif // KRUSKALS_MST_H_INCLUDED
