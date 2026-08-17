#include<iostream>
#include<vector>
using namespace std;
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1;
    while(low<=high){
        int mid = low+((high-low)/2);
        if(nums[mid]== target) return mid;
        else if(target<nums[mid]) high = mid -1;
        else low = mid+1;
    }
    return -1;        
}

    int recursiveSearch(vector<int>& nums,int low, int high, int target) {
    if(low>high) return -1;
    int mid = low+((high-low)/2);
   
    if(nums[mid]==target) return mid;
    else if(nums[mid]<target) return recursiveSearch(nums,mid+1,high,target);
    else return recursiveSearch(nums,low,mid-1,target);          
    }

int main()
{
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 6, n = a.size();;
    int ind = search(a, target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    ind = recursiveSearch(a,0,n-1,target);
    if (ind == -1) cout << "The target is not present." << endl;
    else cout << "The target is at index: "
                  << ind << endl;
    return 0;
}
