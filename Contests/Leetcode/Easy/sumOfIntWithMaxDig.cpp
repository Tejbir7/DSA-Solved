#include<bits/stdc++.h>
using namespace std; 
 int maxDigitRange(vector<int>& nums) {
    int n = nums.size();
    vector<int>range(n,0);
    int large = INT_MIN;
    

    for(int i=0; i<n; ++i){
        string temp = to_string(nums[i]);
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int x: temp){
            maxi = max(maxi, x-'0');
            mini = min(mini, x-'0');
        }
        range[i] = maxi-mini;
        large = max(large,range[i]);
    }
    int sum = 0;
    for(int i=0; i<n; ++i){
        if(range[i]==large) sum+= nums[i];
    }
        return sum;
    }