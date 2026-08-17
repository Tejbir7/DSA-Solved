#include<bits/stdc++.h>
using namespace std;
  int atMost(vector<int>& nums, int k) {
    if(k<0) return 0;
      int n = nums.size();
    int l = 0, r = 0, count = 0, currSum = 0;
    while (r < n) {
        currSum += nums[r];

        while (currSum > k && l <= r) {
            currSum -= nums[l];
            l++;
        }

        int len = r-l+1;
        count+= len;     
        r++;
    }
    return count;
    }

     int numSubarraysWithSum(vector<int>& nums, int goal) {
        int exactly = atMost(nums,goal)-atMost(nums,goal-1);
        return exactly;
    }