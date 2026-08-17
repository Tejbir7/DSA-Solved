#include<bits/stdc++.h>
using namespace std;
//wt,value
int dfs(int i, int weight, vector<pair<int,int>>&nums, vector<vector<int>>& dp){

    if(i==0){
        if(nums[i].first <= weight) return nums[i].second;
        else return 0;
    }
    if(dp[i][weight]!= INT_MIN) return dp[i][weight];

    int notTake = 0;
    int Take = INT_MIN;

    notTake = dfs(i-1,weight,nums, dp);
    if(nums[i].first <= weight){
        Take = nums[i].second + dfs(i-1,weight-nums[i].first,nums,dp);
    }

    return dp[i][weight] = max(Take,notTake);
}

int robbersDay(vector<pair<int,int>>&nums, int wt){
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(wt+1,INT_MIN));
    int ans = dfs(n-1,wt,nums,dp);
    return ans;
}

//Tabulation
//wt,value
int robbersDay(vector<pair<int,int>>&nums, int wt){
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(wt+1,0));

   for(int w = nums[0].first; w <= wt; w++) dp[0][w] = nums[0].second;

    for(int i=1; i<n; ++i){
        for(int currWt = 0; currWt<= wt; ++currWt){
            int notTake = dp[i-1][currWt];
            int Take = 0;
            if(currWt- nums[i].first >=0 ){
                Take = nums[i].second + dp[i-1][currWt- nums[i].first];
            }
            dp[i][currWt] = max(Take,notTake);
        }
    }
    
    return dp[n-1][wt];
}

//2 arr space opptimised

int robbersDay(vector<pair<int,int>>&nums, int wt){
    int n = nums.size();
    vector<int> prev(wt+1,0);

   for(int w = nums[0].first; w <= wt; w++) prev[w] = nums[0].second;

    for(int i=1; i<n; ++i){
        vector<int> temp(wt+1,0);
        for(int currWt = 0; currWt<= wt; ++currWt){
            int notTake = prev[currWt];
            int Take = 0;
            if(currWt- nums[i].first >=0 ){
                Take = nums[i].second + prev[currWt- nums[i].first];
            }
            temp[currWt] = max(Take,notTake);
        }
        prev = temp;
    }
    
    return prev[wt];
}

// single Arr optimised
int robbersDay(vector<pair<int,int>>&nums, int wt){
    int n = nums.size();
    vector<int> prev(wt+1,0);

   for(int w = nums[0].first; w <= wt; w++) prev[w] = nums[0].second;

    for(int i=1; i<n; ++i){
        for(int currWt = wt; currWt>=0; --currWt){
            int notTake = prev[currWt];
            int Take = 0;
            if(currWt- nums[i].first >=0 ){
                Take = nums[i].second + prev[currWt- nums[i].first];
            }
            prev[currWt] = max(Take,notTake);
        }
    }
    
    return prev[wt];
}

