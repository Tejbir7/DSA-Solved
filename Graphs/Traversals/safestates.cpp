#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<vector<int>>& graph, vector<int>& visited, int node) {
    if(visited[node] == 1) return false; // cycle
    if(visited[node] == 2) return true;  // already safe

    visited[node] = 1;

    for(int i : graph[node]) {
        if(!dfs(graph, visited, i)) return false;
    }

    visited[node] = 2;
    return true;
}
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n,0);
    vector<int> result;

    for(int start =0; start<n; ++start){
            if(dfs(graph, visited, result, start)) {
                  result.push_back(start);
            }
        
    }
     return result;
}

    //Another version
    bool dfs(vector<vector<int>>&graph,vector<int> &visited, vector<int> &result, int node){
  visited[node] =1;
  for(int i: graph[node]){
    if(!visited[i]){
        if(!dfs(graph,visited,result,i)) return false;
    }
    else if(visited[i]==1) return false;
  }
  visited[node] =2;
  result.push_back(node);
  return true;
}
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n,0);
    vector<int> result;
    for(int start =0; start<n; ++start){
        if(!visited[start]){
           dfs(graph,visited,result,start);
        }
    }
    sort(result.begin(),result.end());
        return result;
    }

