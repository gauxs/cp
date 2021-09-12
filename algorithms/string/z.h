#ifndef Z_H_INCLUDED
#define Z_H_INCLUDED

#include <string>
#include <vector>
#include <algorithm>

/*
    1 - Z-function for this string is an array of length n where the i-th element is equal to the greatest number of characters
        starting from the position i that coincide with the first characters of s
    2 - z[i] is the length of the longest string that is, at the same time, a prefix of s and a prefix of the suffix of s starting at i
    3 - first element of Z-function, z[0], is generally not well defined, we will assume it is zero

    Reference: https://cp-algorithms.com/string/z-function.html
*/

/*
    Time complexity: O(n)   // n is length of the string
    Space complexity: O(n)  
*/
std::vector<int> z(std::string const &str){
    int str_len = str.length();
    std::vector<int> z_arr(str_len);

    // first element of Z-function, z[0], is generally not well defined, we will assume it is zero
    z_arr[0] = 0;
    for(int i=1, l=0, r=0; i<str_len; i++){
        if(i<=r)
            z_arr[i] = std::min(r-i+1, z_arr[i-l]);
        while(i+z_arr[i]<str_len && str[z_arr[i]]==str[i+z_arr[i]])
            ++z_arr[i];
        if(i+z_arr[i]-1 > r){
            l = i;
            r = i+z_arr[i]-1;
        }
    }

    return z_arr;
}

#endif // Z_H_INCLUDED
