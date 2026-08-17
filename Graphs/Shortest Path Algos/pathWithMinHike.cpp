#include<bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> hikes(n, vector<int>(m, INT_MAX));

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        int dRow[] = {0,0,1,-1};
        int dCol[] = {1,-1,0,0};

        pq.push({0,{0,0}});
        hikes[0][0] = 0;
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int hike = it.first; auto [row,col] = it.second;

            if(row == n-1 && col == m-1) return hike;
            if(hike > hikes[row][col]) continue;         

            for(int k=0; k<4; k++) {
                int nRow = row + dRow[k];
                int nCol = col + dCol[k];

                if(nRow>=0 && nRow<n && nCol>=0 && nCol<m) {

                    int diff = abs(heights[nRow][nCol] - heights[row][col]);

                    int newEffort = max(hike, diff);

                    if(newEffort < hikes[nRow][nCol]) {
                        hikes[nRow][nCol] = newEffort;
                        pq.push({newEffort,{nRow,nCol}});
                    }
                }
            }
        }

        return 0;
    }