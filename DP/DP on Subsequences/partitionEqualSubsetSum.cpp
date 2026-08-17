#include<bits/stdc++.h>
using namespace std;

 bool dfs(int i, int sum,int target, vector<int>&nums, vector<vector<int>> &dp){
    if (sum > target) return false;
    if(i==nums.size()){
        if(sum==target) return true;
        return false;
    }
    if(dp[i][sum]!= -1) return dp[i][sum];
    
    if(sum== target) return true;

    //take
    if(dfs(i+1,sum+nums[i],target, nums,dp)) return dp[i][sum] = true;

    //dont take 
    if(dfs(i+1,sum,target, nums,dp))  return dp[i][sum] = true;
    return dp[i][sum] = false;
   }


    bool canPartition(vector<int>& nums) {
     int n = nums.size();
    int sum = 0;

   for(int i: nums) sum+= i;
   if(sum%2 != 0) return false;

    vector<vector<int>> dp(n, vector<int>(sum/2+1,-1)); 
    if(dfs(0,0,sum/2,nums,dp)) return true;

    return false; 
    }
    
    //Tabulation:
     bool canPartition(vector<int>& nums) {
          int n = nums.size();
          int sum = 0;
          for(int i: nums) sum+= i;
          if(sum%2 != 0) return false;

          int k = sum/2;
           vector<vector<bool>> dp(n, vector<bool>(k+1,false));

           for(int i=0; i<n; ++i) dp[i][0] = true;
           if(nums[0]<=k ) dp[0][nums[0]] = true;

           for(int i = 1; i<n; ++i){
            for(int target=1; target<=sum/2 ; ++target){

            bool notTake = dp[i-1][target];
            bool Take = false;

            if(nums[i]<=target) Take = dp[i-1][target- nums[i]];

            dp[i][target] = Take || notTake;
        }
    }
    return dp[n-1][sum/2];  
    }

    //Space optimised
       bool canPartition(vector<int>& nums) {
            int n = nums.size();
            int sum = 0;
            for(int i: nums) sum+= i;
            if(sum%2 != 0) return false;

          int k = sum/2;
    vector<bool> prev(k+1, false);   
    prev[0] = true;
    if(nums[0]<=k) prev[nums[0]] = true;

    for(int i = 1; i<n; ++i){
        vector<bool> temp(k+1,false);
        temp[0] = true;

        for(int target=1; target<=k ; ++target){
            bool notTake = prev[target];
            bool Take = false;

            if(nums[i]<=target) Take = prev[target- nums[i]];
            temp[target] = Take || notTake;
        }
        prev = temp;
    }
    return prev[k];

    }