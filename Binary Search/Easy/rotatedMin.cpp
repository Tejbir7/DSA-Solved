#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<cstdlib>
using namespace std;
 int findMin(vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;
    int low = 0, high = n-1;
    while(low<=high){
      int mid = low+((high-low))/2;
      if(nums[low]<=nums[high]){    //not rotated
         ans = min(nums[low],ans);
         break;
      }
      if(nums[low]<=nums[mid]){
         ans = min(nums[low],ans); //lowest in this part and check with other half
         low = mid+1; //next part
      }else{
         ans = min(nums[mid], ans); 
         high = mid -1;
      }      
    }
    return ans;
 }
  
      

