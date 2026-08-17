#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//simple level count like BT
void bfs(vector<vector<int>>& grid, queue<pair<int,int>> &q,int &count, int& fresh){
   int m = grid.size(); //rows
    int n = grid[0].size(); //cols

    int delRow[] = {-1,1,0,0};
    int delCol[] = {0,0,-1,1};

    while(!q.empty() && fresh >0){
        int level = q.size();
        for(int i=0; i<level; ++i){
            auto [row,col] = q.front();
            q.pop();
            for(int k=0; k<4; ++k){
                int nRow = row+ delRow[k];
                int nCol = col+ delCol[k];
                if(nRow>=0 && nRow<m && nCol >=0 && nCol<n && grid[nRow][nCol] == 1){
                    q.push({nRow,nCol});
                    grid[nRow][nCol] = 2;
                    --fresh;
                }
            }
        }
        ++count;
    }


}
 int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size(); //rows
    int n = grid[0].size(); //cols
    queue<pair<int,int>> q;
    int fresh = 0;

    for(int i=0; i<m ;++i){
        for(int j=0; j<n; ++j){
            if(grid[i][j] == 2) q.push({i,j});            
            if(grid[i][j] == 1) fresh++;

        }
    }
    int count = 0;
    bfs(grid,q, count, fresh); 
    return !fresh ? count : -1;         
    }