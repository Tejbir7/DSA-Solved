#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
    void dfs(int idx,const vector<int>& nums, int n,int sum, vector<int>& ans){
    if(idx==n){
        ans.push_back(sum);
        return;
    }
    
    //take
    dfs(idx+1,nums,n,sum+nums[idx],ans);

    //dont Take
    dfs(idx+1,nums,n,sum,ans);

}
vector<int>generateSubsequenceSum(int start, int end , vector<int>& nums){
    vector<int>ans;
    dfs(start,nums,end+1,0,ans);
    return ans; 
}
int lowerBound(int target, const vector<int> &nums){
    int low = 0;
    int high = nums.size()-1;

    int ans = nums.size();
    while(low<=high){
        int mid = low + ((high-low)/2);

        if(nums[mid] >= target){
            ans = mid; 
            high = mid-1;
        }else{
            low = mid+1;
        }

    }
    return ans;    
}

public:
    int minAbsDifference(vector<int>& nums, int goal) {
         int n = nums.size();
    //Step 1: Generated Subsequences
    vector<int> nums1 = generateSubsequenceSum(0,n/2,nums);
    vector<int>nums2 = generateSubsequenceSum(n/2+1,n-1,nums);

    //Step 2: sort 2nd arr
    sort(nums2.begin(),nums2.end());

    //Step 3: Find the Absolute difference
    int ans = INT_MAX;
    for(int sum1 : nums1){
        int target = goal- sum1;
        if(target==0) return 0;

        int idx = lowerBound(target,nums2);
         if (idx < nums2.size()) {
            ans = min(ans, abs(goal - (sum1 + nums2[idx])));
        }   
        if (idx > 0) {
                ans = min(ans, abs(goal - (sum1 + nums2[idx - 1])));
            }
    }
    return ans;
        
    }
};