#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
//Wrong approach, cant use sliding window here
//     int maxii(vector<int>nums){
//     int maxi = INT_MIN;
//     for(int i:nums){
//         if(i>maxi) maxi = i;
//     }
//     return maxi;
// }

//     int longestBalanced(vector<int>& nums) {
//           int n = nums.size();
//     if(!n) return 0;
//     int odd = 0, even = 0;
//     vector<int> hash(maxii(nums)+1,0);
//     int left = 0, right = 0;
//     while(right<n){
//         hash[nums[right]] += 1;
//         if(nums[right]%2==0 && hash[nums[right]]<=1) ++even;
//         else ++odd;
//         ++right;
//     }
//     right = n-1;
//     while(odd!=even){
//         if(even > odd){
//             if(nums[right]%2==0){
//                 hash[nums[right]]-= 1;
//                 --right;
//             }
//             else if(nums[left]%2==0){
//                 hash[nums[left]]-=1;
//                 ++left;
//             }
//         }else{
//                if(nums[right]%2==1){
//                 hash[nums[right]]-= 1;
//                 --right;
//             }
//             else if(nums[left]%2==1){
//                 hash[nums[left]]-=1;
//                 ++left;
//             }
//         }
//     }
//       return right-left+1; 
//     }


    int longestBalanced(vector<int>& nums) {
             int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> evenSet;
            unordered_set<int> oddSet;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    evenSet.insert(nums[j]);
                else
                    oddSet.insert(nums[j]);

                if (evenSet.size() == oddSet.size()) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
