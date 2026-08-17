#include<bits/stdc++.h>
using namespace std;
//inefficient
void dfs(int i, int &ans, string temp, const string&s, const string &t){
    if(temp == t){
    ans++;
    return;
}

    if(i>= s.size()) return;
    //take
    dfs(i+1,ans,temp+s[i],s,t);
    //notTake
    dfs(i+1,ans,temp,s,t);  
  
}
  int numDistinct(string &s, string &t) {
        int m = s.size(), n = t.size();
        int ans = 0;
        string temp;
        dfs(0,ans,temp,s,t);
        return ans;
    }

    //better
  int dfs(int i, int j, const string& s, const string& t,
            vector<vector<int>>& dp) {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        if (s[i] == t[j]) return dp[i][j] =  dfs(i - 1, j - 1, s, t, dp) + dfs(i - 1, j, s, t, dp);
        return dp[i][j] = dfs(i - 1, j, s, t, dp);
    }

    int numDistinct(string& s, string& t) {
        int m = s.size(), n = t.size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dfs(m - 1, n - 1, s, t, dp);
    }

    //Tabulation
     int numDistinct(string& s, string& t) {
              int m = s.size(), n = t.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=0; i<=m; ++i) dp[i][0] = 1;

        for(int i=1; i<=m; ++i){
            for(int j=1; j<= min(i,n); ++j){
                if(s[i-1]== t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];                
            }
        }
        return dp[m][n];
    }
    //space optimisation
     int numDistinct(string& s, string& t) {
              int m = s.size(), n = t.size();
              using tt = unsigned int;
        vector<tt> prev(n+1,0);

        prev[0] = 1;

        for(int i=1; i<=m; ++i){
            vector<tt>curr(n+1);
            curr[0] = 1;
            
            for(int j=1; j<= min(i,n); ++j){
                if(s[i-1]== t[j-1]) curr[j] = prev[j-1] + prev[j];
                else curr[j] = prev[j];                
            }
            prev = curr;
            prev[0] = 1;
        }
        return prev[n];
    }