// #include "algorithms/graph/sort/topology_basic.h"

// using namespace std;

// int main(){
//     topological_basic();
//     return 0;
// }

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> change{20, 10, 5, 2, 1};    //2000, 500, 200, 100, 50, 
   
    pair<int, vector<int> > answer(int sumLeft, vector<pair<int, vector<int> > > &mem){
        if(sumLeft == 0){
            vector<int> v;
            pair<int, vector<int> > p(0, v);
            return p;
        }
       
        if(sumLeft < 0){
            vector<int> v;
            pair<int, vector<int> > p(-1, v);
            return p;
        }
       
        if(mem[sumLeft].first !=-1){
            return mem[sumLeft];
        }
       
        int overallMinIndex=-1;
        pair<int, vector<int> > localPair, overallPair(INT_MAX, vector<int>());
        for(int i=0; i<5; i++){
            localPair = answer(sumLeft-change[i], mem);
            if(localPair.first!=-1){
                if(localPair.first<overallPair.first){
                    overallPair=localPair;
                    overallMinIndex=i;
                }
            }
        }
       
        if(overallMinIndex!=-1){
            //cout<<change[overallMinIndex];
            overallPair.second.push_back(change[overallMinIndex]);
            overallPair.first += 1;
            mem[sumLeft] = overallPair;
        }else{
            overallPair.first = -1;
        }
       
        return overallPair;
    }
   
    vector<int> minPartition(int N){
        pair<int, vector<int> > ans;
        vector<pair<int, vector<int> > > mem(N+1, pair<int, vector<int> >(-1, vector<int>()));
        ans = answer(N, mem);
        sort(ans.second.begin(), ans.second.end(), greater<int>());
        return ans.second;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends