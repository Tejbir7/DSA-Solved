#include<bits/stdc++.h>
using namespace std;
int f(int i, int k,const vector<int>& nums, vector<int> &dp){
    int n = nums.size();
    if(i>= n) return 0;
    if(dp[i] != -1) return dp[i];

    int maxi = INT_MIN;
    int ans = 0;

    for(int j=i ; j< min(n,i+k) ; ++j){
       maxi = max(maxi, nums[j]);
       int len = j-i+1;
       ans = max(ans, (maxi* len + f(j+1,k, nums, dp)));
    }
    return dp[i] = ans;   
}

int maxSumAfterPartitioning(const vector<int>& nums, int k) {
    int n = nums.size();
       vector<int> dp(n, -1);
        return f(0,k,nums, dp);

    }