#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
 int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> pse, nse;
        vector<pair<int , int>> smallers(n);
        //smallers({pse,nse});
        for(int i = 0; i<n ; ++i){
         int j = n-i-1;
         while(!pse.empty() && heights[pse.top()]>= heights[i]) pse.pop();
         while(!nse.empty() && heights[nse.top()]>= heights[j]) nse.pop();
         smallers[i].first = pse.empty() ? -1 : pse.top();
         smallers[j].second = nse.empty() ? n : nse.top();

         pse.push(i);
         nse.push(j);         
        }

        int maxArea = 0;
        for(int i = 0; i<n ; ++i){
            int width = smallers[i].second - smallers[i].first - 1;
            maxArea = max(maxArea, width * heights[i] );

        }
        return maxArea;
    }

  int maximalRectangle(vector<vector<char>>& matrix) {
    if(matrix.empty() || matrix[0].empty()) return 0;
    int n = matrix.size();   //rows
    int m = matrix[0].size();   //cols
    vector<vector<int>> prefixSum(n, vector<int>(m,0) );
  for(int j=0;j <m; ++j){
    int sum = 0;
    for(int i=0; i<n; ++i){
        sum+= matrix[i][j] - '0';
        if(matrix[i][j] == '0') sum = 0;
        prefixSum[i][j] = sum;
    }
  }
  //So the prefix sum matrix is complete
  //Now 
  int maxArea = 0;
  for(int i=0; i<n; ++i){
    maxArea = max(maxArea, largestRectangleArea(prefixSum[i]));
  }
  return maxArea;
 }