#ifndef SELECTIONBASIC_H_INCLUDED
#define SELECTIONBASIC_H_INCLUDED

using namespace std;

void swapV(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}

void selection_basic_sort(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        int min_index=-1;
        int min_v=INT_MAX;
        for(int j=i; j<n; j++){
            if(arr[j]<min_v){
                min_v=arr[j];
                min_index=j;
            }
        }
        swapV(arr[i], arr[min_index]);
    }
    return;
}

#endif // SELECTIONBASIC_H_INCLUDED
