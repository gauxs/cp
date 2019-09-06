#ifndef DISJOINT_SETS_H_INCLUDED
#define DISJOINT_SETS_H_INCLUDED

template <typename T>
void initialize(vector<T> &parent, vector<T> &weight, T n){
    for(T i=0; i<n; i++){
        parent[i]=i;
        weight[i]=1;
    }
    return;
}

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

#endif // DISJOINT_SETS_H_INCLUDED
