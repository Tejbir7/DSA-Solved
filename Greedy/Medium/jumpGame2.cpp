#include<bits/stdc++.h>
using namespace std;
    int f(int i,const int n,vector<int>&dp,const vector<int>& nums){
    if(i>=n-1) return 0;

    if(dp[i] != -1) return dp[i];
    const int INF = 1e9;
    int ans = INF;

    for(int j= i+1; j<= min(n-1, i+nums[i]); ++j){
         ans = min(ans, 1+ f(j,n,dp,nums));
    }
    return dp[i] = ans;
}

    int jump(const vector<int>& nums) {
          int n = nums.size();
    vector<int>dp(n, -1);
    return f(0,n,dp,nums);
    }

    //Tabulation
     int jump(const vector<int>& nums) {
                  int n = nums.size();
          vector<int> jumps(n, INT_MAX);
          jumps[n-1] = 0;

          for(int i=n-2; i>=0; --i){
            if(i + nums[i] >= n-1) jumps[i] = 1;
            else{
                int moreJumps = INT_MAX;
                for(int j=i+1; j<= min(n-1, i+nums[i]); ++j){
                    moreJumps = min(moreJumps,jumps[j]);
                }
                if(moreJumps != INT_MAX)
                jumps[i] = moreJumps+1;
            }
          }
          return jumps[0];
    }

    //Greedy, Range one
  int jump(const vector<int>& nums) {
          int jumps = 0, l=0, r= 0, n = nums.size();
        while(r< n-1){
            int farthest = 0;
            for(int i=l; i<=r; ++i){
                farthest = max(farthest, i+nums[i]);
            }
            l = r +1;
            r= farthest;
            ++jumps;
            if(farthest >= n-1) break;
        }
        return jumps;
    }