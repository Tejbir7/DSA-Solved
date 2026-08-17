#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, const vector<int> &nums, vector<vector<int>> &dp)
{
    if (i > j)
        return 0; //> no cuts left
    //== 1 cut remains

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for (int k = i; k <= j; ++k)
    {
        int cost = nums[j + 1] - nums[i - 1] + f(i, k - 1, nums, dp) + f(k + 1, j, nums, dp);
        ans = min(ans, cost);
    }
    return dp[i][j] = ans;
}

int minCost(int n, vector<int> &cuts)
{
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int sz = cuts.size();

    vector<vector<int>> dp(sz, vector<int>(sz, -1));
    return f(1, sz - 2, cuts, dp);
}
// Tabulation
int minCost(int n, vector<int> &cuts)
{
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    int sz = cuts.size();
    

    vector<vector<int>> dp(sz+1, vector<int>(sz+1, 0));
    for (int i = sz - 2; i >= 1; --i){
        for (int j = i; j <= sz-2; ++j){
             int ans = INT_MAX;
            for (int k = i; k <= j; ++k){               
                
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    ans = min(ans, cost);
            }
            dp[i][j] = ans;
        }
    }
    return dp[1][sz-2];
}
