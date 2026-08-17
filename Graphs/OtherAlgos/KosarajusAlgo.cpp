#include<bits/stdc++.h>
using namespace std;
//Return list of strongly connected components
void dfs(vector<vector<int>>&adj, vector<int> &visited, vector<int>&finishTime, int node){
    visited[node] = 1;
    for(int nei: adj[node]){
        if(!visited[nei]) dfs(adj,visited,finishTime,nei);
    }
    finishTime.push_back(node);
}
void LetsCreate(vector<vector<int>>&adj, vector<int> &visited, int node, vector<int>&temp){
    visited[node] = 1;
    temp.push_back(node);
    for(int nei: adj[node]){
        if(!visited[nei]) LetsCreate(adj,visited,nei, temp);
    }
}

vector<vector<int>> stronglyConnected(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int> visited(n,0);
    vector<int> finishTime;
    //firstDFS
    for(int i=0; i<n; ++i){
        if(!visited[i]){
            dfs(adj,visited,finishTime,i);
        }
    }
    //reverse graph
    vector<vector<int>>reversed(n);
    for(int u=0; u<n; ++u){
        for(int v: adj[u]){
            reversed[v].push_back(u);
        }
    }
    for(int i=0; i<n; ++i) visited[i] = 0;
    vector<vector<int>> ans;

    for(int i= n-1; i>=0; i--){
        int node = finishTime[i];
        if(!visited[node]){
             vector<int> temp;
             LetsCreate(reversed,visited,node,temp);
             ans.push_back(temp);                        
        }
    }
    return ans;
}