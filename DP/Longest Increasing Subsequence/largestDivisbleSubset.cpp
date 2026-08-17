#include<bits/stdc++.h>
using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n = nums.size();
      sort(nums.begin(), nums.end());

      vector<int> dp(n,1), hash(n);
      int maxLen = 0, lastIdx = 0;

      for(int i=0; i<n; ++i){
        hash[i] = i;
        for(int prev = 0; prev<i; ++prev){

            if(nums[i]% nums[prev] ==0 && dp[i]< 1+ dp[prev]){
                dp[i] = 1+ dp[prev];
                hash[i] = prev;
            }
        }
        if(maxLen< dp[i]){
            maxLen = dp[i];
            lastIdx = i;
        }
      }

      vector<int> temp(maxLen);

      while(maxLen){
        temp[maxLen-1] = nums[lastIdx];
        lastIdx = hash[lastIdx];
        --maxLen;
      }

      return temp;
    }