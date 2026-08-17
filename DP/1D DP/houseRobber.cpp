#include<bits/stdc++.h>
using namespace std;
int solve(int i, vector<int> &dp, vector<int>&nums){
    if(i<0) return 0;
    if(i==0) return nums[i];
    if(dp[i]!=-1) return dp[i];
    int pick = nums[i] + solve(i-2,dp,nums);
    int dontPick = solve(i-1,dp, nums);
    return dp[i] = max(pick, dontPick);
}
 int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n, -1);
        int ans = solve(n-1, dp, nums);
        return ans;
    }

    //Tabulation:
     int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
       dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<n; ++i){
            int pick = nums[i] + dp[i-2];
            int dontPick = dp[i-1];
            dp[i] = max(pick,dontPick);
        }

        return dp[n-1];
        
    }
    //space optimisation
   int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    int first = nums[0];
    int  sec = max(nums[0], nums[1]);
    for(int i=2; i<n; ++i){
        int take = nums[i] + first;
        int dontTake = sec;

        int ans = max(take,dontTake);
        first = sec;
        sec = ans;
    }

    return sec;
        
    }