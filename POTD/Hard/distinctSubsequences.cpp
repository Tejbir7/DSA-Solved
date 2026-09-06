#include<bits/stdc++.h>
using namespace std;
class Solution {
    int f(int i, int j,const string &s,const string &t,  vector<vector<int>> &dp){
        if(j< 0) return 1;
        if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int notTake = f(i-1, j, s, t, dp);
        int take = 0;
        if(s[i] == t[j]) take = f(i-1, j-1, s, t, dp);

        return dp[i][j] = take+ notTake;
        
    }
public:
    int numDistinct(const string &s,const string &t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n-1, m-1, s, t, dp);
    }
};