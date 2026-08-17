#include<bits/stdc++.h>
using namespace std;

//Wont work very large allocation needed
//   vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
//     int n = occupiedIntervals.size();
//     int maxi = INT_MIN;
//     vector<vector<int>> ans;

//     for(auto &p: occupiedIntervals){
//         maxi = max(maxi,p[1]);
//     }

//     vector<int> difference(maxi+1,0);

//     for(auto&p: occupiedIntervals){
//         int start = p[0];
//         int end = p[1];
//         difference[start]++;
//         if(end+1 < maxi+1) difference[end+1]--;
//     }
//     for(int i=1; i<maxi+1; ++i) difference[i] += difference[i-1];
//     for(int i= freeStart; i<= freeEnd; ++i) difference[i] = 0;

//      int start = 0;
//      int end = 0;
//     for(int i=0; i<maxi+1; ++i){

//        if( difference[i] !=0 ){
//          start = i;
//          int next = i+1;
//          while( next<maxi+1 && difference[next] !=0) {
//             i++;
//             next++;
//          }
//          int end = i;
//          ans.push_back({start,end}) ;
//        }

//     }
//         return ans;
//     }

vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
    int n = occupiedIntervals.size();
    sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<vector<int>> ranges;

    int prevStart = occupiedIntervals[0][0];
    int prevEnd = occupiedIntervals[0][1];

    for(int i=1; i<n; ++i){
        int currStart = occupiedIntervals[i][0];
        int currEnd = occupiedIntervals[i][1];

        if(currStart <= prevEnd+1){
            prevEnd = max(prevEnd, currEnd);
            continue;
        }else{
            ranges.push_back({prevStart,prevEnd});
            prevStart = currStart;
            prevEnd = currEnd;
        }
    }
    ranges.push_back({prevStart, prevEnd});

    vector<vector<int>> ans;

    // for(auto &p: ranges){
    //     int start = p[0], end = p[1];

       
    //     if(start<freeStart){
    //         ans.push_back({start, min(end,freeStart-1)});
           
    //     }
    //     if(end>freeEnd){
    //         ans.push_back({max(freeEnd+1,start), end});
           
    //     }
      
    // }
    for (auto &p : ranges) {
    int start = p[0], end = p[1];

    // Scenario 1: Completely before the free interval
    if (end < freeStart) {
        ans.push_back({start, end});
    }
    // Scenario 2: Completely after the free interval
    else if (start > freeEnd) {
        ans.push_back({start, end});
    }
    // Scenario 3: Overlaps with the free interval
    else {
        // Is there a valid left chunk before freeStart?
        if (start < freeStart) {
            ans.push_back({start, freeStart - 1});
        }
        // Is there a valid right chunk after freeEnd?
        if (end > freeEnd) {
            ans.push_back({freeEnd + 1, end});
        }
    }
}
   return ans;
    }