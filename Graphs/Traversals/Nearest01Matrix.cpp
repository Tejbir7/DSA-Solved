#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    //Finding nearest 0
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> visited(m,vector<int>(n,0));
    vector<vector<int>> ans(m,vector<int>(n,0));
    queue<pair<pair<int,int>,int>> q; //((rowIdx,colIdx),distance)

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(!mat[i][j]){
                q.push({{i,j},0});
                 visited[i][j] =1;
            }
        }
    }

    int dRow[] = {-1,1,0,0};
    int dCol[] = {0,0,-1,1};

    while(!q.empty()){
        auto index = q.front().first;
        auto [row,col] = index;
        auto distance = q.front().second;
        q.pop();

      
        ans[row][col] = distance;

        for(int k=0; k<4; ++k){
            int nRow = row + dRow[k];
            int nCol = col + dCol[k];
            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n 
   && !visited[nRow][nCol] && mat[nRow][nCol]){
     q.push({{nRow,nCol},distance+1});   
      visited[nRow][nCol] = 1;   
   }      
        } 
 }

return ans;
        
    }

    //better soln

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    //Finding nearest 0
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> visited(m,vector<int>(n,0)), dist(m,vector<int>(n,0));
    queue<pair<int,int>> q; //(rowIdx,colIdx)

    //n*m
    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(!mat[i][j]){
                q.push({i,j});
                 visited[i][j] =1;
            }
        }
    }

    int dRow[] = {-1,1,0,0};
    int dCol[] = {0,0,-1,1};

   // n*m*4
    while(!q.empty()){
        auto [row,col] = q.front();
        q.pop();

        for(int k=0; k<4; ++k){
            int nRow = row + dRow[k];
            int nCol = col + dCol[k];

            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n 
   && !visited[nRow][nCol] ){
     q.push({nRow,nCol});   
     dist[nRow][nCol] = dist[row][col] +1;
      visited[nRow][nCol] = 1;
   }      
        } 
 }

return dist;
        
    }

