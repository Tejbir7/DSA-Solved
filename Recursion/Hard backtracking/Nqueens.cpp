#include<iostream>
#include<string>
#include<vector>
using namespace std;
// bool isSafe(int row, int col, vector<string>&board, int n){
//     int roww = row-1;
//     int coll = col-1;

//     //upper diagonal
//     while(roww>=0 && coll>=0){
//         if(board[roww][coll]=='Q') return false;
//         --roww;
//         --coll;
//     }

//     roww = row;
//     coll = col-1;

//     //same level
//     while(coll>=0){
//         if(board[roww][coll]=='Q') return false;
//         --coll;
//     }

//     roww = row+ 1;
//     coll = col-1;


//     //lower diagonal
//     while(roww<n && coll>=0){
//         if(board[roww][coll]=='Q') return false;
//         ++roww;
//         --coll;
//     }

//     return true;

// }


// void dfs(vector<string>&board,vector<vector<string>>& ans,int n, int col){
//     if(col==n){
//         ans.push_back(board);
//         return;
//     }
//     for(int row=0; row<n;++row){
//         if(isSafe(row,col,board,n)){
//             board[row][col] ='Q';
//             dfs(board,ans,n,col+1);
//             board[row][col] ='.';
//         }
//     }
// }


void dfs(int col,
         int n,
         vector<string>& board,
         vector<vector<string>>& ans,
         vector<int>& leftRow,
         vector<int>& lowerDiag,
         vector<int>& upperDiag) {

    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        // O(1) safety check
        if (leftRow[row] == 0 &&
            lowerDiag[row + col] == 0 &&
            upperDiag[n - 1 + col - row] == 0) {

            // PLACE
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[n - 1 + col - row] = 1;

            dfs(col + 1, n, board, ans, leftRow, lowerDiag, upperDiag);

            // REMOVE (BACKTRACK)
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    // helpers
    vector<int> leftRow(n, 0);
    vector<int> lowerDiag(2 * n - 1, 0);
    vector<int> upperDiag(2 * n - 1, 0);

    dfs(0, n, board, ans, leftRow, lowerDiag, upperDiag);
    return ans;
}

// vector<vector<string>> solveNQueens(int n) {
//     vector<vector<string>> ans;
//     vector<string> board(n, string(n, '.'));
//     dfs(board,ans,n,0);
//     return ans;        
//     }

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<vector<string>> recAns = solveNQueens(n);
      for (const auto& t : recAns) {
     
        for (auto x : t) {
            cout << x << " " << endl;
        }
        cout <<  endl;
    }
cout << recAns.size() << endl;
        return 0;


}