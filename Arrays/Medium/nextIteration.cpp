#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
  void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if(n<=1) return;
    int i = n-2;
    while(i>=0 && nums[i]>=nums[i+1]){ --i;}
    if(i>=0){
        int j = n-1;
        while(nums[j]<= nums[i]){ --j;}
        swap(nums[i],nums[j]);
    }
    reverse(nums.begin()+i+1, nums.end());
    return;  
    }
    
void nextPermutation2(vector<int>& nums) {
    next_permutation(nums.begin(), nums.end());
}

int main(){
    int n,target;
    cout << "Enter n: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter values: ";
    for(int x=0;x<n;x++){
        cin >> nums[x];
    }
     nextPermutation(nums);
    for(int x=0;x<n;x++){
        cout << nums[x] << " ";
    }
    return 0;
}
    
