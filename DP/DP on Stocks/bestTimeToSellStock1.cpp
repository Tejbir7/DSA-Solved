#include<bits/stdc++.h>
using namespace std;
    int maxProfit(vector<int>& nums) {
        int n = nums.size();

        int mini = nums[0];
        int ans = 0;

        for (int i = 1; i < n; ++i) {

            mini = min(mini, nums[i]);
            int profit = nums[i] - mini;
            ans = max(ans, profit);
        }

        return ans;
    }