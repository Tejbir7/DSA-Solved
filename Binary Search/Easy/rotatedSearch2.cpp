#include<iostream>
#include<vector>
using namespace std;
bool search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return false;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return true;

        // If left half [low..mid] is strictly sorted
        if (nums[low] < nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // If right half [mid..high] is strictly sorted
        else if (nums[low] > nums[mid]) {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // Ambiguous case: nums[low] == nums[mid] (duplicates)
        else {
            // Skip the duplicate at the left. Alternatively: high--;
            low++;
        }
    }
    return false;
}
                    