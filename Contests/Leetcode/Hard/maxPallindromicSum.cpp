#include<bits/stdc++.h>
using namespace std; 
 long long getSum(vector<int>& nums) {
    int n = nums.size();
    vector<long long> maxSum(n,0);
    maxSum[0] = nums[0];

    for(int i=1; i<n; ++i){
        maxSum[i] = maxSum[i-1]+ nums[i];
    }
    unordered_map<int,int> mpp;
    for(int i=0; i<n; ++i){
        if(mpp.find(nums[i])==mpp.end()){
            mpp[nums[i]] = i;
        }
    }
    long long ans = 0;
    for(int j= n-1; j>=0; --j){
        if(mpp.find(nums[j])==mpp.end()) continue;

        int i = mpp[nums[j]];
        int it = j;
        bool flag = false;
        while(it>i){
            if(nums[it] == nums[i]){
                it--; i++;
            }else{
                flag = true;
                break;
            }
            if(flag = false){
                i = mpp[nums[j]];
                if(i-1!=-1){
                    ans = max( ans,maxSum[j]-maxSum[i-1]);
                }else{
                    ans = maxSum[i];
                }
            }
        }
    }
    return ans;
    }