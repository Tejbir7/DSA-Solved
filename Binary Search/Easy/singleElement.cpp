#include<iostream>
#include<vector>
using namespace std;
 int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return -1;
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];
    int low = 1, high = n-2;
    while(low<=high){
    int mid = low+((high-low)/2);
    if (nums[mid+1]!=nums[mid] && nums[mid-1]!=nums[mid]) return nums[mid];
    if((mid%2==0 && nums[mid]==nums[mid-1] )|| (mid%2!=0 && nums[mid]==nums[mid+1] )){
        high = mid -1;
    }else{
        low = mid+1;
    }      
    }
    return -1;
    }
 int singleNonDuplicate2(vector<int>& nums) {
    int n = nums.size();
    if(n==0) return -1;
    if(n==1) return nums[0];
    int low=0, high = n-1;
    while(low<high){
        int mid = low+((high-low)/2);
        if(nums[mid]==nums[mid^1]){
            low = mid+1;
        } else high = mid;      

    }
    return nums[low];
   
    }
int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = singleNonDuplicate(arr);
    cout << "The single element is: " << ans << "\n";
    int ans1 = singleNonDuplicate2(arr);
    cout << "The single element by m2 is: " << ans << "\n";
    return 0;
}

    
        
    