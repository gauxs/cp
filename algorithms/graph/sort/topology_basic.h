#include <stack>
#include <vector>
#include <iostream>
#include <unordered_map>

#include "utils/basic.h"

#ifndef TOPOLOGY_BASIC_H_INCLUDED
#define TOPOLOGY_BASIC_H_INCLUDED

/*
    Time complexity:    O(V+E)
    Space complexity:   O(V)

    NOTES:
    Topological Sorting is mainly used for scheduling jobs from the given dependencies among jobs. In computer science, 
    applications of this type arise in instruction scheduling, ordering of formula cell evaluation when recomputing formula 
    values in spreadsheets, logic synthesis, determining the order of compilation tasks to perform in make files, data serialization,
    and resolving symbol dependencies in linkers.

    Reference:  https://www.geeksforgeeks.org/topological-sorting/
*/

struct TopologyNode{
    int val;
    bool visited;
    std::vector<TopologyNode*> neighbors;
};

class TopologyGraph{
    int num_of_nodes;
    std::unordered_map<int, TopologyNode*> nodes;

    void topological_sort(TopologyNode*, std::stack<TopologyNode*>&);

    public:
        TopologyGraph();
        void add_edge(int, int);
        std::stack<TopologyNode*> sort_topologically();
};

void TopologyGraph::topological_sort(TopologyNode* node, std::stack<TopologyNode*>& output){
    if(!node->visited){
        node->visited = true;
        for(int i=0; i<node->neighbors.size(); i++){
            if(!(node->neighbors[i]->visited)){
                topological_sort(node->neighbors[i], output);
            }
        }

        output.push(node);
    }

    return;
}

TopologyGraph::TopologyGraph(){
    this->num_of_nodes = 0;
}

// value of the node also acts as identifier of the node
void TopologyGraph::add_edge(int u, int v){
    std::unordered_map<int, TopologyNode*>::iterator node_u_itr = nodes.find(u);
    std::unordered_map<int, TopologyNode*>::iterator node_v_itr = nodes.find(v);

    TopologyNode* node_u;
    if(node_u_itr!=nodes.end()){
        node_u = node_u_itr->second;
    }else{
        node_u = new TopologyNode{
            u,
            false,
            std::vector<TopologyNode*>{}
        };
        nodes[u] = node_u;
        num_of_nodes++;
    }

    TopologyNode* node_v;
    if(node_v_itr!=nodes.end()){
        node_v = node_v_itr->second;
    }else{
        node_v = new TopologyNode{
            v,
            false,
            std::vector<TopologyNode*>{}
        };
        nodes[v] = node_v;
        num_of_nodes++;
    }

    node_u->neighbors.push_back(node_v);
}

std::stack<TopologyNode*> TopologyGraph::sort_topologically(){
    std::stack<TopologyNode*> sorted;

    for(auto itr=nodes.begin(); itr!=nodes.end(); ++itr){
        if(!(itr->second->visited)){
            topological_sort(itr->second, sorted);
        }
    }

    return sorted;
}

void topological_basic(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    TopologyGraph graph;
    graph.add_edge(5, 2);
    graph.add_edge(5, 0);
    graph.add_edge(4, 0);
    graph.add_edge(4, 1);
    graph.add_edge(2, 3);
    graph.add_edge(3, 1);
    std::stack<TopologyNode*> out = graph.sort_topologically();

    while(!out.empty()){
        std::cout<<out.top()->val<<" ";
        out.pop();
    }
}
#endif // TOPOLOGY_BASIC_H_INCLUDED