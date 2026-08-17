#include<iostream>
#include<vector>
using namespace std;
  void moveZeroes(vector<int>& nums) {
    int n= nums.size();
    int lastNonZero =0;
    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            nums[lastNonZero++] = nums[i];
        }

    }
    for(int i=lastNonZero; i<n;i++){
        nums[i]=0;
    }
      
    }
int main(){
    int n,k;
    cout << "Enter n: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter values: ";
    for(int x=0;x<n;x++){
        cin >> nums[x];
    }
    
    moveZeroes(nums);
    for(int x=0;x<n;x++){
        cout << nums[x] << " ";
    }
   
    return 0;

} 