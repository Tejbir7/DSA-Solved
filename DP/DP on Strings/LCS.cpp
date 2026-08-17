#include<bits/stdc++.h>
using namespace std;
//Recurrence
int dfs(int i, int j, string &s , string &t){
    if(i<0 || j<0) return 0;

    if(s[i]==t[j]){
        return  1 + dfs(i-1,j-1,s,t);
    }
    return max(dfs(i,j-1,s,t), dfs(i-1,j,s,t));
}
int lcs(string s, string t){
    int n = s.size(), m = t.size();
    int lcs = dfs(n-1,m-1,s,t);
}

//Memoization
int dfs(int i, int j, string &s , string &t, vector<vector<int>> &dp){
    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    if(s[i]==t[j]){
        return dp[i][j] = 1 + dfs(i-1,j-1,s,t,dp);
    }
    return dp[i][j] = max(dfs(i,j-1,s,t,dp), dfs(i-1,j,s,t,dp));
}
int lcs(string s, string t){
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int>(m,-1));
    int Lcs = dfs(n-1,m-1,s,t,dp);
    return Lcs;
}

//Tabulation
//without dhifting of index 
int lcs(string s, string t){
     int m = s.size(), n = t.size();
    vector<vector<int>> dp(m, vector<int>(n,0));

   for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){

        if(s[i]==t[j]){
            if(i-1 >=0 && j-1 >=0) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = 1;

        }
        else{
            int choice1 = 0, choice2 = 0;
            if(i-1 >= 0) choice1 = dp[i-1][j];
            if(j-1 >= 0) choice2 = dp[i][j-1];
            dp[i][j] = max(choice1,choice2);
        }
           
}
}
return dp[m-1][n-1];
}

//shifting of index 
int lcs(string s, string t){
    int m = s.size();
    int n = t.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(s[i-1]== t[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

//space optimised 
int lcs(string s, string t){
    int m = s.size();
    int n = t.size();

    vector<int>prev(n+1,0);

    for(int i=1; i<=m; ++i){
        vector<int> curr(n+1);

        for(int j=1; j<=n; ++j){
            if(s[i-1]== t[j-1]) curr[j] = 1+ prev[j-1];
            else{
                curr[j] = max( prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }
    return prev[n];
}
