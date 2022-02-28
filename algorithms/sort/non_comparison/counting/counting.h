#ifndef COUNTING_H_INCLUDED
#define COUNTING_H_INCLUDED

#include <vector>
#include <iostream>
#include "utils/basic.h"

void counting_sort(
        std::vector<int> &input,
            std::vector<int> &output,
                int min_ele, int max_ele){

    int input_len = input.size();
    std::vector<int> count(max_ele-min_ele+1);

    for(int i=0; i<input_len; i++)
        count[input[i]-min_ele]++;

    for(int i=1; i<(max_ele-min_ele+1); i++)
        count[i] += count[i-1];

    // to make it stable we are operating in reverse order.
    for(int i=input_len-1; i>=0; i--){
        output[count[input[i]-min_ele]-1] = input[i];
        count[input[i]-min_ele]--;
    }

    return;
}

#endif // COUNTING_H_INCLUDED