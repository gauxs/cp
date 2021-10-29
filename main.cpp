#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int profit(vector<int>& prices, int n, int cur_day, vector<vector<int>>& mem, int transactionsLimit, int numberOfTransactionsDone){
        if(cur_day>=n || numberOfTransactionsDone>transactionsLimit)
            return 0;
        
        if(mem[numberOfTransactionsDone][cur_day]!=INT_MIN)
            return mem[numberOfTransactionsDone][cur_day];
        
        int profit_from_buying_today=0, profit_from_not_buying_today=0;
        
        profit_from_not_buying_today = profit(prices, n, cur_day+1, mem, transactionsLimit, numberOfTransactionsDone);
        if(cur_day+1<n && prices[cur_day+1]>prices[cur_day])
            profit_from_buying_today = profit(prices, n, cur_day+1, mem, transactionsLimit, numberOfTransactionsDone+1) + (prices[cur_day+1]-prices[cur_day]);
            
        mem[numberOfTransactionsDone][cur_day] = max(profit_from_buying_today, profit_from_not_buying_today);
        cout<<"Day: "<<cur_day+1<<" || Transaction Done: "<<numberOfTransactionsDone<<" || Profit: "<<mem[numberOfTransactionsDone][cur_day]<<endl;
        cout<<"profit_from_not_buying_today: "<<profit_from_not_buying_today<<" || profit_from_buying_today: "<<profit_from_buying_today<<endl<<endl;
        return mem[numberOfTransactionsDone][cur_day];
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> mem(3, vector<int>(n, INT_MIN));
        
        return profit(prices, n, 0, mem, 2, 0);
    }
};

int main() {
    vector<int> arr{1, 2, 3, 4, 5};
    Solution obj;
    cout<<obj.maxProfit(arr)<<endl;
    return 0;
}