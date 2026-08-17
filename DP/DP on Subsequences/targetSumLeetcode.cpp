 #include<bits/stdc++.h>
 using namespace std;

 //Recursive
 int dfs(int i, const vector<int>& nums, int sum, const int target) {
        if (i < 0)
            return sum == target;

            //add + subtract
        return dfs(i - 1, nums, sum - nums[i], target) +
               dfs(i - 1, nums, sum + nums[i], target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = dfs(n - 1, nums, 0, target);
        return ans;
    }

    //memoization
  int dfs(int i, const vector<int>& nums, int sum, const int target,vector<vector<int>>&dpPos, vector<vector<int>> &dpNeg) {
        if (i < 0) return sum == target;

            if(sum<0 && dpNeg[i][-sum]!= -1) return dpNeg[i][-sum];
            if(sum>0 && dpPos[i][sum]!= -1) return dpPos[i][sum];

            //add + subtract
            int ans = dfs(i - 1, nums, sum - nums[i], target,dpPos,dpNeg) +
               dfs(i - 1, nums, sum + nums[i], target, dpPos,dpNeg);
        
               if(sum>=0) return dpPos[i][sum] = ans;
               else return dpNeg[i][-sum] = ans;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
         int n = nums.size();
        int total = 0;
        for(int i=0; i<n; ++i) total+= nums[i];

        vector<vector<int>> dpPos(n, vector<int>(total+1,-1));
        vector<vector<int>> dpNeg(n, vector<int>(total+1,-1));
        int ans = dfs(n - 1, nums, 0, target,dpPos,dpNeg);
        return ans;
    }
 
