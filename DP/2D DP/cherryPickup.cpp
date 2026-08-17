#include<bits/stdc++.h>
using namespace std;

int f(int r1, int c1, int r2, int c2, vector<vector<int>>& grid, vector<vector<vector<vector<int>>>> &dp){
    int cherries = 0;
     int m = grid.size();
     int n = grid[0].size();

    if(r1<0 || c1<0 || r2<0 || c2<0 || r1>=m || c1>=n || r2>=m || c2>=n ||
   grid[r1][c1]==-1 || grid[r2][c2]==-1 ) return -1e9;

    if(dp[r1][c1][r2][c2] != -1) return dp[r1][c1][r2][c2];

    if(r1 == r2 && c1 == c2){
        cherries+= grid[r1][c1];        
    }else{
        cherries+= grid[r1][c1] + grid[r2][c2];
    }

    if(r1==m-1 && r2==m-1 && c1 == n-1 && c2 == n-1) return cherries;

    int hh = f(r1+1,c1,r2+1,c2,grid,dp);
    int dd = f(r1,c1+1,r2,c2+1,grid,dp);
    int hd = f(r1+1,c1,r2,c2+1,grid,dp);
    int dh = f(r1,c1+1,r2+1,c2,grid,dp);

    int best = max({hh,dd,hd,dh}); 

    return dp[r1][c1][r2][c2] = cherries + best;
}

   int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<vector<int>>>> dp(m, 
        vector<vector<vector<int>>>(n,
            vector<vector<int>>(m
                , vector<int>(n,-1))));
                
                int ans = f(0,0,0,0,grid,dp);
                return max(0,ans) ;        
    }