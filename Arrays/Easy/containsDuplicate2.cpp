#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;
      
        for(int i=0; i<n; ++i){
           mpp[nums[i]].push_back(i);

             int m = mpp[nums[i]].size();
           if(m>1){
          
            if(abs(mpp[nums[i]][m-1]-mpp[nums[i]][m-2]) <=k) return true;
           }
        }
        return false;
    }
};

//optimisation
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
      
        for(int i=0; i<n; ++i){
            int j = -1;
           if(mpp.find(nums[i]) != mpp.end()){
               j = mpp[nums[i]];
           }

           if( j != -1 && abs(j-i) <= k) return true;

           mpp[nums[i]] = i;
        }
        return false;
    }
};

