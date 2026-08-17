#include<iostream>
#include<vector>
using namespace std;
  int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    if(!n) return 0;
    int l =0, r=0;
    int maxlen = 0, zeroCount = 0;
    while(r<n){
        if(nums[r]==0) ++zeroCount;
        while (zeroCount > k) {
            if (nums[l] == 0) zeroCount--;
            l++;
        }
        maxlen = max(maxlen,r-l+1);
        ++r;
    }
    return maxlen;
    }
    int optimal(vector<int> &nums, int k){
        int n = nums.size();
        if(!n) return 0;
        int l = 0, r= 0, maxlen=0, zeroes =0;
        while(r<n){
            if(nums[r]==0) ++zeroes;
            if(zeroes>k){
                if(nums[l]==0) --zeroes;
                ++l;
            }
            if(zeroes<=k){
                maxlen = max(maxlen,r-l+1);
              
            }
              ++r;
        }
        return maxlen;
    }
      int main(){
     vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        int k=3;
        int maxii = optimal(nums,k);
        cout << maxii<< endl;
        return 0;
    }