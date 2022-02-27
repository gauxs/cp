#ifndef SQUARE_ROOT_DECOMPOSITION_H_INCLUDED
#define SQUARE_ROOT_DECOMPOSITION_H_INCLUDED

#pragma GCC optimize("Ofast")
#include <vector>
#include <cmath>

void initializeStorage(std::vector<int> &input, std::vector<int> &storage, int n, int s){
    for(int i=0; i<n; i++){
        // think of each index like a bucket
        // [0, s-1] at index 0, [s, 2s-1] at index 1 ....
        storage[i/s] += input[i];   
    }

    return;
}

// its slow because of division operations
int findSumInRangeSlow(std::vector<int> &input, std::vector<int> &storage, int l, int r, int s){
    int sum=0;
    for(int i=l; i<=r; ){
        if(i%s==0 && i+s-1<=r){
            sum += storage[i/s];
            i += s;
        }else{
            sum += input[i];
            i++;
        }
    }

    return sum;
}


int findSumInRangeFast(std::vector<int> &input, std::vector<int> &storage, int l, int r, int s){
    int sum=0;
    int left_block = l/s, right_block = r/s;

    if(left_block == right_block){
        for(int i=l; i<=r; i++){
            sum += input[i];
        }
    }else{
        for(int i=l, end=((left_block+1)*s)-1; i<=end; i++){
            sum += input[i];
        }

        for(int i=(left_block+1); i<=(right_block-1); i++){
            sum += storage[i];
        }

        for(int i=right_block*s; i<=r; i++){
            sum += input[i];
        }
    }
    
    return sum;
}

#endif // SQUARE_ROOT_DECOMPOSITION_H_INCLUDED

// int main(){
//     std::vector<int> input{5, 2, 7, 1, 8, 6, 10};
//     int n = input.size();
//     int s = (int)sqrt(n+0.0)+1; // number of blocks and size of blocks
//     std::vector<int> storage(s);

//     initializeStorage(input, storage, n, s);
//     std::cout<<findSumInRangeSlow(input, storage, 3, 5, s)<<std::endl;
//     std::cout<<findSumInRangeFast(input, storage, 0, 6, s)<<std::endl;

//     return 0;
// }