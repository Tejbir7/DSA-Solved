#include<bits/stdc++.h>
using namespace std;

//Rough Aprroach: Use djikstra to form the dist array and then do direct check 
 int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
     int n = grid.size();
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    if(n==1 ) return 1;

    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    queue<pair<pair<int,int> , int>> q;
    q.push({{0,0},1});
    grid[0][0] = 777;


    int dRow[] = {-1,0,1,-1,0,1,1,-1};
    int dCol[] = {-1,-1,-1,1,1,1,0,0};

    while(!q.empty()){
       auto it = q.front();
       q.pop();
       auto[row,col] = it.first; auto block = it.second;
      if(dist[row][col] > block) dist[row][col] = block;
       
       for(int k=0; k<8; ++k){
        int nRow = row + dRow[k];
        int nCol = col+ dCol[k];

        if(nRow>=0 && nCol >=0 && nRow<n && nCol<n && !grid[nRow][nCol]){
            q.push({{nRow,nCol},block+1});
            grid[nRow][nCol] = 777;
        }
       }
 }
 return dist[n-1][n-1] == INT_MAX  ? -1 : dist[n-1][n-1];
}

//BEST VERSION
 int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
       int n = grid.size();
    if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
    if(n==1 ) return 1;

    queue<pair<int,int>> q;
    q.push({0,0});
    grid[0][0] = 777;

    int block = 1;

    int dRow[] = {-1,0,1,-1,0,1,1,-1};
    int dCol[] = {-1,-1,-1,1,1,1,0,0};

    while(!q.empty()){
        int level = q.size();
        while(level--){

      
       auto[row,col] = q.front(); q.pop();
      if(row == n-1 && col == n-1 ) return block;
       
       for(int k=0; k<8; ++k){
        int nRow = row + dRow[k];
        int nCol = col+ dCol[k];

        if(nRow>=0 && nCol >=0 && nRow<n && nCol<n && !grid[nRow][nCol]){
            q.push({nRow,nCol});
            grid[nRow][nCol] = 777;
        }
       }
 }
 ++block;
}
 return -1;
}