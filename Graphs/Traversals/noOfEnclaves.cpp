  #include<bits/stdc++.h>
  using namespace std;
//Next tym pass m and n to avoid recompute
  void dfs(vector<vector<int>>&grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!= 1) return;
        grid[i][j] = 7;
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
      
    }
    int numEnclavesDFS(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //boundary traversal
        for(int j=0; j<n ; ++j){
            if(grid[0][j]==1) dfs(grid,0,j);
            if(grid[m-1][j]==1) dfs(grid,m-1,j);
        }
        for(int i=0; i<m ; ++i){
            if(grid[i][0]==1) dfs(grid,i,0);
            if(grid[i][n-1]==1) dfs(grid,i,n-1);
        }   
        int count =0;

        //final updation:
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
            //    if(grid[i][j]==7) grid[i][j] = 1;
            //No need to correct this
                if(grid[i][j]==1) ++count;
            }
        }     

        return count;
    }
//in bfs instantly mark it while pushing , never wait!!
    void bfs(vector<vector<int>>&grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int dRow[] = {0,0,1,-1};
        int dCol[] = {1,-1,0,0};
        q.push({i,j});
         grid[i][j] = 7;

        while(!q.empty()){
            auto[row, col] = q.front(); q.pop();
         
            for(int k=0; k<4; ++k){
                int nRow = row + dRow[k];
                int nCol = col + dCol[k];

                if(nRow>=0 && nRow<m && nCol>=0 && nCol<n && grid[nRow][nCol] == 1){
                    grid[nRow][nCol] = 7;
                    q.push({nRow,nCol});
                }
            }
        }
        return;
    }
     int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //boundary traversal
        for(int j=0; j<n ; ++j){
            if(grid[0][j]==1) bfs(grid,0,j);
            if(grid[m-1][j]==1) bfs(grid,m-1,j);
        }
        for(int i=0; i<m ; ++i){
            if(grid[i][0]==1) bfs(grid,i,0);
            if(grid[i][n-1]==1) bfs(grid,i,n-1);
        }   
        int count =0;

        //final updation:
        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
            //    if(grid[i][j]==7) grid[i][j] = 1;
            //No need to correct this
                if(grid[i][j]==1) ++count;
            }
        }     

        return count;
        
    }