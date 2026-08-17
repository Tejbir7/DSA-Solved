#include<iostream>
#include<vector>
using namespace std;
void swapGreater(vector<int>& nums1,vector<int>& nums2, int i, int j){
    if(nums1[i]>nums2[j]) swap(nums1[i],nums2[j]);
}
void mergeNM(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   if(!n || !m) return;
    int len = n+m;
    int gap = (len+2-1)/2; //seal
    while(gap>0){
        int left = 0;
        int right = left+gap;
        while(right<len){
            // arr1 and arr2
            if(left<m && right>=m){
                swapGreater(nums1,nums2,left,right-m);
            }
            //arr2 and arr2
           else if(left>=m){
            swapGreater(nums1,nums2,left-m,right-m);
            }
            // arr1 and arr1
            else{
                swapGreater(nums1,nums2,left,right);
            }
            ++left, ++right;
        }
        if(gap==1) break;
        gap = (gap+2-1)/2;
    }        
    }

//for leetcode variant:
 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         int i = m - 1;          // last valid element in nums1
    int j = n - 1;          // last element in nums2
    int k = m + n - 1;      // last position in nums1

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // copy remaining nums2 elements if any
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
    }