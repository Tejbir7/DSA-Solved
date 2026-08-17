#include<bits/stdc++.h>
using namespace std;  
//Would give TLE
  int dfs(int i, int temp,vector<int>&nums ){
    if(i<0){
        return 0;
    }

    //Sell or wait for better
    if(temp > nums[i]) return max((temp- nums[i] +dfs(i-1, nums[i], nums)), dfs(i-1,temp,nums));

    //Start with this 
    return dfs(i-1,nums[i],nums);
}

int maxProfit(vector<int>&nums) {
    int n = nums.size();
        return dfs(n-2, nums[n-1], nums);
    }

    //Another dp idea 
  int dfs(int i, int buy,vector<int>&nums, vector<vector<int>>&dp){
        if(i==nums.size()) return 0;

        if(dp[i][buy]!= -1) return dp[i][buy];
        int profit = 0;

        if(buy){
            profit = max(- nums[i] + dfs(i+1,0,nums,dp), dfs(i+1,1,nums,dp));
        }else{
            profit = max(nums[i] + dfs(i+1,1,nums,dp), dfs(i+1,0,nums,dp));
        }

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>&nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return dfs(0,1,nums,dp);              
    }
    //Tabulation
     int maxProfit(vector<int>&nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        for(int i=n-1; i>=0; --i){
            for(int buy =0; buy<=1; ++ buy){
            
                if(buy){
                    dp[i][buy] = max(- nums[i] + dp[i+1][0], dp[i+1][1]);
                }else{
                    dp[i][buy]= max( nums[i] + dp[i+1][1], dp[i+1][0]);
        }
            }
        }
        return dp[0][1];         
    }

    //space optimised
      int maxProfit(vector<int>&nums) {
        int n = nums.size();
        vector<int> next(2,0), curr(2);

        for(int i=n-1; i>=0; --i){
            for(int buy =0; buy<=1; ++ buy){
            
                if(buy){
                    curr[buy] = max(- nums[i] + next[0], next[1]);
                }else{
                    curr[buy]= max( nums[i] + next[1], next[0]);
        }
            }
               swap(next,curr);
        }
        return next[1];         
    }

    //best
       int maxProfit(vector<int>&nums) {
        int n = nums.size();
        array<int,2> next = {0,0}, curr = {0,0};

        for(int i=n-1; i>=0; --i){
            for(int buy =0; buy<=1; ++ buy){
            
                if(buy){
                    curr[buy] = max(- nums[i] + next[0], next[1]);
                }else{
                    curr[buy]= max( nums[i] + next[1], next[0]);
        }
            }
               swap(next,curr);
        }
        return next[1];         
    }



