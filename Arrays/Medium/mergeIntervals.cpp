#include<bits/stdc++.h>
using namespace std;
// when n is small: <=10^7,  O(n+M)
 vector<vector<int>> merge(vector<vector<int>>& occupiedIntervals) {
        if(occupiedIntervals.empty()) return {};
         int n = occupiedIntervals.size();
    int maxi = INT_MIN;
    vector<vector<int>> ans;

    for(auto &p: occupiedIntervals){
        maxi = max(maxi,p[1]);
    }
    maxi = 2*  (maxi+1);
    vector<int> difference(maxi,0);

    for(auto&p: occupiedIntervals){
        int start = 2* p[0];
        int end = 2* p[1];
        difference[start]++;
        if(end+1 < maxi) difference[end+1]--;
    }
    for(int i=1; i< maxi; ++i){
        difference[i] += difference[i-1];
    }
    
    int start = 0; int end = 0;

    for(int i=0; i< maxi; ++i){
       if( difference[i] !=0 ){
         start = i;
         int next = i+1;
         while(next < maxi && difference[next] != 0) {
            i++;
            next++;
         }
         int end = i;
         ans.push_back({start/2,end/2}) ;
       }

    }
        return ans;
    }

    //betterVersion: n log n 
     vector<vector<int>> merge(vector<vector<int>>& occupiedIntervals) {
          int n = occupiedIntervals.size();
    sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> ranges;

    int prevStart = occupiedIntervals[0][0];
    int prevEnd = occupiedIntervals[0][1];

    for(int i=1; i<n; ++i){
        int currStart = occupiedIntervals[i][0];
        int currEnd = occupiedIntervals[i][1];

        if(currStart <= prevEnd){
            prevEnd = max(prevEnd, currEnd);
            continue;
        }else{
            ranges.push_back({prevStart,prevEnd});
            prevStart = currStart;
            prevEnd = currEnd;
        }
    }
    ranges.push_back({prevStart, prevEnd});
    return ranges;
    }