#include<bits/stdc++.h>
using namespace std;

//visited[i] == 1 → seen before (useless info)
//path[i] == 1 → currently in recursion stack (important)
bool dfscheck(vector<vector<int>>& adjList, vector<int> &visited, vector<int> &path, int node){
    visited[node] =1;
    path[node] =1;
    for(int i : adjList[node]){
        if(!visited[i]){
            if(dfscheck(adjList, visited,path, i)) return true;
        }
        //been visited, but hasnt been visited on same path 
        else if(path[i]) return true;
     
    }
    path[node] = 0;
    return false;
}
bool hasCycle(vector<vector<int>>& adjList){
    int n = adjList.size();
    vector<int>visited(n,0);
    vector<int>path(n,0);
    for(int start =0; start <n; ++start){
        if(!visited[start]){
            if( dfscheck(adjList,visited,path, start)) return true;
        }
    }
return false;
}

//more optimised:
bool dfs(int node, vector<vector<int>>& adj, vector<int>& state){
  // 0: never seen
  //1: currently in dfs path
  //2: completely processed
  
    state[node] = 1; // visiting

    for(int i : adj[node]){
        if(!state[i]){
        if(dfs(i, adj, state)) return true;
    }
    else if(state[i]==1) return true;
}

    state[node] = 2; // done
    return false;
}
