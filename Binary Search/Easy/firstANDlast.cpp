#include<iostream>
#include<vector>
using namespace std;
   vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return {-1, -1};

    // find first index with nums[idx] >= target (lower_bound)
    int l = 0, h = n - 1, first = n;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (nums[mid] >= target) {
            first = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    // if target not present
    if (first == n || nums[first] != target) return {-1, -1};

    // find first index with nums[idx] > target (upper_bound)
    l = 0; h = n - 1;
    int upper = n;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (nums[mid] > target) {
            upper = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    int last = upper - 1;          // last index where nums[idx] == target
    return {first, last};
    }
        
int main() {
  int n = 7;
  int target = 13;
  vector < int > nums = {3,4,13,13,13,20,40};
  
  // returning the last occurrence index if the element is present otherwise -1
  vector<int> ans = searchRange(nums,target);
  for(auto it: ans){
 cout << it << " ";
  }
  return 0;
}