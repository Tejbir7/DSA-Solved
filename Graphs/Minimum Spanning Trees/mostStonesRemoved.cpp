#include<bits/stdc++.h>
using namespace std;
int mRow = INT_MIN;
int mCol = INT_MIN;

// //Wrong idea it would be 10001* 10001 cells 
// void dfs(vector<vector<int>>& placed,int i, int j){
//     if(i<0 || j<0 || i>mRow || j> mCol || placed[i][j] == 0) return;

//     placed[i][j] = 0;
    
    
    
// }
//  int removeStones(vector<vector<int>>& stones) {
//    for(auto &p: stones){
//     int row = p[0], col = p[1];
//     if(row>mRow) mRow = row;
//     if(col>mCol) mCol = col;
//    }
//    int totalStones = 0;
//    vector<vector<int>> placed(mRow+1, vector<int>(mCol+1,0));
//    for(auto &p: stones){
//     int row = p[0], col = p[1];
//      placed[row][col] = 1;
//      ++totalStones;
//    }

//    int count = 0;

//     for(int i=0; i<mRow; ++i){
//         for(int j=0; j<mCol; ++j){
//             if(placed[i][j] == 1){
//                 dfs(placed, i, j);
//                 ++count;
//             }
//         }
//     }
  
//     return totalStones- count;
//     }

unordered_map <int, vector<int>> rowMap;
unordered_map <int,vector<int>> colMap; 

void dfs(vector<int> &vis, vector<vector<int>>& stones , int i){
    vis[i] = 1;
    int row = stones[i][0];
    int col = stones[i][1];

    for(auto nei: rowMap[row]){
        if(!vis[nei]) dfs(vis, stones, nei);
    }
    for( auto nei: colMap[col]){
        if(!vis[nei]) dfs(vis,stones, nei);
    }
    return;
}

  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size(); 

    for(int i=0; i<n; ++i){
        rowMap[stones[i][0]].push_back(i);
        colMap[stones[i][1]].push_back(i);
    }

    vector<int> vis(n,0);
    int components = 0;

    for(int i=0 ; i< n ; ++i){
    
        if(!vis[i]){
             dfs(vis,stones, i);
             ++components;
        }
    }
        return n-components;
    }