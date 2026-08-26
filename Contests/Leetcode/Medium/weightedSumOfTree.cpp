#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ht = 0;

    struct tree {
        int val;
        int invDep;
    };

    vector<tree> trees;

    void dfs(int node, int depth, const vector<vector<int>>& adj,
             const vector<int>& nums) {
        trees.push_back({nums[node], depth});
        ht = max(ht, depth);

        for (auto child : adj[node]) {

            dfs(child, depth + 1, adj, nums);
        }
    }

public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        dfs(0, 1, adj, nums);
        using ll = long long;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll wt = 1LL * trees[i].val * (ht - trees[i].invDep + 1);
            ans += wt;
        }
        return ans;
    }
};