#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> &isConnected, vector<int>&visited, int i){
    visited[i] =1;
    for(int j=0; j<isConnected.size(); ++j){
        if(isConnected[i][j] && !visited[j]){
            dfs(isConnected, visited, j);
        }
    }
}
  int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> visited(n,0);
    int count = 0;
    for(int i=0; i<n; ++i){
        if(!visited[i]){
            ++count;
            dfs(isConnected, visited, i);
        }
    }
        return count;
    }