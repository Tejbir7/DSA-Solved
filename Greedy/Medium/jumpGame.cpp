#include<bits/stdc++.h>
using namespace std;
//dp
bool f(int i,const int n, const vector<int>& nums, vector<int>&dp){
    if(i>=n-1) return dp[i] = true;
    if(dp[i] != -1) return dp[i];
    
    for(int j=min(n-1, i+nums[i]); j>= i+1; --j){
        if(f(j,n,nums,dp)) return dp[i] = true;
    }

    return dp[i] = false;
 }

 bool canJump(vector<int>& nums) {
    int n = nums.size();
    vector<int>dp(n+1,-1);
    return f(0,n,nums,dp);
    }

    //greedy 
      bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = 0;
        for(int i=0; i<n; ++i){
            if(i>reach) return false;
            reach = i+nums[i];
            if(reach>= n-1) break;
        }
        return true;
    }