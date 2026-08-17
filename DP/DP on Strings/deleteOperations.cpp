#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string &s, string &t) {
        int m = s.size(), n = t.size();

        vector<int>prev(n+1,0);

        for(int i=1; i<=m; ++i){
            vector<int>curr(n+1);

            for(int j=1; j<=n; ++j){
                if(s[i-1]==t[j-1]) curr[j] = 1+ prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        int ans = m+n - (2*prev[n]);
        return ans;
    }
};