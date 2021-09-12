#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <deque>
#include <utils/basic.h>

using namespace std;

bool myComp(string s1, string s2){
        int len_s1 = s1.length();
        int len_s2 = s2.length();
        
        if(len_s1==len_s2){
            for(int i=0; i<len_s1; i++){
                if(s1[i]>s2[i]){
                    return true;
                }else if(s1[i]<s2[i]){
                    return false;
                }
            }
            return true;
        }else{
            if(len_s1<len_s2){
                for(int i=0; i<len_s1; i++){
                    if(s1[i]>s2[i]){
                        return true;
                    }else if(s1[i]<s2[i]){
                        return false;
                    }
                }
                int j=0;
                for(int i=len_s1; i<len_s2; i++, j++){
                    if(s2[i]>s2[j]){
                        return false;
                    }else if(s2[i]<s2[j]){
                        return true;
                    }
                }
                
                for(int i=0; i<len_s1 && j<len_s2; i++, j++){
                    if(s2[j]<s1[i]){
                        return false;
                    }else if(s2[j]>s1[i]){
                        return true;
                    }
                }
                return false;
            }else{
                for(int i=0; i<len_s2; i++){
                    if(s1[i]>s2[i]){
                        return true;
                    }else if(s1[i]<s2[i]){
                        return false;
                    }
                }
                int j=0;
                for(int i=len_s2; i<len_s1; i++, j++){
                    if(s1[i]>s1[j]){
                        return true;
                    }else if(s1[i]<s1[j]){
                        return false;
                    }
                }
                
                for(int i=0; i<len_s2 && j<len_s1; i++, j++){
                    if(s1[j]<s2[i]){
                        return true;
                    }else if(s1[j]>s2[i]){
                        return false;
                    }
                }
                
                return true;
            }
        }
    }

class Solution {
public:
       
    string largestNumber(vector<int>& nums) {
        string answer;
        vector<string> str(nums.size());
        
        for(int i=0; i<nums.size(); i++){
            str[i] = to_string(nums[i]);
        }
        
        sort(str.begin(), str.end(), myComp);
        
        for(int i=0; i<str.size(); i++){
            answer += str[i];
        }
        
        bool allZero = true;
        cout<<answer<<endl;
        for(int i=0; i<answer.length(); i++){
            if(answer[i]!='0'){
                allZero=false;
                break;
            }    
        }
        
        if(allZero){
            answer="0";
        }
        
        return answer;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::vector<int> input{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    // Solution obj;
    // cout<<obj.largestNumber(input)<<endl;
    cout<<(7<<3)<<endl;

    return 0;
}