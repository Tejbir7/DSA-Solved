 #include<bits/stdc++.h>
 using namespace std;
 //Recursive
    int dfs(int i,int amount, vector<int>& coins){
    if(amount == 0){
        return 1;
    }
    if(i==0){
        if(amount % coins[0] == 0){
            return 1;
        }
        return 0;
    }

    int notTake = 0, Take = 0;
     notTake += dfs(i-1,amount,coins);
    if(coins[i]<=amount){
        Take += dfs(i,amount-coins[i],coins);
    }

    return Take+notTake;
 }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return dfs(n-1,amount,coins);
    }

    //Memoization
     int dfs(int i,int amount, vector<int>& coins,vector<vector<int>>&dp){
    if(amount == 0){
        return 1;
    }
    if(i==0){
        if(amount % coins[0] == 0){
            return 1;
        }
        return 0;
    }
    if(dp[i][amount]!=-1) return dp[i][amount];

    int notTake = 0, Take = 0;
     notTake += dfs(i-1,amount,coins,dp);
    if(coins[i]<=amount){
        Take += dfs(i,amount-coins[i],coins,dp);
    }

    return dp[i][amount]= Take+notTake;
 }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return dfs(n-1,amount,coins,dp);
    }
