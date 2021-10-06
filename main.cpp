// { Driver Code Starts
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

class Solution {
public:
    int min_i, max_i, min_j, max_j;
    void answer(vector<vector<char>>& board, vector<vector<bool>>& visited, int m, int n, int i, int j, vector<pair<int, int>> &nodes){
        if(board[i][j]=='X' || visited[i][j] || i>=m || j>=n)
            return;
        
        visited[i][j] = true;
        min_i = min(min_i, i); max_i = max(max_i, i);
        min_j = min(min_j, j); max_j = max(max_j, j);
        nodes.push_back(make_pair(i, j));
        answer(board, visited, m, n, i+1, j, nodes);
        answer(board, visited, m, n, i, j+1, nodes);
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<pair<int, int>> nodes;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O' && !visited[i][j]){
                    min_i = i; max_i = i;
                    min_j = j; max_j = j;
                    answer(board, visited, m, n, i, j, nodes);
                    if(min_i>0 && max_i<m-1 && min_j>0 && max_j<n-1){
                        for(auto p: nodes){
                            board[p.first][p.second] = 'X';
                        }
                    }
                    nodes.clear();
                }
            }
        }
        
        return;
    }
};
int main() {
    vector<vector<char>> board{{'X','X','X','X'}, {'X','O','O','X'}, {'X','X','O','X'}, {'X','O','X','X'}};
    Solution ob;
    ob.solve(board);

    return 0;
}
  // } Driver Code Ends