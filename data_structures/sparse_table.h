#ifndef SPARSE_TABLE_H_INCLUDED
#define SPARSE_TABLE_H_INCLUDED

#include <vector>
#include <cmath>

void initializeSumStorage(std::vector<int> &input, std::vector<std::vector<int> > &st, int n, int k){
    for(int i=0; i<n; i++){
        st[i][0]=input[i];
    }

    // O(N*k) or O(N*log(N))
    for(int j=1; j<k; j++){
        for(int i=0; (i+(1<<(j-1)))<n; i++){
            st[i][j]=st[i][j-1] + st[i+(1<<(j-1))][j-1];
        }
    }

    return;
}

int findSum(std::vector<std::vector<int> > &st, int l, int r, int n, int k){
    int sum=0;
    // O(k) or (log2(N))
    for(int i=k; i>=0; i--){
        if((1<<i)<=(r-l+1)){
            sum+=st[l][i];
            l+=(1<<i);
        }
    }

    return sum;
}


void initializeMinStorage(std::vector<int> &input, std::vector<std::vector<int> > &st, int n, int k){
    for(int i=0; i<n; i++){
        st[i][0]=input[i];
    }

    // O(N*k) or O(N*log(N))
    for(int j=1; j<k; j++){
        for(int i=0; (i+(1<<(j-1)))<n; i++){
            st[i][j]=std::min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }

    return;
}

int findMin(std::vector<std::vector<int> > &st, int l, int r, int n, int k){
    int j=log2(r-l+1);
    // O(1)
    return std::min(st[l][j], st[r-(1<<j)+1][j]);
}

#endif // SPARSE_TABLE_H_INCLUDED

// int main(){
//     std::vector<int> input{5, 2, 7, 1, 8, 6, 10};
//     int n = input.size();
//     int k = log2(n)+1;    // max range supported [n, n+(2^k)-1] = 2^k elements
//     std::vector<std::vector<int> > storage(n, std::vector<int>(k, -1));

//     // initializeSumStorage(input, storage, n, k);
//     // std::cout<<findSum(storage, 0, 6, n, k);

//     initializeMinStorage(input, storage, n, k);
//     std::cout<<findMin(storage, 0, 6, n, k);

//     return 0;
// }