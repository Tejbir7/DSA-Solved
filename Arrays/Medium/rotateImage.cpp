#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
           swap(matrix[i][j],matrix[j][i]);           
        }
    }
    for(int i=0;i<n;i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    return;
    }
int main(){
     int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> matrix(n);
    cout << "Enter values: ";
    for(int x=0;x<n;x++){
        cin >> matrix[x];
    }
   
 for(int x=0;x<n;x++){
        cout << matrix[x] << " ";
    }

    return 0;
}