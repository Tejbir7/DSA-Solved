#include<bits/stdc++.h>
using namespace std; 

 int dfs(int i, int buy, int transaction,vector<int>& nums,vector<vector<vector<int>>>&dp ){
    if(transaction<=0 || i==nums.size() ) return 0;

    if(dp[i][buy][transaction] != -1) return dp[i][buy][transaction];
    int profit = 0;
    if(buy && transaction){
        profit = max(-nums[i] + dfs(i+1,0,transaction,nums,dp),
                      dfs(i+1,1,transaction,nums,dp));
    }
    else if(!buy && transaction){
        profit = max(nums[i] + dfs(i+1, 1,transaction-1,nums,dp), dfs(i+1,0,transaction,nums,dp));
    }

    return dp[i][buy][transaction] = profit;
}

 int maxProfit(vector<int>& nums) {
    int n = nums.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
    return dfs(0,1,2,nums, dp);
        
    }
//Tabulation

 int maxProfit(vector<int>& nums) {
        int n = nums.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

    for(int i=n-1; i>=0 ;--i){
        for(int buy: {0,1}){
            for(int transaction : {1,2}){

                 if(buy && transaction){
         dp[i][buy][transaction] = max(-nums[i] + dp[i+1][0][transaction],
                      dp[i+1][1][transaction]);
    }
    else if(!buy && transaction){
        dp[i][buy][transaction] = max(nums[i] + dp[i+1][1][transaction-1], dp[i+1][0][transaction]);
    }
            }
        }
    }
        return dp[0][1][2];  
    }

    //clever
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3,0)));

    for(int i=n-1; i>=0 ;--i){
            for(int transaction : {1,2}){

         dp[i][1][transaction] = max(-nums[i] + dp[i+1][0][transaction],
                      dp[i+1][1][transaction]);
    
        dp[i][0][transaction] = max(nums[i] + dp[i+1][1][transaction-1], dp[i+1][0][transaction]);
    
            }
        
    }
        return dp[0][1][2];  
    }
    //space optimisation
      int maxProfit(vector<int>& nums) {
        int n = nums.size();
    vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

    for(int i=n-1; i>=0 ;--i){
            for(int transaction : {1,2}){

         curr[1][transaction] = max(-nums[i] + next[0][transaction],
                      next[1][transaction]);
    
        curr[0][transaction] = max(nums[i] + next[1][transaction-1], next[0][transaction]);
    
            }
            swap(next,curr);
        
    }
        return next[1][2];  
    }
    //best
      int maxProfit(vector<int>& nums) {
        int n = nums.size();
    array<array<int,3>,2> next{},curr{};

    for(int i=n-1; i>=0 ;--i){
            for(int transaction : {1,2}){

         curr[1][transaction] = max(-nums[i] + next[0][transaction],
                      next[1][transaction]);
    
        curr[0][transaction] = max(nums[i] + next[1][transaction-1], next[0][transaction]);
    
            }
            swap(next,curr);
        
    }
        return next[1][2];  
    }
