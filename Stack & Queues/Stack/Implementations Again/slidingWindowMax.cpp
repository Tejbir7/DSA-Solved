#include<iostream>
#include<queue>
#include<climits>
#include<vector>
#include<deque>
#include<utility>
using namespace std;

//Extreme naive brute force solution
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, right = k-1;
    vector<int> ans;
    while(right<n){
        int maxi = INT_MIN;
        for(int i= left; i<=right; ++i){
            if(maxi<nums[i]) maxi = nums[i];
        }
        ans.push_back(maxi);
        ++right; ++left;
    }
      return ans;
    }

    //Optimal using monotonicity and deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        for(int i = 0 ; i<n ; ++i){
            //remove out of window
            if(!dq.empty() && dq.front() <= i-k) dq.pop_front();
            //maintain decreasing
            while(!dq.empty() && nums[i]>=nums[dq.back()]) dq.pop_back();

            dq.emplace_back(i);
            
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }