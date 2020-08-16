#include <iostream>
#include <vector>
#include <stack>

#ifndef DRGNDEN_H_INCLUDED
#define DRGNDEN_H_INCLUDED
#define LI long int

using namespace std;

struct node {
    LI index;
    LI size_of_node;
    LI parent_index;
    LI heavy_child_index;
    LI tastiness_till_now;
    vector<LI> child;
};

void fill_reachability(vector<LI> &heights, LI n, vector<struct node> &tree_travel_to_right, vector<struct node> &tree_travel_to_left){
    stack<LI> leftover_nodes;
    stack<LI> temp_nodes;

    for(LI i=n; i>=0; i--){
        temp_nodes.push(i);
        while(!leftover_nodes.empty()){
            LI node_index = leftover_nodes.top();
            leftover_nodes.pop();
            if(heights[node_index]<heights[i]){
                tree_travel_to_right[node_index].index = node_index;
                tree_travel_to_right[node_index].parent_index = i;

                tree_travel_to_right[i].size_of_node += tree_travel_to_right[node_index].size_of_node;
                tree_travel_to_right[i].child.push_back(node_index);
            }else{
                temp_nodes.push(node_index);
            }
        }

        while(!temp_nodes.empty()){
            LI temp_index = temp_nodes.top();
            temp_nodes.pop();
            leftover_nodes.push(temp_index);
        }
    }

    leftover_nodes = stack<LI>();
    temp_nodes = stack<LI>();
    for(LI i=1; i<=n+1; i++){
        temp_nodes.push(i);
        while(!leftover_nodes.empty()){
            LI node_index = leftover_nodes.top();
            leftover_nodes.pop();
            if(heights[node_index]<heights[i]){
                tree_travel_to_left[node_index].index = node_index;
                tree_travel_to_left[node_index].parent_index = i;

                tree_travel_to_left[i].size_of_node += tree_travel_to_left[node_index].size_of_node;
                tree_travel_to_left[i].child.push_back(node_index);
            }else{
                temp_nodes.push(node_index);
            }
        }

        while(!temp_nodes.empty()){
            LI temp_index = temp_nodes.top();
            temp_nodes.pop();
            leftover_nodes.push(temp_index);
        }
    }

    return;
}

void find_heavy_child(vector<struct node> &tree, LI cur_node_index){
    LI no_of_child = tree[cur_node_index].child.size();

    tree[cur_node_index].heavy_child_index = -1;
    for(LI i=0; i<no_of_child; i++){
        find_heavy_child(tree, tree[cur_node_index].child[i]);
        if(tree[cur_node_index].size_of_node <= (2*tree[tree[cur_node_index].child[i]].size_of_node)){
            tree[cur_node_index].heavy_child_index = i;
        }
    }

    return;
}

void decompose(LI cur_node_index, vector<struct node> &tree, vector<LI> &head){

}

LI reachability_cost(LI b, LI c, vector<struct node> &tree_left_to_right, vector<struct node> &tree_right_to_left){
    LI cost=-1;

    if(b == c){
        cost=0;
        cost += (tree_left_to_right[c].tastiness_till_now - tree_left_to_right[tree_left_to_right[b].parent_index].tastiness_till_now);
    } else if(b < c){
        LI temp_c = c;
        while(b<temp_c){
            temp_c = tree_left_to_right[temp_c].parent_index;
        }
        if(b == temp_c){
           cost=0;
            cost += (tree_left_to_right[c].tastiness_till_now - tree_left_to_right[tree_left_to_right[b].parent_index].tastiness_till_now);
        }else{
            cost = -1;
        }
    }else {
        LI temp_c = c;
        while(b>temp_c){
            temp_c = tree_right_to_left[temp_c].parent_index;
        }
        if(b == temp_c){
            cost=0;
            cost += (tree_right_to_left[c].tastiness_till_now - tree_right_to_left[tree_right_to_left[b].parent_index].tastiness_till_now);
        }else{
            cost = -1;
        }
    }

    return cost;
}

void print_tree(vector<struct node> &tree, LI cur_node_index){
    cout<<"Current Node: "<<tree[cur_node_index].index<<endl;
    cout<<"Parent Index: "<<tree[cur_node_index].parent_index<<endl;
    cout<<"Tastiness till now: "<<tree[cur_node_index].tastiness_till_now<<endl;
    LI no_of_child = tree[cur_node_index].child.size();
    cout<<"Children: ";
    for(LI i=0; i<no_of_child; i++){
        cout<<tree[cur_node_index].child[i]<<" ";
    }
    cout<<endl;
    for(LI i=0; i<no_of_child; i++){
        print_tree(tree, tree[cur_node_index].child[i]);
    }

    return;
}

void update_tastiness(vector<struct node> &tree, LI cur_node_index, LI diff){
    tree[cur_node_index].tastiness_till_now += diff;
    LI no_of_child = tree[cur_node_index].child.size();
    for(LI i=0; i<no_of_child; i++){
        update_tastiness(tree, tree[cur_node_index].child[i], diff);
    }

    return;
}

void initialize(LI n, vector<LI> &heights, vector<LI> &tastiness, vector<struct node> &tree_travel_to_right, vector<struct node> &tree_travel_to_left){
    heights[0] = 10000000000;
    tastiness[0] = 0;

    heights[n+1] = 10000000000;
    tastiness[n+1] = 0;

    tree_travel_to_right[0].index = 0;
    tree_travel_to_right[0].parent_index = -1;
    tree_travel_to_right[0].tastiness_till_now = 0;
    tree_travel_to_right[n+1].index = n+1;
    tree_travel_to_right[n+1].parent_index = -1;
    tree_travel_to_right[n+1].tastiness_till_now = 0;

    tree_travel_to_left[0].index = 0;
    tree_travel_to_left[0].parent_index = -1;
    tree_travel_to_left[0].tastiness_till_now = 0;
    tree_travel_to_left[n+1].index = n+1;
    tree_travel_to_left[n+1].parent_index = -1;
    tree_travel_to_left[n+1].tastiness_till_now = 0;

    for (LI i=0; i<n+2; i++){
        tree_travel_to_right[i].size_of_node =1;
        tree_travel_to_left[i].size_of_node =1;
    }

    return;
}

int drgden(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    LI n, q;
    cin>>n>>q;

    vector<LI> heights(n+2);
    vector<LI> tastiness(n+2);
    vector<LI> head(n+2, -1);
    vector<struct node> tree_travel_to_right(n+2);
    vector<struct node> tree_travel_to_left(n+2);

    for(LI i=1; i<=n; i++){
        cin>>heights[i];
    }

    for(LI i=1; i<=n; i++){
        cin>>tastiness[i];
    }

    initialize(n, heights, tastiness, tree_travel_to_left, tree_travel_to_right);
    fill_reachability(heights, n, tree_travel_to_right, tree_travel_to_left);
    find_heavy_child(tree_travel_to_right, 0);
    find_heavy_child(tree_travel_to_left, n+1);

    /*cout<<"L to R tree: "<<endl;
    print_tree(tree_travel_to_right, 0);
    cout<<"R to L tree: "<<endl;
    print_tree(tree_travel_to_left, n+1);*/

    int query_type;
    LI b;
    while(q--){
        cin>>query_type;
        switch(query_type){
            case 1:
                LI k;
                cin>>b>>k;
                update_tastiness(tree_travel_to_right, b, k-tastiness[b]);
                update_tastiness(tree_travel_to_left, b, k-tastiness[b]);
                tastiness[b] = k;
                break;
            case 2:
                LI c;
                cin>>b>>c;
                cout<<reachability_cost(b, c, tree_travel_to_right, tree_travel_to_left)<<endl;
                cout<<reachability_cost(b, c, tree_travel_to_right, tree_travel_to_left)<<endl;
                break;
        }
    }

    return 0;
}

#endif // DRGNDEN_H_INCLUDED
