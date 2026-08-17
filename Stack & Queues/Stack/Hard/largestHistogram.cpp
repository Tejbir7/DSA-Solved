#include<iostream>
#include<utility>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
//Approach , We would be needing pse and nse to solve the problem and then it would be easy and would boil down to O(N)
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
    // 2nd way better approach 
     int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i=0; i<n; ++i){
            while(!st.empty() && heights[st.top()]>= heights[i]){
                int el = st.top();
                st.pop();
               int nse = i, pse = st.empty() ? -1 : st.top();
               maxArea = max(maxArea, heights[el]*(nse-pse-1)); 
            }
            st.push(i);
        }
        //leftover elements
        while(!st.empty()){
            int nse = n;
            int el = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, (nse-pse-1)* heights[el]);
        }
        return maxArea;
    }
