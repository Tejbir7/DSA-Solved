#include<bits/stdc++.h>
using namespace std;
 string shortestCommonSupersequence(string &s, string&t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));

    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(s[i-1]== t[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i= m, j= n;
    string lcs;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            lcs.push_back(s[i-1]);
            --i; --j;
        }
        else if(dp[i-1][j]>=dp[i][j-1]) --i;
        else --j;
    }
    reverse(lcs.begin(), lcs.end());

    i=0; j=0;
    int k=0;
    string ans;
    while(i<m && j<n && k<lcs.size()){
        while(s[i]!= lcs[k]){
            ans.push_back(s[i]);
            ++i;
        }
        while(t[j]!= lcs[k]){
            ans.push_back(t[j]);
            ++j;
        }
        ans.push_back(lcs[k]);
        ++k; ++i; ++j;
    }
    while(k<lcs.size()) ans.push_back(lcs[k++]);
    while(i<m) ans.push_back(s[i++]);
    while(j<n) ans.push_back(t[j++]);

    return ans;
        
    }

    //better version
 string shortestCommonSupersequence(string &s, string&t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));

    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(s[i-1]== t[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i= m, j= n;
    string lcs;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            lcs.push_back(s[i-1]);
            --i; --j;
        }
        else if(dp[i-1][j]>=dp[i][j-1]) --i;
        else --j;
    }
    reverse(lcs.begin(), lcs.end());

    i=0; j=0;
    int k=0;
    string ans;
    for(char c: lcs){
        while(s[i]!= c) ans.push_back(s[i++]);
        while(t[j]!= c) ans.push_back(t[j++]);
        ans.push_back(c);
        ++i; ++j;
    }
    while(i<m) ans.push_back(s[i++]);
    while(j<n) ans.push_back(t[j++]);

    return ans;
    }

    //Another version build simultaneously 
     string shortestCommonSupersequence(string &s, string&t) {
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));

    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(s[i-1]== t[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int i= m, j= n;
    string ans;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            ans.push_back(s[i-1]);
            --i; --j;
        }
        else if(dp[i-1][j]>=dp[i][j-1]){
            ans.push_back(s[i--]);
        } 
        else{
            ans.push_back(t[j--]);
        } 
    }
    reverse(ans.begin(),ans.end());   
    return ans;
    }