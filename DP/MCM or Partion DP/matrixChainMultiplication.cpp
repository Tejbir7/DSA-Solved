#include<bits/stdc++.h>
using namespace std;
	int f(int i, int j, const vector<int>&nums, vector<vector<int>> & dp) {
		if (i == j)
			return dp[i][j] = 0;
		
		if (dp[i][j] != -1)
			return dp[i][j];
		
		long long mini = LLONG_MAX;
		
		for (int k = i; k<j; ++k) {
			long long steps = 0;
			steps = 1LL * (nums[i - 1] * nums[k] * nums[j]) + f(i, k, nums, dp) + f(k + 1, j, nums, dp);
			mini = min(mini, steps);
		}
		return dp[i][j] = (int)mini;
	}

	int matrixMultiplication(vector<int> &nums) {
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n + 1, 0));
		
		for (int i = n - 1; i >= 1; --i) {
			for (int j = i + 1; j<n; ++j) {
				int mini = INT_MAX;
				
				for (int k = i; k<j; ++k) {
					
					int steps = (nums[i - 1] * nums[k] * nums[j]) + dp[i][k] + dp[k + 1][j];
					
					mini = min(mini, steps);
				}
				dp[i][j] = mini;
			}
		}
		return dp[1][n - 1];
		
	}