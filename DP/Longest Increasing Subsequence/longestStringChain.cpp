#include<bits/stdc++.h>
using namespace std;
bool areRelated(string& s, string& t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;
        bool once = false;
        while (i < m && j < n) {
            if (s[i] != t[j]) {
                if (!once) {
                    ++j; // t is bigger, its words[i]
                    once = true;
                } else
                    return false;

            } else {
                ++i;
                ++j;
            }
        }
        return true;
    }


    int longestStrChain(vector<string>& words) {
        int n = words.size();
sort(words.begin(), words.end(),
     [](const string &a, const string &b){
         return a.size() < b.size();
     });
        vector<int> dp(n, 1);
        int maxLen = 1;

        for (int i = 0; i < n; ++i) {
            for (int prev = 0; prev < i; ++prev) {
                if (words[i].size() != words[prev].size() + 1)
                    continue;
                if (areRelated(words[prev], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }
            if (maxLen < dp[i])
                maxLen = dp[i];
        }
        return maxLen;
    }