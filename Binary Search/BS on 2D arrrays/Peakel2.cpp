#include<iostream>
#include<climits>
#include<vector>
using namespace std;
int maxEl(vector<vector<int>>&mat,int col){
    int n= mat.size();
    int maxVal=INT_MIN;
    int idx = -1;
    for(int r=0;r<n;++r){
        if(mat[r][col]>maxVal){
            maxVal= mat[r][col];
            idx = r;
        }
    }
    return idx;
}
  
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n= mat.size();
     if (n == 0) return {-1, -1};
    int m = mat[0].size();
    if (m == 0) return {-1, -1};

    int low = 0,high = m-1;
    while(low<=high){
        int midCol = low+((high-low)>>1);
        int row = maxEl(mat,midCol);
        int curr = mat[row][midCol];
        int left = midCol - 1 >= 0 ? mat[row][midCol - 1] : INT_MIN;
        int right = midCol + 1 < m ? mat[row][midCol + 1] : INT_MIN;
       if(curr>left&&curr>right) return {row,midCol};
        else if(curr<left)   high=midCol-1;       
        else if(curr>left) low = midCol+1;    
        else return {row,midCol};    
    }
    return {-1,-1};        
    }

     int main() {
      // Example usage
      vector<vector<int>> mat = {
          {4, 2, 5, 1, 4, 5},
          {2, 9, 3, 2, 3, 2},
          {1, 7, 6, 0, 1, 3},
          {3, 6, 2, 3, 7, 2}
      };
  
      // Call findPeakGrid function and print the result
      vector<int> peak = findPeakGrid(mat);
      cout << "The row of peak element is " << peak[0]
           << " and column of the peak element is " << peak[1] << endl;
  
      return 0;
  }
