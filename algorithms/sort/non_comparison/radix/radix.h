
#ifndef RADIX_H_INCLUDED
#define RADIX_H_INCLUDED

#include <vector>
#include <iostream>
#include <utils/basic.h>

void counting_sort(std::vector<int> &input, int exp){
    std::vector<int> output(input.size());
    std::vector<int> count(10);

    for(int i=0; i<input.size(); i++){
        count[(input[i]/exp)%10]++;
    }

    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }

    // to make it stable we are operating in reverse order.
    for(int i=input.size(); i>=0; i--){
        output[count[(input[i]/exp)%10]-1] = input[i];
        count[(input[i]/exp)%10]--;
    }

    for(int i=0; i<output.size(); i++){
        input[i] = output[i];
    }

    return;
}

void radix_sort(std::vector<int> &input){
    int max_ele = myutils::mymath::get_max(input);
    // O(d)
    for(int i=1; max_ele/i>0; i*=10){
        // O(n)
        counting_sort(input, i);
    }
}

#endif // RADIX_H_INCLUDED