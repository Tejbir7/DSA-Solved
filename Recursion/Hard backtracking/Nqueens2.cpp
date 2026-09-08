#include<bits/stdc++.h>
using namespace std;
//passes
class Solution {
    int count = 0;
    bool check(int i, int j, int n,vector<vector<int>> &nums){
        //vertical check
        int row = i, col = j;
        while(row>=0){
            if(nums[row--][col]) return false; 
        }
        //right diagonal
        row = i, col = j;
        while(row>=0 && col <n){
            if(nums[row--][col++]) return false;
        }
         row = i, col = j;
          while(row>=0 && col >=0){
            if(nums[row--][col--]) return false;
        }
        return true;
    }

    void f(int i, int j, int n, vector<vector<int>> &nums ){
    if(i>=n || j>=n) return;

    for(int k=j ; k<n; ++k){
        if(check(i,k,n,nums)){

            if(i == n-1){
                 ++count;
            }
            else{
            nums[i][k] = 1;
            f(i+1,0,n,nums);
            nums[i][k] = 0;
            }
        }
    }
   }
public:
    int totalNQueens(int n) {
       vector<vector<int>> nums(n, vector<int>(n, 0));
       f(0,0,n,nums);
       return count;
    }
};

class Solution {
    int count = 0;
    bool check(int i, int j, int n,vector<vector<int>> &nums){
        //vertical check
        int row = i, col = j;
        while(row>=0){
            if(nums[row--][col]) return false; 
        }
        //right diagonal
        row = i, col = j;
        while(row>=0 && col <n){
            if(nums[row--][col++]) return false;
        }
         row = i, col = j;
          while(row>=0 && col >=0){
            if(nums[row--][col--]) return false;
        }
        return true;
    }

    void f(int i, int n, vector<vector<int>> &nums ){
     if (i == n) {
            ++count;
            return;
        }

    for(int k=0 ; k<n; ++k){
        if(check(i,k,n,nums)){

           
            nums[i][k] = 1;
            f(i+1,n,nums);
            nums[i][k] = 0;
            
        }
    }
   }
public:
    int totalNQueens(int n) {
       vector<vector<int>> nums(n, vector<int>(n, 0));
       f(0,n,nums);
       return count;
    }
};