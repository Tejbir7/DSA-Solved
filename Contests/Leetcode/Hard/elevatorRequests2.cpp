#include<bits/stdc++.h>
using namespace std;
 long long elevatorRequests(int n, int start, vector<int>& nums) {
        int t = nums.size();
        vector<int> vis(t,0);
        int ans = 0;

     //   unordered_map<int,int> mpp;

        int minPenalty= INT_MAX, idx = -1;
        for(int i=0; i<t; ++i){
            if(abs(start-nums[i]) < minPenalty){
            minPenalty = abs(start-nums[i]);
            idx = i;
            }
        }
        vis[idx] = 1;
      //  mpp[start] = minPenalty;
        ans += minPenalty;

        for(int i=0; i<n; ++i){
            int iDx = -1;
            int mini = INT_MAX;
            for(int j=0; j<n; ++j){
                if(j==i) continue;
                if(vis[j] == 1) continue;

                if(mini > abs(nums[i]-nums[j])){
                    mini = abs(nums[i]-nums[j]);
                    iDx = j;
                }

            }
            vis[idx] = 1;
            minPenalty += mini;
            ans += minPenalty;
       //     mpp[nums[i]] = mini;
        }
        return ans;
    }