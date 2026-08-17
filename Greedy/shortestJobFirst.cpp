#include<bits/stdc++.h>
using namespace std;
  int solve(vector<int>& nums) {
        sort(nums.begin(), nums.end());
         int n = nums.size();
        vector<int> temp(n-1);

        int sum = 0;

        for(int i=0; i<n-1; ++i){
            sum+=nums[i];
            temp[i] = sum;
        }
        sum = 0;

        for(int i=0; i<n-1; ++i) sum+= temp[i];
        return sum/n;
    }

    //Further optmisation
      int solve(vector<int>& nums) {
        sort(nums.begin(), nums.end());
         int n = nums.size();
     
        int sum = 0, ans = 0;

        for(int i=0; i<n-1; ++i){
            sum+=nums[i];
            ans+= sum;
        }
      
        return ans/n;
    }