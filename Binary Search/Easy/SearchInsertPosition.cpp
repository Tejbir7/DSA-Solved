#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int n = nums.size(),aspect=0;
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low+((high-low)/2);
        if(nums[mid]== target) return mid;
        else if(target<nums[mid]) high = mid -1;
        else low = mid+1;
        aspect = mid;
    }
   if (aspect == low) return low;
   else if (aspect == high) return high+1;
   else return aspect;
}
int searchInsert(vector<int>& arr, int target) {
    int n = arr.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= target) {
            ans = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = search(arr, x);
    cout << "The index is: " << ind << "\n";
    ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}