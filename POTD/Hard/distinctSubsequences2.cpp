#include<bits/stdc++.h>
using namespace std;
class Solution {
    static const int MOD = 1e9 + 7;

public:
    int distinctSubseqII(string s) {
        int tot = 0, dp[26]{};

        for (auto& t : s) {
            char c =  t - 'a';
            int add = (tot - dp[c] + MOD) % MOD;
            dp[c] = 1 + tot;
            tot = (dp[c] + add) % MOD;
        }

        return tot;
    }
};




//By Graph
class Solution {
    int MOD = 1e9 + 7;
    vector<int> memo;

    int dfs(int i, const string &s, vector<vector<int>> &adj) {
        if (memo[i] != -1) return memo[i];

        long long count = 1; // 1 represents the subsequence ending exactly at s[i]

        for (auto it : adj[i]) {
            count = (count + dfs(it, s, adj)) % MOD;
        }
        
        return memo[i] = count;
    }

public:
    int distinctSubseqII(const string &s) {
        int n = s.size();
        vector<vector<int>> adj(n);
        
        // Build edges ONLY to the first occurrence of each character after i
        // This naturally prevents duplicate subsequences without needing a hash set
        for (int i = 0; i < n; ++i) {
            vector<bool> seen(26, false);
            for (int j = i + 1; j < n; ++j) {
                if (!seen[s[j] - 'a']) {
                    seen[s[j] - 'a'] = true;
                    adj[i].push_back(j);
                }
            }
        }

        memo.assign(n, -1);
        long long total = 0;
        vector<bool> seen(26, false);

        // Start a path ONLY from the first occurrence of each character in the string
        for (int i = 0; i < n; ++i) {
            if (!seen[s[i] - 'a']) {
                seen[s[i] - 'a'] = true;
                total = (total + dfs(i, s, adj)) % MOD;
            }
        }

        return total;
    }
};