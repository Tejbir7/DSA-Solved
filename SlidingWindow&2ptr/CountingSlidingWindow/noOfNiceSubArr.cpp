#include<bits/stdc++.h>
using namespace std;
int atMost(vector<int>& nums, int k){
    if(k<0) return 0;
    int n = nums.size();
    int l=0, r=0, odds =0, count = 0;
    while(r<n){
        //condn
        if(nums[r] % 2 != 0) ++odds;

        //baseCase
        while(l<=r && odds>k){
            if(nums[l]%2 != 0) --odds;
            ++l;
        }

        //update
        int noOfSubArr = r-l+1;
        count+= noOfSubArr;
        ++r;
    } 

    return count;
}
  int numberOfSubarrays(vector<int>& nums, int k) {
    int exact = atMost(nums,k) - atMost(nums,k-1);
    return exact;
        
    }