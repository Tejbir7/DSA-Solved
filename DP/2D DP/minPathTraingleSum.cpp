#include<bits/stdc++.h>
using namespace std;
  int minimumTotal(vector<vector<int>>& triangle) {
    int height = triangle.size();
    for(int i=1; i<height; ++i){
        triangle[i][0] += triangle[i-1][0];
    }
    for(int i=1; i<height; ++i){
        int prevSize = triangle[i-1].size();
        int currSize = triangle[i].size();
       for(int j=1; j< prevSize ; ++j){
          triangle[i][j] += min(triangle[i-1][j],triangle[i-1][j-1]);
       }
       triangle[i][currSize-1] += triangle[i-1][prevSize-1];
    }
        int ans = INT_MAX;
    for(int i=0; i< triangle[height-1].size(); ++i){
        ans = min(ans,triangle[height-1][i]);
    }
    return ans;
    }