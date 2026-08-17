#include<bits/stdc++.h>
using namespace std;

//Recurrence
int dfs(int i, int prev, vector<int>&nums){
    if(i>=nums.size()) return 0;

    int dontPick = dfs(i+1, prev, nums);
    int pick = 0;

    if(prev == -1 || nums[i]> nums[prev]){
         pick = 1 + dfs(i+1, i, nums);
    }
    
    return max(pick, dontPick);
}
int lis(vector<int>&nums){
    return dfs(0,-1,nums);
}

//dp 
int dfs(int i, int prev, vector<int>&nums, vector<vector<int>>&dp){
    if(i>=nums.size()) return 0;

    if(dp[i][prev+1] != -1) return dp[i][prev+1];

    int dontPick = dfs(i+1, prev, nums, dp);
    int pick = 0;

    if(prev == -1 || nums[i]> nums[prev]){
         pick = 1 + dfs(i+1, i, nums, dp);
    }
    
    return dp[i][prev+1] = max(pick, dontPick);
}
int lis(vector<int>&nums){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return dfs(0,-1,nums, dp);
}

//Tabulation
int lis(vector<int>&nums){
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for(int i=n-1; i>=0; --i){
        for(int prev = i-1; prev>=-1; --prev){

            int dontPick = dp[i+1][prev+1];
            int pick = 0;
            if(prev == -1 || nums[i]> nums[prev]) pick = 1 + dp[i+1][i+1];

            dp[i][prev+1] = max(pick, dontPick);
        }
    }
    return dp[0][0];
}

//space optimisation
int lis(vector<int>&nums){
    int n = nums.size();
    vector<int> next(n+1,0), curr(n+1);
    
    for(int i=n-1; i>=0; --i){
        for(int prev = i-1; prev>=-1; --prev){

            int dontPick = next[prev+1];
            int pick = 0;
            if(prev == -1 || nums[i]> nums[prev]) pick = 1 + next[i+1];

            curr[prev+1] = max(pick, dontPick);
        }
        swap(curr, next);
    }
    return next[0];
}

//space opt 2
int lis(vector<int>&nums){
    int n = nums.size();
    vector<int> dp(n, 1);
    
    int maxLen = 0;

    for(int i=0; i<=n-1; ++i){
        for(int prev = 0; prev<i; ++prev){
            if(nums[i]> nums[prev]){
                dp[i] = max(dp[i], 1+dp[prev]);
               
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

//For Printing LIS
vector<int> lisPrint(vector<int>&nums){
    int n = nums.size();

    vector<int> dp(n, 1);
    vector<int> hash(n);

    int maxLen = 1;
    int lastIdx = 0;

    for(int i=0; i<n; ++i){
        hash[i] = i;
        for(int prev = 0; prev<i; ++prev){
            if(nums[i]> nums[prev] && dp[i] < 1 + dp[prev]){
                dp[i] = 1+dp[prev];
                hash[i] = prev;
            }
        }
        if(maxLen < dp[i]){
        maxLen = max(maxLen, dp[i]);
        lastIdx = i;
        }
    }

    vector<int> temp(maxLen);


    while(maxLen){
        temp[maxLen-1] = nums[lastIdx];
        lastIdx = hash[lastIdx];
        --maxLen;
    }

    return temp;
}

//Finding len in N log N
int lcs(vector<int>&nums){
       int n = nums.size();
   vector<int> temp;
   temp.push_back(nums[0]);
   for(int i=1; i<n; ++i){
    if(nums[i]> temp.back()){
        temp.push_back(nums[i]);
    }else{
        int idx = lower_bound(temp.begin(), temp.end(), nums[i])- temp.begin();
        temp[idx] = nums[i];
    }
   }
   return temp.size();

}

