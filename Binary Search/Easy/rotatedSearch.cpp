#include<iostream>
#include<vector>
using namespace std;

 int search(vector<int>& nums, int target) {
   int n = nums.size();
    if (n == 0) return -1;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;

        // If left half [low..mid] is sorted
        if (nums[low] <= nums[mid]) {
            // Is target inside the sorted left half?
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Otherwise right half [mid..high] must be sorted
        else {
            // Is target inside the sorted right half?
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
    }

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int k = 1;
    int ans = search(arr, k);
    if (ans == -1)
        cout << "Target is not present.\n";
    else
        cout << "The index is: " << ans << "\n";
    return 0;
}
