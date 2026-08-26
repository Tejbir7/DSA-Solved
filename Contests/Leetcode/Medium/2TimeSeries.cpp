#include<bits/stdc++.h>
using namespace std; 
 vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        int m = s1.size(), n = s2.size();
        int i = 0, j= 0;
        vector<vector<int>> ans;

        while(i<m || j<n){
            if(i<m && j<n && s1[i][0] <= s2[j][0]){
                ans.push_back({s1[i][0], s1[i][1]+s2[j][1]});
                ++i;
            }
            else if(i<m && j<n && s1[i][0] > s2[j][0] ){
                ans.push_back({s2[i][0], s1[i][1]+s2[j][1]});
                ++j;
            }
        }
        return ans;
    }