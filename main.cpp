#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <cmath>
#include "algorithms/search/exponential_search.h"
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::vector<int> input{1, 4, 6, 19, 21, 34, 57, 64, 111, 145};
    std::cout<<exponential_search(input, 21)<<std::endl;

    return 0;
}