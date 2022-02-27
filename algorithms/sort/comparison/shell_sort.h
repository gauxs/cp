#ifndef SHELL_SORT_H_INCLUDED
#define SHELL_SORT_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

/*
    Reference:  https://www.geeksforgeeks.org/shellsort/
*/

/*
    Time complexity:
    1.  Worst: O(n*n) - sorted in reverse order
    2.  Average: O(n*n)
    3.  Best: O(n) - sorted in-order

    Space complexity: O(1)
    Inplace sorting: yes
    Stable sorting: yes
*/
void shell_sort(std::vector<int> &input){
    int n = input.size();

    // gap goes from [n/2, 1]
    for(int gap=n/2; gap>0; gap/=2){
        for(int i=gap; i<n; i++){
            int temp = input[i];
            int j;
            // j>=gap because we are checking input[j-gap]
            for(j=i; j>=gap && input[j-gap]>temp; j-=gap){
                input[j] = input[j-gap];
            }
            input[j] = temp;
        }
    }
    
    return;
}

#endif // SHELL_SORT_H_INCLUDED

// int main(){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     std::cout.tie(NULL);
    
//     std::vector<int> input{ 1, 4, 1, 2, 7, 5, 2};
    
//     shell_sort(input);
//     myutils::myprint::print(input, input.size());

//     return 0;
// }