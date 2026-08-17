#include<iostream>
#include<vector>
using namespace std;
 void sortColors(vector<int>& nums) {
    int n = nums.size();
    int low = 0,mid=0,high=n-1;
    while(mid<=high){
   if(nums[mid]==0){
    swap(nums[low],nums[mid]);
    ++mid;
    ++low;
   }
  else if(nums[mid]==1){
    ++mid;
   }
   else{
    swap(nums[mid],nums[high]);
    --high;
   }
    }
}
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter values: ";
    for(int x=0;x<n;x++){
        cin >> nums[x];
    }
    sortColors(nums);
 for(int x=0;x<n;x++){
        cout << nums[x] << " ";
    }

    return 0;

}