#include<bits/stdc++.h>
using namespace std;


    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n,vector<int>(m,0));
       vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        int size = sources.size();
        queue<pair<int,int>> q;

        for(int i=0; i<size; ++i){
            int row = sources[i][0];
            int col = sources[i][1];
            
            q.push({row,col});
           dist[row][col] = 0;
            
            int color = sources[i][2];
            grid[row][col] = color;
        }

         int dRow[] = {-1,1,0,0};
        int dCol[] = {0,0,-1,1};

        while(!q.empty()){
            
            auto [row,col] = q.front(); q.pop();

            for(int k=0; k<4; ++k){
                int nRow = row+ dRow[k];
                int nCol = col+ dCol[k];

                if(nRow>=0 && nCol>=0 && nCol <m && nRow <n){

                    //C1: uncolored
                    if(dist[nRow][nCol]>dist[row][col]+1){
                       dist[nRow][nCol] = dist[row][col] + 1;
                        grid[nRow][nCol] = grid[row][col];
                        q.push({nRow, nCol});
                    }
                    //C2: colored
                    else if(dist[nRow][nCol]==dist[row][col]+1){
                        grid[nRow][nCol] = max(grid[nRow][nCol], grid[row][col]);
                        // Note: We DO NOT push to the queue here. It was already 
                        // pushed during Case 1 when the first color reached it.
                    }
                    // Case 3: Reached at a later time step. Do nothing (implicitly handled).
                }
            }
            
            }
        
        return grid;
    }
