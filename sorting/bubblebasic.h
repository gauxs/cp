#ifndef BUBBLEBASIC_H_INCLUDED
#define BUBBLEBASIC_H_INCLUDED

using namespace std;

void swapV(int& a, int& b){
    int temp=a;
    a=b;
    b=temp;
}

void bubble_basic_sort(vector<int> &arr, int n){
    for(int i=n; i>=0; i--){
        for(int j=0; j<i-1; j++){
            if(arr[j+1]<arr[j]){
                swapV(arr[j], arr[j+1]);
            }
        }
    }
    return;
}
#endif // BUBBLEBASIC_H_INCLUDED
