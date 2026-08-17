#include<bits/stdc++.h>
using namespace std;
int dfs(int i, int sum, int target, vector<int>& nums, vector<vector<int>>& dp){
    if(sum>target) return 0;
    if(i>=nums.size()){
        if(sum==target) return 1;
        return 0;
    }

    if(dp[i][target] != -1) return dp[i][target];
    
    if(sum==target) return 1;
    int count = 0;

    //pick
    count += dp[i][target] = dfs(i+1,sum+nums[i],target,nums,dp);
    //dont pick
    count += dp[i][target] = dfs(i+1,sum,target,nums,dp);

    return count;
}
int findways(vector<int>& nums, int tar){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(tar+1,-1));
    int ans = dfs(0,0,tar,nums,dp);
    return ans;
}

//Tabulation:
int findways(vector<int>&nums, int target){
  // code here
           int n = nums.size();
     //dp[i][target]
     vector<vector<int>> dp(n, vector<int>(target+1,0));
     for(int i=0; i<n; ++i) dp[i][0] = 1;
     if(nums[0]<=target) dp[0][nums[0]] = 1;

     for(int i=1; i<n; ++i){
        for(int j=1; j<=target; ++j){
            int dontPick = dp[i-1][j];
            int pick = 0;
            if(nums[i]<=j) pick = dp[i-1][j-nums[i]];
            dp[i][j] = pick+dontPick;
        }
     }
     return dp[n-1][target];
}