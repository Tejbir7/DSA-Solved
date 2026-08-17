#include<bits/stdc++.h>
using namespace std;
//Recurrence soln: Uses extra stack space 
 int f(vector<vector<int>>&dp, int m, int n){
    if(m<0 || n<0) return 0;
    if(m==0 && n==0) return 1;
    if(dp[m][n]!=-1) return dp[m][n];
    return dp[m][n] = f(dp,m-1,n) + f(dp,m,n-1);
 }
 int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,-1));
    int ans = f(dp,m-1,n-1);
    return ans;        
    }

    //Tabulization: stack space eliminated
 int uniquePaths(int m, int n) {
    vector<vector<int>> ways(m, vector<int>(n,1));
     for(int row=1; row<m ; ++row){
        for(int col=1; col<n; ++col){
             ways[row][col] = (ways[row-1][col] + ways[row][col-1]);
        }
     }
     return ways[m-1][n-1];        
    }
    //Space optimised dp:
    int uniquePaths(int m, int n) {
    vector<int> prev(n,1);
     for(int row = 1; row<m; ++row){
        vector<int>temp(n);
     for(int col=0; col<n ; ++col){            
        if(col == 0){
            temp[col] = prev[col];
            continue;
        }
        temp[col] = temp[col-1] + prev[col];                            
     }
     prev = temp;
    }
     return prev[n-1];        
    }
