#include<bits/stdc++.h>
using namespace std;
 int dfs(int i, int buy,const vector<int>& prices, vector<vector<int>>&dp){
    if(i>= prices.size()) return 0;

    if(dp[i][buy] != -1) return dp[i][buy];
    int profit = 0;

    if(buy){
        profit = max(-prices[i] + dfs(i+1,0,prices, dp) , dfs(i+1,1,prices, dp));
    }else{
        profit =  max(prices[i] + dfs(i+2,1,prices, dp), dfs(i+1,0,prices,dp));
    }

    return dp[i][buy] = profit;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
      vector<vector<int>> dp(n, vector<int>(2,-1));
        return dfs(0,1,prices, dp);
    }

    //space optimised
    int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<vector<int>> dp(n+2, vector<int>(2,0));
       
      for(int i=n-1; i>=0; --i){
        dp[i][0] = max(prices[i] + dp[i+2][1], dp[i+1][0]);
        dp[i][1] = max(- prices[i] + dp[i+1][0], dp[i+1][1]);
      }
      return dp[0][1];
    }

    //space optimised
     int maxProfit(vector<int>& prices) {
      int n = prices.size();
      vector<vector<int>> dp(n, vector<int>(2,-1));
        return dfs(0,1,prices, dp);
    }

    //space optimised
       int maxProfit(vector<int>& prices) {
           int n = prices.size();


      array<int,2> ancient{};
      array<int,2> next{};
      array<int,2> curr;

       
      for(int i=n-1; i>=0; --i){
        
        curr[0] = max(prices[i] + ancient[1], next[0]);
        curr[1] = max(- prices[i] + next[0], next[1]);
        swap(next,ancient);
        swap(curr,next);
      }
      return next[1];
    }