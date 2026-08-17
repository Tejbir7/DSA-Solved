#include<bits/stdc++.h>
using namespace std;
void helper(set<string>&ans, string &s, int i, int maxi){
    string temp;
    while(i>0 && maxi!=0){
        temp.push_back(s[i-1]);
        --i; --maxi;
    }
    reverse(temp.begin(), temp.end());
    ans.insert(temp);
    return;
}

vector<string> lcSubstring(string &s, string &t){
    int m = s.size(), n = t.size();
    int maxi = 0;
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));

    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
                maxi = max(maxi,dp[i][j]);
            }
        }
    }
    set<string> ans;
    vector<string>temp;

    for(int i=1; i<m+1; ++i){
        for(int j=1; j<n+1; ++j){
            if(dp[i][j]== maxi){
                //helper(ans,s,i,maxi);  //Double work 
                //simple
                ans.insert(s.substr(i - maxi, maxi));
            } 
        }
    }
    for(auto &it : ans){
        temp.push_back(it);
    }
    return temp;
}

