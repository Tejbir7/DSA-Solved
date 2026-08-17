#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<char>>& board,  int i, int j){
    int m = board.size();
    int n = board[0].size();

    if(i <0 || j<0 || j> n-1 || i>m-1 || board[i][j] != 'O' ) return;
    board[i][j] = 'S';

    dfs(board,i,j+1);
    dfs(board,i,j-1);
    dfs(board,i+1,j);
    dfs(board,i-1,j);

}
//Why use visited we can perform on the matrix itself
//vector<vector<int>> visited(m, vector<int>(n,0));

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    int verticalBoundary[] = {0,n-1};
    for(int j: verticalBoundary){
        for(int i=0 ;i <m; ++i){
           if(board[i][j]=='O') dfs(board,i,j); 
        }
    }
    int horizontalBoundary[] = {0,m-1};
    for(int i: horizontalBoundary){
        for(int j=0 ;j <n; ++j){
           if(board[i][j]=='O') dfs(board,i,j); 
        }
    }

    for(int i=0; i<m; ++i){
        for(int j=0; j<n; ++j){
            if(board[i][j]=='S') board[i][j] = 'O';
            else if (board[i][j]=='O') board[i][j] = 'X';
        }
    }   

    return;
        
    }