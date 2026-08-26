#include<bits/stdc++.h>
using namespace std;

//CuberSome, Avoid in contests
//  vector<string> createGrid(int m, int n, int k) {
//     vector<string>ans;
//     if(k==1){
//         if(m<1 || n<1) return {};
//         vector<vector<char>> grid(m,vector<char>(n,'#'));
//         for(int i=0; i<n; ++i) grid[0][i] = '.';
//         for(int i=0; i<m; ++i) grid[i][n-1] = '.';
//         for(auto it: grid){
//             string temp;
//             for(auto i: it){
//                 temp.push_back(i);
//             }
//             ans.push_back(temp);
//         }
//         return ans;
//     }
//    else if(k==2){
//         if(m<2 || n<2) return {};
//         vector<vector<char>> grid(m,vector<char>(n,'#'));
//         for(int i=0; i<n; ++i) {
//             grid[0][i] = '.';
//             grid[m-1][i] = '.';
//         }
//         for(int i=0; i<m; ++i) {
//         grid[i][n-1] = '.';
//         grid[i][0] = '.';

//     }
//         for(auto it: grid){
//             string temp;
//             for(auto i: it){
//                 temp.push_back(i);
//             }
//             ans.push_back(temp);
//         }
//         return ans;
//     }
//   else  if(k==3){
//     int row = 0, col = 0;

//       if (n >= 3 && m >= 2){
//         row = 2; col = 3;
//       }    
// else if (m >= 3 && n >= 2)  {
//     row = 3; col = 2; 
// }
//   else  return {};
// }

//        vector<vector<char>>grid(m,vector<char>(n,'#'));
      
//        for(int i=0; i<row; ++i){
//         for(int j=0; j<col; ++j){
//             grid[i][j] = '.';
//         }
//        }

       
        
//     }

    //Backtracking like N Queens
    
     int countPaths(vector<vector<char>> &grid, int m, int n, int k){

        vector<vector<long long>> dp(m, vector<long long>(n,0));

        for(int i=0 ; i<n; ++i) {
            if(grid[0][i] == '#') break;
            dp[0][i] = 1;
        }
        for(int i=0 ; i<m; ++i){
            if(grid[i][0] == '#') break;
            dp[i][0] = 1;
        } 

        for(int i=1; i<m; ++i){
            for(int j=1; j<n; ++j){
                if(grid[i][j] == '#' ) continue;
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        
        return min(dp[m-1][n-1],(long long) k + 1);        
    }

    bool solve(vector<vector<char>> &grid,int k, int row, int col){
        int m = grid.size(), n = grid[0].size();
         if(row == m) return false;

        int cnt = countPaths(grid,m,n,k);

         if(cnt==k) return true;
         if (cnt < k) return false;
     
       int nr = row; int nc = col+1;
        if(nc == n){
            nr = row+1;
            nc = 0;
        }

         if ((row == 0 && col == 0) || (row == m - 1 && col == n - 1))
        return solve(grid, k, nr, nc);

        //block this 
        grid[row][col] = '#';
        if(solve(grid,k,nr,nc)) return true;

        //keep open
         grid[row][col] = '.';
       return solve(grid, k, nr, nc);
             
    }
   
    vector<string> createGrid(int m, int n, int k) {
        if(k==1 && (m<1 || n<1)) return {};
         if(m<2 || n<2) return {};

         vector<string> ans;
        vector<vector<char>> grid(m,vector<char>(n, '.'));
            
        if(solve(grid,k,0,0)){
              for(auto it: grid){
            string temp;
            for(auto i: it){
                temp.push_back(i);
            }
            ans.push_back(temp);
        }
        return ans;
        }
        return {};        
    }