#include <vector>
#include <queue>

#ifndef BREADTH_FIRST_SEARCH_01_H_INCLUDED
#define BREADTH_FIRST_SEARCH_01_H_INCLUDED


/*
    The path found by breadth first search to any node is the shortest path to that node, i.e the path that
    contains the smallest number of edges in unweighted graphs.

    V-total number of nodes in the graph
    E-total number of edges in the graph

    Time complexity:    O(V+E)
    Space complexity:   O(V)        when first node is connected to all the other unvisited nodes.

    NOTES: Must read "Applications of BFS" in the reference provided below.

    Reference:  https://cp-algorithms.com/graph/01_bfs.html
*/

struct bfs_node{
    bool visited;
    bfs_node* previous;
    int value, distance_from_source;
    std::vector<bfs_node*> neighbors;
};

void bfs(bfs_node* node){
    std::queue<bfs_node*> q;
    node->visited=true;
    node->previous=NULL;
    node->distance_from_source=0;
    q.push(node);
    while(!q.empty()){
        bfs_node* cur_node=q.front();
        q.pop();
        for(auto itr=cur_node->neighbors.begin(); itr!=cur_node->neighbors.end(); ++itr){
            if(!(*itr)->visited){
                (*itr)->visited=true;
                (*itr)->previous=cur_node;
                (*itr)->distance_from_source=cur_node->distance_from_source+1;
                q.push(*itr);
            }
        }
    }

    return;
}

void bfs_traversal(bfs_node* source){
    bfs(source);
}

#endif // BREADTH_FIRST_SEARCH_01_H_INCLUDED