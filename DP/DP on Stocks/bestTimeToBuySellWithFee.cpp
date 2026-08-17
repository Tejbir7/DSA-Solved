#include<bits/stdc++.h>
using namespace std;
 int dfs(int i, int buy, vector<int>& nums, const int &fee, vector<vector<int>> &dp) {
        if (i >= nums.size())
            return 0;


            if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if (buy)
            profit = max(-nums[i] + dfs(i + 1, 0, nums, fee, dp), dfs(i + 1, 1, nums, fee, dp));
        else
            profit =
                max(nums[i] - fee + dfs(i + 1, 1, nums,fee, dp), dfs(i + 1, 0, nums, fee, dp));

        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) { 
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return dfs(0, 1, prices, fee, dp);
     }

     //space
       int maxProfit(vector<int>& nums, int fee) {
           int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));

        for(int i =n-1; i>=0; --i){
            dp[i][1] = max(-nums[i] + dp[i+1][0], dp[i+1][1]);
            dp[i][0] = max(nums[i]- fee + dp[i+1][1], dp[i+1][0]);
        }
        return dp[0][1];
    }
    //best
     int maxProfit(vector<int>& nums, int fee) {
           int n = nums.size();
      array<int,2> next{}; array<int,2> curr;

        for(int i =n-1; i>=0; --i){
            curr[1] = max(-nums[i] + next[0], next[1]);
            curr[0] = max(nums[i]- fee + next[1], next[0]);
             swap(curr,next);
        }
        return next[1];
    }
