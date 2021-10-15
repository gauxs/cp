// { Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

bool my_sort(vector<int> &a, vector<int> &b){
    return a[0]>b[0]?true:a[1]>b[1]?true:a[2]>b[2];
}

class Solution {
public:
    int answer(vector<vector<int>> &cuboids, int n, vector<int> &mem, int cur_cuboid){
        if(cur_cuboid>=n){
            return 0;
        }
        
        int max_height = 0, local_height;
        for(int i=cur_cuboid+1; i<n; i++){
            if(cuboids[i][0]<=cuboids[cur_cuboid][0] && cuboids[i][1]<=cuboids[cur_cuboid][1] && cuboids[i][2]<=cuboids[cur_cuboid][2]){
                local_height = answer(cuboids, n, mem, i); 
                if(local_height>max_height)
                    max_height = local_height;
            }
        }
        
        return max_height + max(cuboids[cur_cuboid][0], max(cuboids[cur_cuboid][1], cuboids[cur_cuboid][2]));
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<int> mem(n, -1);
        
        sort(cuboids.begin(), cuboids.end(), my_sort);
        
        for(int i=0; i<n; i++){
            cout<<cuboids[i][0]<<cuboids[i][1]<<cuboids[i][2]<<endl;
        }
        
        int ans=0;
        for(int i=0; i<n; i++){
            ans = max(ans, answer(cuboids, n, mem, i));
            cout<<ans<<endl;
        }
        
        return ans;
    }
};

int main() {
    vector<vector<int>> board{{50,45,20},{95,37,53},{45,23,12}};
    Solution ob;
    ob.maxHeight(board);

    return 0;
}
  // } Driver Code Ends