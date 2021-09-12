#ifndef RABIN_KARP_H_INCLUDED
#define RABIN_KARP_H_INCLUDED

#include <string>
#include <algorithm>
#include <utils/basic.h>

/*
    NOTE:
    1 - Read proof of "Fast hash calculation of substrings of given string" at
        https://cp-algorithms.com/string/string-hashing.html to understand this more clearly.

    Reference: https://cp-algorithms.com/string/rabin-karp.html
*/

/*
    n - string length
    m - pattern length
    Time complexity: O(m + n)   // m is the string length
    Space complexity: O(m + n)
*/
std::vector<int> rabin_karp(std::string const &str, std::string const &pattern){
    int p = 31;
    int m = 1e9 + 9;
    int str_len = str.length();
    int pattern_len = pattern.length();
    int p_pow_len = std::max(str_len, pattern_len);

    // O(n + m)
    std::vector<long long int> p_pow(p_pow_len);
    p_pow[0] = 1;
    for(int i=1; i<p_pow_len; i++){
        p_pow[i] = (p_pow[i-1] * p) % m;
    }

    // O(m)
    long long int pattern_hash = 0;
    for(int i=0; i<pattern_len; i++){
        pattern_hash = (pattern_hash + (pattern[i] - 'a' + 1) * p_pow[i]) % m;
    }

    // O(n)
    // for convenience, we will use str_hash[i] as the hash of the prefix with i characters,
    // and define str_hash[0]=0.
    std::vector<long long int> str_hash(str_len+1);
    str_hash[0] = 0;
    for(int i=0; i<str_len; i++){
        str_hash[i+1] = (str_hash[i] + (str[i] - 'a' + 1) * p_pow[i]) % m;
    }

    std::vector<int> occurences;
    for(int i=0; i+pattern_len-1<str_len; i++){
        long long int cur_hash = (str_hash[i+pattern_len] - str_hash[i] + m) % m;   // still no idea, why +m here?
        // why *p_pow[i]? 
        // because we multiple both side by p^i, proof at https://cp-algorithms.com/string/string-hashing.html
        if(cur_hash == (pattern_hash * p_pow[i] % m)){  
            occurences.push_back(i);
        }
    }

    return occurences;
}

#endif // RABIN_KARP_H_INCLUDED