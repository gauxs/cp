#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED

#include <string>
#include <utils/basic.h>

/*
    1 - We want to solve the problem of comparing strings efficiently.
    2 - We convert each string into an integer and compare those instead of the strings. Comparing two strings is then an O(1) operation.
    3 - For the conversion, we need a hash function. The goal of it is to convert a string into an integer, the hash of the string.
    4 - We want the hash function to map strings onto numbers of a fixed range [0,m).
    5 - And of course, we want hash(s)≠hash(t) to be very likely if s≠t.
    6 - Using hashing will not be 100% deterministically correct, because two complete different strings might have the
        same hash (the hashes collide).
    7 - However, in a wide majority of tasks, this can be safely ignored as the probability of the hashes of two different strings
        colliding is still very small.

    Properties of Hash function:
    1 - if two strings s and t are equal (s=t), then also their hashes have to be equal (hash(s)=hash(t))
    2 - if the hashes are equal (hash(s)=hash(t)), then the strings DO NOT necessarily have to be equal

    Reference: https://cp-algorithms.com/string/string-hashing.html
*/

/*
    Time complexity: O(m)   // m is the string length
    Space complexity: O(1)
*/
long long int compute_hash_polynomial_rolling(std::string const &str){
    /*
        It is reasonable to make p a prime number roughly equal to the number of characters in the input alphabet.
        For example, if the input is composed of only lowercase letters of the English alphabet, p=31 is a good choice.
        If the input may contain both uppercase and lowercase letters, then p=53 is a possible choice.
    */
    const int p = 31;
    //  a good choice for m is some large prime number
    const int m = 1e9 + 9;
    long long int p_pow = 1;
    long long int hash_value = 0;
    int str_length = str.length();

    for(int i=0; i<str_length; i++){
        //  converting a→0 is not a good idea, because then the hashes of the strings a, aa, aaa, … all evaluate to 0
        hash_value = hash_value + ((str[i] - 'a' + 1) * p_pow) % m;
        //  pre-compute p_pow for more efficiency at the expense of space
        p_pow = (p_pow * p) % m;
    }

    return hash_value;
}

/*
    Fast hash calculation of substrings of given string
    1 - By knowing the hash value of each prefix of the string s, we can compute the hash of any substring directly using the formula
        prooved at https://cp-algorithms.com/string/string-hashing.html.
    2 - Why did they added 'm', while calculating hash of substring? We are just supposed to multiply with same p_pow, which is being
        done in next line. Code below:
            ...
            long long cur_h = (h[i + l] + m - h[i]) % m; // why adding m?
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            ...

    Improve no-collision probability:
    1 - There is a really easy trick to get better probabilities. We can just compute two different hashes for each string (by using two
        different p, and/or different m, and compare these pairs instead. If m is about 10^9 for each of the two hash functions than this 
        is more or less equivalent as having one hash function with m≈10^18. When comparing 106 strings with each other, the probability
        that at least one collision happens is now reduced to ≈10^-6.
*/
#endif // HASHING_H_INCLUDED