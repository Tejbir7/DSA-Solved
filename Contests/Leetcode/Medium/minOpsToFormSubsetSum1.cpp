#include<bits/stdc++.h>
using namespace std;
// class Solution {
//     int f(int i, int k, const vector<int>& nums, vector<vector<int>> &dp ){
//         if(i == 0){
//             if (k!= 0) return -1;
//         }
//         if(dp[i][k] != -1) return dp[i][k];

//         int take = 0;
//         int notTake = f(i-1, k, nums, dp);

//         take = 1 + min({ f(i-1, k - (nums[i]*2), nums, dp),
//                          f(i,   k - (nums[i]*2), nums, dp),
//                          f(i-1, k - (nums[i]/2), nums, dp),
//                          f(i,   k - (nums[i]/2), nums, dp),
//                         });

//         return dp[i][k] = min(take, notTake);        

//     }
// public:
//     int minOperations(vector<int>& nums, int sum) {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(sum+1,-1));
//         return f(n-1, sum, nums, dp);
//     }
// };
class Solution {
    int f(int i, int k, const vector<int>& nums, vector<vector<int>> &dp ){
        if(k == 0) return 0;
        if(i < 0 || k<0) return 1e9;

        if(dp[i][k] != -1) return dp[i][k];

        int take = 1e9;
        int notTake  = f(i-1, k, nums, dp);

        int x = nums[i];
        take = f(i-1, k-x, nums, dp);

        int curr = x*2;
        int ops = 1;
        while(curr <= k){
            take = min(take, ops+f(i-1, k-curr, nums, dp));
            curr *= 2;
            ++ops;
        }

        curr = x/2;
        ops = 1;
        while(curr >0){
            take = min(take, ops + f(i-1, k-curr, nums, dp));
            curr /= 2;
            ++ops;
        }

        return dp[i][k] = min(take, notTake);        

    }
public:
    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        int res = f(n-1, sum, nums, dp);
        return res >= 1e9 ? -1 : res ;
    }
};