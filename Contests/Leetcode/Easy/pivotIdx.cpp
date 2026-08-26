#include<bits/stdc++.h>
using namespace std;
 int pivotIndex(vector<int>& nums) {
        int n = nums.size();
       vector<int> leftSum(n,0);
       vector<int> rightSum(n,0);
       for(int i=1; i<n; ++i) leftSum[i] += nums[i-1];
       for(int j=n-2; j>=0; --j) rightSum[j] += nums[j+1];

       for(int i=0; i<n; ++i){
        if(leftSum[i]==rightSum[i]) return i;
       }
       return -1;
    }

 int pivotIndex(vector<int>& nums) {
        int n = nums.size();
     
       for(int i=1; i<n; ++i) nums[i] += nums[i-1];
       for(int j=n-2; j>=0; --j) nums[j] -= nums[j+1];

       for(int i=0; i<n; ++i){
        if(nums[i]==0) return i;
       }
       return -1;
    }