#include<bits/stdc++.h>
using namespace std;
bool dfs(int i, int j, const string &s,const string &t, vector<vector<int>>&dp){
    if(j==0 && i!=0) return false;
    if(i==0 && j==0) return true;
    if(i==0){
        for(int k= j-1; k>=0; k--) if(t[k] != '*') return false;
        return true;
    }

    if(dp[i][j]!= -1) return dp[i][j];

    if(s[i-1]==t[j-1] || t[j-1]== '?') return dp[i][j] = dfs(i-1,j-1,s,t,dp);

    else{
        // keep Taking or Take nothing
        if(t[j-1] == '*') return dp[i][j] = dfs(i-1,j,s,t,dp) || dfs(i,j-1,s,t,dp);
    }
    
    return dp[i][j] = false;
}
  bool isMatch(string &s, string &t) {
        int m = s.size(), n = t.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return dfs(m,n,s,t,dp);
    }