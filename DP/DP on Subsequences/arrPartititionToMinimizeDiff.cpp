 #include<bits/stdc++.h>
 using namespace std;

 void dfs(int idx, int end, vector<vector<int>>&subsets, vector<int>&nums, int sum, int count){
    if(idx==end+1){ 
    subsets[count].push_back(sum);
    return;
    }
    //dont pick
    dfs(idx+1, end,subsets,nums, sum, count);

    //pick
    dfs(idx+1, end,subsets,nums, sum+nums[idx], count+1);
 }
 int lowerBound(vector<int>&nums, int target){
   int low = 0;
   int high = nums.size()-1;

   int idx = high+1;

   while(low<=high){
      int mid = low + ((high-low)/2);
      if(nums[mid]>=target){
         idx = mid;
         high = mid-1;
      }else low = mid+1;
   }
   return idx;
 }

  int minimumDifference(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for(int i=0; i<n; ++i) totalSum+= nums[i];

    int m = n/2;
    vector<vector<int>> nums1(m+1), nums2(m+1);
     dfs(0,m-1,nums1,nums,0,0); //forms 1st
     dfs(m,n-1,nums2,nums,0,0);  //forms 2nd

     for (int i = 0; i <= m; i++) sort(nums2[i].begin(), nums2[i].end());
     
     int optimalPartition = totalSum/2;

     int mini = INT_MAX;
    for(int i=0; i<=m; ++i){
      for(int sum1: nums1[i]){
         int target = optimalPartition - sum1;
         
         int idx = lowerBound(nums2[m-i], target);

         //sum2 = nums2[m-i][idx] or nums2[m-i][idx-1]
         if(idx< nums2[m-i].size()){
            mini = min(mini, abs(totalSum - 2*(sum1 + nums2[m-i][idx])));
         }
         if(idx>0){
              mini = min(mini, abs(totalSum - 2*(sum1 + nums2[m-i][idx-1])));
         }
      }
    }
      return mini;
   }
   //Derivation: abs(totalSum - (sum1+sum2)) - (sum1 + sum2) 
         //      = abs(totalSum - 2*(sum1+sum2))