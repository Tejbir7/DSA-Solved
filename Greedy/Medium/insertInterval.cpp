#include<bits/stdc++.h>
using namespace std;
 vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int maxi = INT_MIN;
       for(auto &it: intervals){
        int r = it[1];
        maxi = max(maxi, r);
       }
       maxi = max({maxi, newInterval[0], newInterval[1]});
       int n = 2*maxi+2;
       vector<int> prefix(n,0);
        for(auto &it: intervals){
            int l = 2*it[0];
        int r = 2*it[1];
         ++prefix[l];
         --prefix[r+1];
       }
       ++prefix[2*newInterval[0]];
       --prefix[2*newInterval[1]+1];

       for(int i=1; i<n; ++i){
        prefix[i] += prefix[i-1];
       }

       int i=0;
       vector<vector<int>>ans;
       while(i<n){
        if(prefix[i]>0){
            int l = i/2;
            while(i+1<n && prefix[i+1]!= 0){
                ++i;
            }
            int r = i/2;
            ans.push_back({l,r});
        }
        ++i;
       }
       return ans;
    }

//another 
 vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int L = newInterval[0], R = newInterval[1];
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();
        
        int left = -1, right = -1;
        int i=0;

      while(i<n && intervals[i][1]<L){
        ans.push_back(intervals[i]);
        ++i;
      }

      while(i<n && intervals[i][0]<=R){
        L = min(L,intervals[i][0]);
        R = max(intervals[i][1], R);
        ++i;
      }
      ans.push_back({L,R});
      while(i<n){
        ans.push_back(intervals[i++]);
      }
      return ans;
}