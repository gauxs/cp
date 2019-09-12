#ifndef BELLMAN_STRUCT_H_INCLUDED
#define BELLMAN_STRUCT_H_INCLUDED

#pragma GCC optimize("Ofast")
#include <iostream>
#include <bits/stdc++.h>
#define GraphNode T
using namespace std;

struct Edge{
    int src_node;
    int weight;
    int dest_node;
    struct Edge* next_edge;
};

struct GraphNode{
    bool visited;
    int weight;
    int cur_node;
    struct Edge* edges_list_head;
};

// graph_nodes_list - This is "0" based.
struct Graph{
    int num_of_nodes;
    struct GraphNode* graph_nodes_list;
};

struct Edge* create_edge(int src, int weight, int dst){
    struct Edge* new_edge=(struct Edge*)malloc(sizeof(struct Edge));
    new_edge->src_node=src;
    new_edge->dest_node=dst;
    new_edge->weight=weight;
    new_edge->next_edge=NULL;
    return new_edge;
}

struct Graph* create_graph(int num_of_nodes){
    struct Graph* newGraph=(struct Graph*)malloc(sizeof(struct Graph));
    newGraph->num_of_nodes=num_of_nodes;
    newGraph->graph_nodes_list=(struct GraphNode*)malloc(num_of_nodes*sizeof(struct GraphNode));
    for(int i=0; i<num_of_nodes; i++){
        newGraph->graph_nodes_list[i].visited=false;
        newGraph->graph_nodes_list[i].weight=INT_MAX;
        newGraph->graph_nodes_list[i].edges_list_head=NULL;
    }
    return newGraph;
}

// src/dst - These are "0" based. If question is "1" based send "src-1".
struct Edge* add_graph_edge(struct Graph* graph, int src, int dst, int weight){
    struct GraphNode* src_node=&(graph->graph_nodes_list[src]);
    src_node->cur_node=src;
    struct Edge* edge=create_edge(src, weight, dst);
    edge->next_edge=src_node->edges_list_head;
    src_node->edges_list_head=edge;
    return edge;
}

//int main(){
//    std::ios::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    int n, m, a, b, w;
//    cin>>n>>m;
//
//    struct Graph* graph=create_graph(n);
//
//    for(int i=1; i<=m; i++){
//        cin>>a>>b>>w;
//        add_graph_edge(graph, a-1, b-1, w);
//    }
//
//    graph->graph_nodes_list[0].weight=0;
//
//    for(int j=1; j<n; j++){
//        for(int i=0; i<n; i++){
//            struct GraphNode* cur_node=&(graph->graph_nodes_list[i]);
//            for(struct Edge* ne=cur_node->edges_list_head; ne!=NULL; ne=ne->next_edge){
//                if((graph->graph_nodes_list[ne->src_node].weight+ne->weight)<(graph->graph_nodes_list[ne->dest_node].weight)){
//                    graph->graph_nodes_list[ne->dest_node].weight=(graph->graph_nodes_list[ne->src_node].weight+ne->weight);
//                }
//            }
//        }
//    }
//
//    for(int i=1; i<n; i++){
//        cout<<graph->graph_nodes_list[i].weight<<" ";
//    }
//
//    return 0;
//}

#endif // BELLMAN_STRUCT_H_INCLUDED
