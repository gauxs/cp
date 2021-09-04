#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <cmath>
#include <utils/basic.h>
#include "algorithms/sort/radix_sort.h"
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::vector<int> input{ 1, 4, 1, 2, 7, 5, 2};
    
    radix_sort(input);
    myutils::myprint::print(input, input.size());

    return 0;
}