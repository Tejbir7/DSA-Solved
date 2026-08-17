#include<bits/stdc++.h>
using namespace std;

//Recurrence soln 
bool dfs(int i, int sum,int target, vector<int>&nums){
     if(i>=nums.size()){
        if(sum==target) return true;
        return false;
    }
   
    if(sum== target) return true;

    //take
    if(dfs(i+1,sum+nums[i],target, nums)) return true;

    //dont take 
    if(dfs(i+1,sum,target, nums)) return true;       

    return false;
}

bool ifExists(vector<int>&nums, int k){
    
    if(dfs(0,0,k,nums)) return true;
    return false;
}

//Top Down 

//Memoization
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

bool ifExists(vector<int>&nums, int k){

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    if(dfs(0,0,k,nums,dp)) return true;
    return false;
}


//Top Down
//Strivers version: Better understanding
//Better to use as forms direct tabulation 
bool f(int i, int target,vector<int>&nums, vector<vector<int>> &dp ){
    if(target == 0) return true;
    if(i == 0 ) return (target == nums[0]);

    if(dp[i][target] != -1) return dp[i][target];

    bool notTake = f(i-1, target, nums, dp);
    bool take = false;

    if(nums[i]<= target) take = f(i-1,target-nums[i],nums,dp);
    return dp[i][target] = take || notTake;
}
bool ifExists(vector<int>&nums, int k){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(k+1,-1));
    if(f(n-1,k,nums,dp)) return true;
    return false;
}

//Tabulation:
bool ifExists(vector<int>&nums, int k){
    int n = nums.size();
    vector<vector<bool>> dp(n, vector<bool>(k+1,false));
    for(int i=0; i<n; ++i) dp[i][0] = true;
     if(nums[0]<=k) dp[0][nums[0]] = true;

    for(int i = 1; i<n; ++i){
        for(int target=1; target<=k ; ++target){
            bool notTake = dp[i-1][target];
            bool Take = false;

            if(nums[i]<=target) Take = dp[i-1][target- nums[i]];

            dp[i][target] = Take || notTake;
        }
    }
    return dp[n-1][k];
}

//Space optimised
bool ifExists(vector<int>&nums, int k){
    int n = nums.size();
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
