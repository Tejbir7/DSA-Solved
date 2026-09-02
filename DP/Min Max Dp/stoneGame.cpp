#include<bits/stdc++.h>
using namespace std;

class Solution {
    int f(int i, int j, vector<int>&nums){
        if(i>j ) return 0;
        int takeLeft = nums[i] - f(i+1, j, nums);
        int takeRight = nums[j] - f(i, j-1, nums);

        return max(takeLeft, takeRight);
    }
public:
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        return f(0, n-1, nums) >0;
    }
};

//Memoized
class Solution {
    int f(int i, int j, vector<int>&nums, vector<vector<int>> &dp){
        if(i>j ) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int takeLeft = nums[i] - f(i+1, j, nums, dp);
        int takeRight = nums[j] - f(i, j-1, nums, dp);

        return dp[i][j] = max(takeLeft, takeRight);
    }
public:
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n/2, vector<int>(n/2 , -1));
        return f(0, n-1, nums, dp) >0;
    }
};