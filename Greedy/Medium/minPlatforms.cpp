#include<bits/stdc++.h>
using namespace std;
//2 Ptr

  int minPlatform(vector<int>& arr, vector<int>& dep) {
      int n = arr.size();
      sort(arr.begin(), arr.end());
      sort(dep.begin(), dep.end());

    
      int ans = 1;
      int i=0, j = 0;
      int curr = 0;

      while(i<n && j<n){
          
        if(arr[i]<= dep[j]){
          ++curr;
          ans = max(curr, ans);
          ++i;
        }
        else{
             --curr;
             ++j;
        }

      }

      return ans;
    }