#include<bits/stdc++.h>
using namespace std; 

int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;

        for(int i=0; i<n; ++i){
            int start=i+k;
            if(start>n-1) continue;
            for(int j=start; j<n; ++j){
                maxi = max(maxi, nums[i]+nums[j]);
            }
        }
        return maxi;
    }

    // best 
 int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxSofar (n,0);
        int maxi = INT_MIN;
      for(int i=0; i<n; ++i){
        maxi = max(maxi, nums[i]);
        maxSofar[i] = maxi;
      }
        int ans = INT_MIN;
        for(int j=0; j<n; ++j){
            int i= j-k;
            if(i>n-1 || i<0) continue;
            ans = max(ans, maxSofar[i]+nums[j]);
        }

        return ans; 
    }