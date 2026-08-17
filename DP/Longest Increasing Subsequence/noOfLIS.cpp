#include<bits/stdc++.h>
using namespace std;
  int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);

        int maxLen = 1;

        for(int i=1; i<n; ++i){
            for(int prev = 0; prev<i; ++prev){

                if(nums[i]> nums[prev]){
                   if(dp[i]<dp[prev]+1){
                    dp[i] = dp[prev]+1;
                    cnt[i] = cnt[prev];
                   }
                   else if(dp[i]==dp[prev]+1){
                    cnt[i]+= cnt[prev];
                   }
                }
            }
            if(maxLen< dp[i]){
                maxLen = dp[i];
            }
        }
        int ans = 0;
       for(int i=0; i<n; ++i){
        if(dp[i]==maxLen){
            ans+= cnt[i];
        }
       }
       return ans;
    }