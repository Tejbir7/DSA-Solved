#include<bits/stdc++.h>
using namespace std;

//incorrect
// void dfs(int i,vector<int>&nums, int n ){
//     if(i>=n-1) return;
//     nums[i] = 0;
//     dfs(i+1,nums,n);
// }
// //bobWins = true intially
// bool turns(bool &bobWins, vector<int>&nums){
//     int n = nums.size();
//     for(int i=0; i<n; ++i){
//         if(nums[i]){
//             dfs(i,nums,n);
//            bobWins =  !bobWins;
//         }
//     }
//     return bobWins;
// }
//  int main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n; cin >> n;
//         vector<int> nums(n);
//         for(int i=0; i<n; ++i) cin >> nums[i]; 

//         bool bobWins = false;
//         bobWins = turns(bobWins,nums);
//         if(bobWins) cout << "Bob";
//         else cout << "Alice";
//     }
//     return 0;
//  }