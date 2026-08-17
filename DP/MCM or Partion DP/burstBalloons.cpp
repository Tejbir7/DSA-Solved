#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, const int n, vector<int>& nums,   vector<vector<int>> &dp) {
        if (i > j)
            return 0;

            if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        for (int k = i; k <= j; ++k) {

            int coins = (nums[k] * nums[i-1] * nums[j+1]) +
                        f(i, k - 1, n, nums, dp) + f(k + 1, j, n, nums, dp);
            ans = max(ans, coins);
        }

        return dp[i][j] = ans;
    }


    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;

        temp.push_back(1);
        for (int i = 0; i < n; ++i)
        temp.push_back(nums[i]);
        temp.push_back(1);

        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return f(1, n, n, temp, dp);
    }