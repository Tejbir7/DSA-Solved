#include<bits/stdc++.h>
using namespace std;

//Both these solutions not preferred here due to unoptimal
//Recurrence
string dfs(int i, int j, string &s, string &t){
    if(i<0 || j<0) return "";

    if(s[i]==t[j]){
        return dfs(i-1,j-1,s,t) + s[i];
    }
         string t1 = dfs(i,j-1,s,t);
         string t2 = dfs(i-1,j,s,t);
         return (t1.size() >= t2.size()) ? t1 : t2;
  
}

string lcs(string &s, string&t){

    int m = s.size(), n = t.size();
    return dfs(m-1,n-1,s,t);
}

//Memoization
string dfs(int i, int j, string &s, string &t, vector<vector<string>> &dp){
    if(i<0 || j<0) return "";
    if(dp[i][j] != "-1") return dp[i][j];

    if(s[i]==t[j]){
        return dp[i][j] = dfs(i-1,j-1,s,t) + s[i];
    }
         string t1 = dfs(i,j-1,s,t,dp);
         string t2 = dfs(i-1,j,s,t,dp);
         return dp[i][j] = (t1.size() >= t2.size()) ? t1 : t2;
  
}

string lcs(string &s, string&t){

    int m = s.size(), n = t.size();
    vector<vector<string>> dp(m,vector<string>(n, "-1"));
    return dfs(m-1,n-1,s,t, dp);
}

//Backtracking over the dp arr is preferred
// But not for the memoization but tabulation as some states may not be computed, so if not computed you have to do dfs again from that pt



// int dfs(int i, int j, string &s , string &t, vector<vector<int>> &dp){
//     if(i==0 || j==0) return 0;

//     if(dp[i][j] != -1) return dp[i][j];
//     if(s[i-1]==t[j-1]){
//         return dp[i][j] = 1 + dfs(i-1,j-1,s,t,dp);
//     }
//     return dp[i][j] = max(dfs(i,j-1,s,t,dp), dfs(i-1,j,s,t,dp));
// }

// string lcs(string &s, string &t){
//      int m = s.size(), n = t.size();

//     vector<vector<int>> dp(m+1, vector<int>(n+1,-1));
//     int Lcs = dfs(m,n,s,t,dp);

//     string ans(Lcs, ' ');

//     int i=m, j= n;
//     Lcs = Lcs-1;
 
//     while(i>0 && j>0){
//         if(s[i-1]== t[j-1]){
//             ans[Lcs--] = s[i-1];
//             i-= 1; 
//             j-=1;
//         }
//          else if(dp[i-1][j]>= dp[i][j-1]) i-=1;

//             else j-=1;
//     }
//     return ans;
// }

//shifting of index 
string lcs(string s, string t){
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

    int sz = dp[m][n];
        string ans(sz, ' ');
        --sz;

    int i=m, j= n;
 
    while(i>0 && j>0){
        if(s[i-1]== t[j-1]){
            ans[sz--] = s[i-1];
            --i; 
            --j;
        }
         else if(dp[i-1][j]>= dp[i][j-1]) --i;

            else --j;
    }
    return ans;
 
}