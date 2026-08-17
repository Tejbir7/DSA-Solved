#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums,vector<int>&dp, int l, int r){
    if(r<l) return 0;
    if(r==l) return nums[l];
    if(dp[r]!=-1) return dp[r];
    int pick = nums[r] + solve(nums,dp,l,r-2);
    int dontPick = solve(nums,dp,l,r-1);
    return dp[r] = max(pick,dontPick);
    
}
 int rob(vector<int>& nums) {
   int n = nums.size();
    if(n==1) return nums[0];
     vector<int> dp1(n-1, -1);
     vector<int> dp2(n-1, -1);
     int ans1 = solve(nums,dp1,0,n-2);
     int ans2 = solve(nums,dp2,1,n-1);
     return max(ans1,ans2);
    }

    //m2
     int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int prev2 = 0;
        int prev1 = nums[0];
        for(int i=1; i<n-1; ++i){
            int take = nums[i] + prev2;
            int dontTake = prev1;
            int curri = max(take,dontTake);
            prev2 = prev1; prev1 = curri;
        }
        int ans1 = prev1;

        prev2 = 0;
        prev1 = nums[1];
        for(int i=2; i<n; ++i){
            int take = nums[i] + prev2;
            int dontTake = prev1;
            int curri = max(take,dontTake);
            prev2 = prev1; prev1 = curri;
        }
        int ans2 = prev1;

        return max(ans1,ans2);

        
    }
    //m3
    //  int rob(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==1) return nums[0];
    //     int prev2 = nums[0];
    //     int prev1 = max(nums[0],nums[1]);
    //     for(int i=2; i<n-1; ++i){
    //         int take = nums[i] + prev2;
    //         int dontTake = prev1;
    //         int curri = max(take,dontTake);
    //         prev2 = prev1; prev1 = curri;
    //     }
    //     int ans1 = prev1;

    //     prev2 = nums[1];
    //     prev1 = max(nums[1],nums[2]);
    //     for(int i=3; i<n; ++i){
    //         int take = nums[i] + prev2;
    //         int dontTake = prev1;
    //         int curri = max(take,dontTake);
    //         prev2 = prev1; prev1 = curri;
    //     }
    //     int ans2 = prev1;

    //     return max(ans1,ans2);

        
    // }
    //Not correct for 2 elements but for >=3 is correct 