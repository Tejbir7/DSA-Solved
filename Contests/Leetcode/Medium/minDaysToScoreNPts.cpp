#include<bits/stdc++.h>
using namespace std;
class Solution {
    int f(int k, vector<int> &dp){
        if(k == 0) return 0;
        if(dp[k] != -1) return dp[k];
        
        int ans = INT_MAX;
        for(int p=1; ; ++p){
            int sum = p * (p +1) / 2;
            if(sum > k) break;
            
            if(sum == k) ans = min(ans, p);
            else{
                ans = min(ans, f(k - sum, dp) + 1 + p);
            }
        }

        return dp[k] = ans;
    }
public:
    int minDays(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};