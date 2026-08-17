#include<iostream>
#include<vector>
using namespace std;
   long long maxSumTrionic(vector<int>& nums) {
    long long sum = 0;
    int n = nums.size();
    if(!n) return sum;
    int right = 0;
    

        
    }
     bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(!n) return false;

        int right = 0;
        while(right<n-1){
              if(nums[right+1]>nums[right]) ++right ;
              else break;
        }
       if(right==n-1 || right ==0) return false;
       while(right<n-1){
        if(nums[right+1]<nums[right]) ++right;
        else break;
       }
       if(right == n-1) return false;
        while(right<n-1){
              if(nums[right+1]>nums[right]) ++right ;
              else break;
        }
        if(right==n-1) return true;
        else return false;
    }