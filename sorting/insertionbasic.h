#ifndef INSERTIONBASIC_H_INCLUDED
#define INSERTIONBASIC_H_INCLUDED

using namespace std;

void insertion_basic_sort(vector<int> &arr, int n, int ele){
    int i=n-1;
    while(i>=0 && arr[i]>ele){
        i--;
    }
    i++;
    for(int j=n-1; j>=i; j--){
        arr[j+1] = arr[j];
    }
    arr[i]=ele;
    return;
}

#endif // INSERTIONBASIC_H_INCLUDED
