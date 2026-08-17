#include<bits/stdc++.h>
using namespace std;
bool isPallindrome(const string &t){
    int n = t.size();
    int i=0, j= n-1;
    while(i<j){
        if(t[i] != t[j]) return false;
        ++i; --j;
    }
    return true;
}
int f(int i, const string &s, vector<int>& dp){
    int n = s.size();
    if(i>=n) return 0;
    if(dp[i] != -1) return dp[i];

    string temp;
    int ans = INT_MAX;
    for(int k=i; k<n; ++k){
        temp.push_back(s[k]);
        if(isPallindrome(s)){
            ans = min(ans, 1+f(i+1,s,dp));
        }
    }

    return dp[i] = ans;
}
 int minCut(const string &s) {
    int n = s.size();
        vector<int> dp(n,-1);
        return f(0,s,dp);
    }