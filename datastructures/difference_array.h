#ifndef DIFFERENCE_ARRAY_H_INCLUDED
#define DIFFERENCE_ARRAY_H_INCLUDED

vector<int> initializeDiffArray(vector<int> &inp, int n){
    vector<int> diffArray(n+1);
    diffArray[0]=inp[0];
    diffArray[n]=0;
    for(int i=1; i<n; i++){
        diffArray[i]=inp[i]-inp[i-1];
    }
    return diffArray;
}

void update(vector<int> &diffArr, int l, int r, int x){
    diffArr[l]+=x;
    diffArr[r+1]-=x;
    return;
}

void updArr(vector<int> &arr, vector<int> &diffArr, int n){
    arr[0]=diffArr[0];
    for(int i=1; i<n; i++){
        arr[i]=diffArr[i]+arr[i-1];
    }
    return;
}

void printDiffArr(vector<int> &arr, vector<int> &diffArr, int n){
    cout<<diffArr[0]<<" ";

    for(int i=1; i<n; i++){
        cout<<diffArr[i]+arr[i-1]<<" ";
    }
    cout<<endl;
    return;
}

#endif // DIFFERENCE_ARRAY_H_INCLUDED
