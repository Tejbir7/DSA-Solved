#include<bits/stdc++.h>
using namespace std;
int f(int r, int c1, int c2, vector<vector<int>>& grid,  vector<vector<vector<int>>> &dp) { 
    int m = grid.size() , n = grid[0].size();

    //Out of Bound
    if(r<0 || c1<0 || c2<0 || c1>n-1 || c2>n-1 ) return -1e9;

    int cherries = 0;
    
    if(dp[r][c1][c2]!= -1) return dp[r][c1][c2];

    if(c1==c2){
        cherries = grid[r][c1];               
    }else{
        cherries = grid[r][c1] + grid[r][c2];
    }

    //Base Case
    if(r == grid.size()-1) return cherries;
    
    int best = -1e9;
    for(int d1=-1 ; d1<2; ++d1){
        for(int d2 = -1; d2<2; ++ d2){
          int  go = f(r+1,c1+d1,c2+d2,grid,dp);
          best = max(best,go);
        }
    }
    
    return dp[r][c1][c2] =  cherries + best;       
}

  int cherryPickup(vector<vector<int>>& grid) {
    int m = grid.size(); 
    int n = grid[0].size();
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(n,-1)));
    int ans = f(0,0,n-1,grid,dp);
    return ans;        
    }

    //Tabulation
     int cherryPickup(vector<vector<int>>& grid) {
         int m = grid.size(); 
         int n = grid[0].size();

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n,vector<int>(n,0)));

    //Base Case 
        for(int j = 0; j<n ; ++j){
            for(int k=0;  k<n; ++k){

                if(j==k) dp[m-1][j][k] = grid[m-1][j];
                else dp[m-1][j][k] = grid[m-1][j] + grid[m-1][k];                
            }
        }

        for(int i = m-2; i>-1; --i){
            for(int j= 0; j<n; ++j){
                for(int k=0; k<n; ++k){
                    
                     int best = -1e9 , curr = 0;
                     if(j==k) curr = grid[i][j];
                     else curr = grid[i][j] + grid[i][k];

                    for(int d1 = -1; d1<2; ++d1){
                        for(int d2 = -1; d2<2; ++d2){
                            int c1 = j+d1, c2 = k+d2;
                            if(c1>n-1 || c2>n-1 || c1<0 || c2<0) continue;

                            best = max(best, curr + dp[i+1][c1][c2]);
                        }
                    }

                    dp[i][j][k] = best;
                }
            }
        }
    
                return dp[0][0][n-1];
    }