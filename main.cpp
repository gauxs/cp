// #pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <utils/basic.h>
#include <utils/expression_parsing.h>

using namespace std;

class Solution {
public:
    int findBalanced(string s, int n, int times, int left, int right, vector<int> &occur){
        if(left>right){
            return 0;
        }
        
        int leftIndex=0, rightIndex=0;
        bool leftCanBePicked=false, rightCanBePicked=false;
        
        switch(s[left]){
            case 'Q':
                leftIndex = 0;
                break;
            case 'W':
                leftIndex = 1;
                break;
            case 'E':
                leftIndex = 2;
                break;
            case 'R':
                leftIndex = 3;
                break;
        }
        
        switch(s[right]){
            case 'Q':
                rightIndex = 0;
                break;
            case 'W':
                rightIndex = 1;
                break;
            case 'E':
                rightIndex = 2;
                break;
            case 'R':
                rightIndex = 3;
                break;
        }
        
        if((occur[leftIndex]+1)<=times){
            leftCanBePicked = true;
        }

        if((occur[rightIndex]+1)<=times){
            rightCanBePicked = true;
        }
        
        if(!leftCanBePicked && !rightCanBePicked){
            cout<<"left: "<<left<<"| right: "<<right<<endl;
            return right-left+1;
        }
        
        int a=1000000, b=1000000, c=1000000;
        if(leftCanBePicked && rightCanBePicked){
            occur[leftIndex]++;
            a = findBalanced(s, n, times, left+1, right, occur);            
            occur[leftIndex]--;
            
            occur[rightIndex]++;
            b = findBalanced(s, n, times, left, right-1, occur);
            occur[rightIndex]--;
            
            occur[leftIndex]++;
            occur[rightIndex]++;
            c = findBalanced(s, n, times, left+1, right-1, occur);
            occur[leftIndex]--;
            occur[rightIndex]--;
        }else if(!leftCanBePicked){
            occur[rightIndex]++;
            a = findBalanced(s, n, times, left, right-1, occur);
            occur[rightIndex]--;
        }else if(!rightCanBePicked){
            occur[leftIndex]++;
            a = findBalanced(s, n, times, left+1, right, occur);
            occur[leftIndex]--;
        }
        
        return min(c, min(a, b));
    }
    
    int balancedString(string s) {
        int s_len = s.length();
        int left=0, right=s_len-1;
        int times = s_len/4;
        vector<int> occur(4, 0);
        
        return findBalanced(s, s_len, times, left, right, occur);
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    string expression = "-2+1";
    cout<<expression_parsing(expression)<<endl;
    Solution obj;
    obj.balancedString("QQWE");

    return 0;
}