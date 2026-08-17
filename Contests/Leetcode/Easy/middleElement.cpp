#include<bits/stdc++.h>
using namespace std;
  bool isMiddleElementUnique(vector<int>& nums) {
    int n = nums.size();
    int ceil = n-1/2;
    int maxi = INT_MIN;
     for(int i: nums){
        maxi = max(maxi,i);
     }
    vector<int> count(maxi+1,0);
    for(int i: nums) count[i]++;
    if(count[ceil]==1) return true;
    return false; 
    }