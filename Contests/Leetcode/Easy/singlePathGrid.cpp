#include<bits/stdc++.h>
using namespace std;
  vector<string> createGrid(int m, int n) {
        vector<vector<char>> grid(m, vector<char>(n,'#'));
        for(int i=0; i<n; ++i) grid[0][i] = '.';
        for(int j=1; j<m; ++j) grid[j][n-1] = '.';
        vector<string> ans;

        for(int i=0; i<m ; ++i){
             string temp;
            for(int j=0; j<n; ++j){
                temp += grid[i][j];
            }
            ans.push_back(temp);
            }

            return ans;        
    }