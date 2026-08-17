#include<bits/stdc++.h>
using namespace std;
//Recurrence
int dfs(int i,vector<int>& coins, int amount ){
    if(amount ==0) return 0;
    if(i==0){
        if(amount % coins[i] ==0){
            return amount/coins[i]; 
        }
        return 1e9;
    }

    int notTake = 0+ dfs(i-1,coins,amount);  //consume
    int Take = 1e9; 
    if(coins[i]<=amount){
        Take = 1 + dfs(i,coins,amount-coins[i]); //Stay
    }
    return min(notTake,Take);
}
  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int ans = dfs(n-1,coins,amount);
    return ans==1e9 ? -1 : ans;        
    }

    //memoization
 int dfs(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (i == 0) {
            if (amount % coins[i] == 0) {
                return dp[i][amount] = amount / coins[i];
            }
            return dp[i][amount] = 1e9;
        }
        if (dp[i][amount] != -1)
            return dp[i][amount];

        int notTake = 0 + dfs(i - 1, coins, amount, dp); // consume
        int Take = 1e9;
        if (coins[i] <= amount) {
            Take = 1 + dfs(i, coins, amount - coins[i], dp); // Stay
        }
        return dp[i][amount] = min(notTake, Take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = dfs(n - 1, coins, amount, dp);
        return ans >= 1e9 ? -1 : ans;
    }

    //Tabulation
      int coinChange(vector<int>& coins, int amount) {
          int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 1e9));
        
       for(int i=0; i<n; ++i){
        dp[i][0] = 0;
       }
        for(int amnt=1; amnt<=amount; ++amnt){
            if(amnt % coins[0] == 0) dp[0][amnt] = amnt/coins[0];
        }

       for(int i=1; i<n; ++i){
        for(int amnt =1; amnt <= amount ; ++amnt){
            int notTake = dp[i-1][amnt];
            int Take = 1e9;
             if ( coins[i] <= amnt) {
             Take = 1 + dp[i][amnt - coins[i]];
        }
         dp[i][amnt] = min(Take,notTake);
        }
       }
       if(dp[n-1][amount]>=1e9) return -1;
       else return dp[n-1][amount];   
    }

    //Space safe
       int coinChange(vector<int>& coins, int amount) {
            int n = coins.size();
        vector<int> prev(amount+1, 1e9);
        
         prev[0] = 0;
        for(int amnt=1; amnt<=amount; ++amnt){
            if(amnt % coins[0] == 0) prev[amnt] = amnt/coins[0];
        }

       for(int i=1; i<n; ++i){
        vector<int>curr(amount+1,0);
        for(int amnt =1; amnt <= amount ; ++amnt){
            int notTake = prev[amnt];
            int Take = 1e9;
             if ( coins[i] <= amnt) {
             Take = 1 + curr[amnt - coins[i]];
        }
             curr[amnt] = min(Take,notTake);
        }
        prev = curr;
       }
       if( prev[amount]>=1e9) return -1;
       else return prev[amount];
    }

    //Single ARR
     int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> curr(amount + 1, 1e9);

        curr[0] = 0;
        for (int amnt = 1; amnt <= amount; ++amnt) {
            if (amnt % coins[0] == 0)
                curr[amnt] = amnt / coins[0];
        }

        for (int i = 1; i < n; ++i) {
            for (int amnt = coins[i]; amnt <= amount; ++amnt) {
                int notTake = curr[amnt];
                int take = 1 + curr[amnt - coins[i]];
                curr[amnt] = min(notTake, take);
            }
        }
        if (curr[amount] >= 1e9)
            return -1;
        else
            return curr[amount];
    }