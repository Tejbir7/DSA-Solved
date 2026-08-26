#include<bits/stdc++.h>
using namespace std;
  int maximumGap(const string& skill, const string& station) {
         int n = skill.size(), m = station.size();
        if (n == 1) return 0;
        vector<int> left(n), right(m);

        int j = 0;
        for(int i=0; i<n; ++i){
         
         while(j<m && skill[i] != station[j]){
            ++j;
         }
         left[i] = j;
         ++j;
        }

        j = m-1;
        for(int i=n-1; i>=0; --i){
         while(j>=0 && skill[i] != station[j]){
            --j;
         }
         right[i] = j;
         --j;
        }
        int ans = 0;
        for(int i=1; i<n; ++i){
         ans = max(ans, right[i]-left[i-1]);
        }
        return ans;
    }