#include<bits/stdc++.h>
using namespace std;
int maxFrequency(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());
    long long windowSum =0;
    int l=0;
    int best =1;
    while(k<0){
        if(nums[i]<nums[j]){
            while(nums[i]==nums[j]){
                nums[i]++;
                k--;
            }
        } else{
            while(nums[i]==nums[j]){
                nums[j]++;
                k--;
            }
        }
        i=i+2;
        j=j+2;
    }

}