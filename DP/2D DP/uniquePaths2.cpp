#include<bits/stdc++.h>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0] == 1) return 0;
 int m = obstacleGrid.size();
 int n = obstacleGrid[0].size();
    if(obstacleGrid[m-1][n-1] == 1) return 0;

vector<vector<long long>> ways(m, vector<long long>(n));

for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
           ways[i][j] = obstacleGrid[i][j];
    }
} 
       ways[0][0] = 1;
     int dRow[] = {0,1};
     int dCol[] = {1,0};

     for(int row=0; row<m ; ++row){
        for(int col=0; col<n; ++col){
            if(obstacleGrid[row][col]== 1) continue;             
            for(int k=0; k<2; ++k){
                int nRow = row + dRow[k];
                int nCol = col + dCol[k];
                
                if(nCol>=0 && nCol<n && nRow>=0 && nRow<m && obstacleGrid[nRow][nCol]!= 1){
                    ways[nRow][nCol] += ways[row][col];
                }
            }
        }
     }
     return ways[m-1][n-1];        
    }