
#ifndef RADIX_SORT_H_INCLUDED
#define RADIX_SORT_H_INCLUDED

#include <vector>
#include <iostream>
#include <utils/basic.h>

/*
    Digit by digit sort starting from least significant digit to most significant digit. Radix sort uses 
    counting sort as a subroutine to sort.

    Note:
    1 - Is Radix Sort preferable to Comparison based sorting algorithms like Quick-Sort? 
        If we have log2n bits for every digit, the running time of Radix appears to be better than Quick Sort for a wide range of input 
        numbers. The constant factors hidden in asymptotic notation are higher for Radix Sort and Quick-Sort uses hardware caches more 
        effectively. Also, Radix sort uses counting sort as a subroutine and counting sort takes extra space to sort numbers.

    Reference: https://www.geeksforgeeks.org/radix-sort/
*/

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

/*
    Time complexity: 
    Let there be d digits in input integers. Radix Sort takes O(d*(n+b)) time where b is the base for representing numbers,
    for example, for the decimal system, b is 10. What is the value of d? If k is the maximum possible value, then d would
    be O(logb(k)). So overall time complexity is O((n+b) * logb(k)). Which looks more than the time complexity of comparison-based
    sorting algorithms for a large k. Let us first limit k. Let k <= n^c where c is a constant. In that case, the complexity becomes
    O(n*logb(n)). But it still doesn’t beat comparison-based sorting algorithms.

    What if we make the value of b larger?. What should be the value of b to make the time complexity linear? If we set b as n, we
    get the time complexity as O(n). In other words, we can sort an array of integers with a range from 1 to n^c if the numbers are
    represented in base n (or every digit takes log2(n) bits).

    Space complexity: O(n+k) where n is number of elements and k is the range of input (for counting sort) which is constant here i.e 10
    Inplace sorting: No
    Stable sorting: Yes
*/
void radix_sort(std::vector<int> &input){
    int max_ele = myutils::mymath::get_max(input);
    // O(d)
    for(int i=1; max_ele/i>0; i*=10){
        // O(n)
        counting_sort(input, i);
    }
}

#endif // RADIX_SORT_H_INCLUDED

// int main(){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     std::cout.tie(NULL);
    
//     std::vector<int> input{ 1, 4, 1, 2, 7, 5, 2};
    
//     radix_sort(input);
//     myutils::myprint::print(input, input.size());

//     return 0;
// }