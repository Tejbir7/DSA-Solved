#include<bits/stdc++.h>
using namespace std;
int rec(vector<int>&dp,int n){
    if(n<=2) return n;
    if(dp[n]!= -1) return dp[n];

    return dp[n] = rec(dp,n-1)+ rec(dp, n-2);

}
 int climbStairs(int n) {
    vector<int>dp(n+1,-1);
    int ans = rec(dp,n);
    return ans;
    }

    //M2: Tabulation 
     int climbStairs(int n) {
         if(n<=2) return n;
        vector<int> dp(n+1);
        for(int i=0; i<=2; ++i) dp[i] = i;
        for(int i=3; i<=n; ++i){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    //M3 Space optimised 
     int climbStairs(int n) {
       if(n<= 2) return n;
        int prev2 = 1;
        int prev1 = 2;
        for(int i=3; i<=n; ++i){
            int curr = prev1+ prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }