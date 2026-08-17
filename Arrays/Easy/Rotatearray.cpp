#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k){
    int n= nums.size();
    k%=n;
    if(k==0) return ;
   reverse(nums.begin(),nums.end());
   reverse(nums.begin(),nums.begin()+k);
   reverse(nums.begin()+k,nums.end());
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
    cout << "Enter k: ";
    cin >> k;
    rotate(nums,k);
    for(int x=0;x<n;x++){
        cout << nums[x] << " ";
    }
   
    return 0;

}