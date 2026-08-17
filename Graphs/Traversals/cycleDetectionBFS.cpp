#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//for only connected and undirected graphs
bool detectCycle(vector<vector<int>>& adjList, int src, vector<int>& visited){

    queue<pair<int,int>> q;
    q.push({src,-1});
    visited[src] = 1;

    while(!q.empty()){
        auto Pair = q.front();
        q.pop();

        int node = Pair.first;
        int parent = Pair.second;

        
        for(auto it: adjList[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push({it,node});
            }
            else if(parent!= it){
                return true;
            }
        }
    }
return false;
}

//V = vertices
bool detectCycleGraph(vector<vector<int>> & adjList, int V){
  //  int n = adjList.size(); n = V 
  //if V not given then calculate n
    vector<int> visited(V,0);
    for(int i=0; i<V; ++i){
        if(!visited[i]){
            if(detectCycle(adjList, i, visited)) return true;

        }
    }
    return false;
}