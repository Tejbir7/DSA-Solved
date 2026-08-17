#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   int left = m-1; int right = 0;
   while(left>=0 && right<n){
    if(nums1[left]>nums2[right]){
        swap(nums1[left], nums2[right]);
        --left;
        ++right;
    }else{
        break;
    }
   }
   sort(nums1.begin(),nums1.end());
   sort(nums2.begin(),nums2.end());
}

     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!n) return;
        int left = m-1, right = 0;
        while(right <n){
            nums1[left]==nums2[right];
            left--; ++right;
        }
        sort(nums1.begin(),nums2.end());
        return;
    }