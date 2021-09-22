#ifndef KMP_H_INCLUDED
#define KMP_H_INCLUDED

#include <string>
#include <vector>

/*
    1 - The basic idea behind KMP’s algorithm is: whenever we detect a mismatch (after some matches), we already know some
        of the characters in the text of the next window. We take advantage of this information to avoid matching the characters
        that we know will anyway match. 
    2 - The prefix function for this string is defined as an array π of length n, where π[i] is the length of the longest 
        proper prefix of the substring s[0…i] which is also a suffix of this substring.
    3 - A proper prefix of a string is a prefix that is not equal to the string itself. By definition, π[0]=0

    Reference:  https://cp-algorithms.com/string/prefix-function.html
*/

/*
    Time complexity: O(n)   // n is string length    
    Space complexity: O(n)
*/
std::vector<int> kmp(std::string const &str){
    int str_len = str.length();
    std::vector<int> proper_prefix_function(str_len);
    // proper prefix of a string is a prefix that is not equal to the string itself. By definition, π[0]=0
    proper_prefix_function[0] = 0;
    for(int i=1; i<str_len; i++){
        int j = proper_prefix_function[i-1];
        while(j>0 && str[i]!=str[j])
            j = proper_prefix_function[j-1];
        if(str[i]==str[j])
            j++;
        proper_prefix_function[i] = j;
    }

    return proper_prefix_function;
}

#endif // KMP_H_INCLUDED