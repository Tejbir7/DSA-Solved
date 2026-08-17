#include<iostream>
#include<vector>
using namespace std;
 int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if(!n) return 0;
    int prefix =1, suffix = 1;
    int maxi = INT_MIN;
    for(int i=0;i<n;++i){
        if(suffix==0) suffix = 1;
        if(prefix ==0) prefix =1;

        prefix *= nums[i];
        suffix *= nums[n-i-1];
        maxi = max(maxi, max(suffix,prefix));
        
    }
        return maxi;
    }