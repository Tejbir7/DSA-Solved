#include<bits/stdc++.h>
using namespace std;
int f(vector<vector<int>>& nums, vector<vector<int>> &dp, int day, int last ){
    if(day==0){
        int maxi = 0;
        for(int i=0; i<3; ++i){
            if(i==last) continue;
            maxi = max(maxi, nums[0][i]);
        }
        return maxi;
    }
    if(dp[day][last] != -1) return dp[day][last];
    int maxi = 0;
    for(int i=0; i<3; ++i){
        if(i==last) continue;
        int points = nums[day][i]+ f(nums,dp,day-1,i);
        maxi = max(maxi,points);
    }
    return dp[day][last] = maxi;
}
  int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int>(4,-1));
        int ans = f(mat,dp,n-1,3);
        return ans;
        
    }

    //better
    int maximumPoints(vector<vector<int>>&nums){
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(3));
       for(int i=0;i<3;++i){
      dp[0][i] = nums[0][i];
       }

      
        for(int day=1; day<n; ++day){
            for(int task =0; task<3; ++task){
                
                int maxi =0;
                for(int prev=0; prev<3; ++prev){
                    if(prev==task) continue;
                    int points = nums[day][task] + dp[day-1][prev];
                    maxi = max(maxi,points);
                    dp[day][task] = maxi;
                }
            }
        }
        return max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
            }

            //best
               int maximumPoints(vector<vector<int>>&nums){
        int n = nums.size();
        vector<int> prev(3);
       for(int i=0;i<3;++i){
          prev[i] = nums[0][i];
       }

      
        for(int day=1; day<n; ++day){
            vector<int> temp(3);
            for(int task =0; task<3; ++task){
                int maxi =0;
                for(int prevTask=0; prevTask<3; ++prevTask){
                    if(prevTask==task) continue;
                    int points = nums[day][task] + prev[prevTask];
                    maxi = max(maxi,points);
                       temp[task] = maxi;
                }
            }
             prev = temp;
        }
        return max({prev[0],prev[1],prev[2]});
            }
