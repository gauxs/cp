#ifndef DISJOINT_SETS_H_INCLUDED
#define DISJOINT_SETS_H_INCLUDED

template <typename T>
void initialize(vector<T> &parent_ds, vector<T> &size_disjoint_ds, int n){
    for(int i=0; i<n; i++){
        parent_ds[i]=i;
        size_disjoint_ds[i]=1;
    }
    return;
}


#endif // DISJOINT_SETS_H_INCLUDED
