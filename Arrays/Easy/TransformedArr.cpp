#include<iostream>
#include<vector>
using namespace std;
 vector<int> constructTransformedArray(vector<int>& nums) {
    int n = nums.size();
    if(!n) return {};
    vector<int>result(n,0);
    for(int i = 0;i<n;++i){
        if(nums[i]==0) continue;
        else if (nums[i]>0){
            int shift = nums[i];
            result[i] = nums[(i+ shift)%n];
        }else{
            int shift = abs(nums[i])%n;
            int idx = i-shift;
            if(idx<0) idx+=n;
            result[i] = nums[idx];
        }
    }
        return result;
    }
    //best
    vector<int> constructTransformedArray(vector<int>& nums) {
    int n = nums.size();
    if(!n) return {};
    vector<int>result(n,0);
    for(int i = 0;i<n;++i){
        if(nums[i]==0) continue;
        else {
            int shift = nums[i];
            result[i] = nums[((i+shift)%n+n)%n];
        }
    }
        return result;
    }