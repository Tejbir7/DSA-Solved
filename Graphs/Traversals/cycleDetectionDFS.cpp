#include<iostream>
#include<vector>
using namespace std;

bool dfs(vector<vector<int>> &adjList,vector<int>&visited, int node, int parent){
    visited[node] = 1;

    for(auto it: adjList[node]){
        if(!visited[it]){
            if(dfs(adjList,visited,it,node)) return true;
        }
        else if(it!= parent) return true;
    }
    return false;
}
bool cycleDetection(vector<vector<int>> &adjList){
    int n = adjList.size();
    vector<int> visited(n,0);
    for(int i=0; i<n; ++i){
        if(!visited[i]){
            if(dfs(adjList,visited,i,-1)) return true;
        }
    }
    return false;
}