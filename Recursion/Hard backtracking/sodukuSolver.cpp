#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isValid(vector<vector<char>>&board,int row,int col, char ch){
    for(int i=0;i<9;i++){
        //row check;
        if(board[row][i]==ch) return false;

        //col check;
        if(board[i][col]==ch) return false;

        //cell check;
        if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)]== ch)
        return false;
    }
    return true;
}

bool dfs(vector<vector<char>> &board){
     for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            if(board[i][j]=='.'){
                for(char ch='1';ch<='9';++ch){
                    if(isValid(board,i,j,ch)){
                        board[i][j]= ch;
                        if(dfs(board)) return true;
                        board[i][j] = '.';
                    }
                }      
                return false; 
            }else continue;            
        }
    }
    return true;
}

 void solveSudoku(vector<vector<char>>& board) {
   dfs(board);        
    }