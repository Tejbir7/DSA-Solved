#include<bits/stdc++.h>
using namespace std;
  bool isBipartiteBFS(vector<vector<int>>& graph) {
    int n = graph.size();
     vector<int> color(n,-1);

     for(int start =0; start<n; ++start){
        if(color[start]!= -1) continue;

        queue<int> q;
        q.push(start); 
        color[start] = 0;

         while(!q.empty()){
            int node = q.front(); q.pop();

            for(int i: graph[node]){
                if(color[i] == -1){
                    color[i] = 1 - color[node];
                    q.push(i);
                }
                else if(color[i]==color[node]){
                    return false;
                }
            }
        }
     }
     return true;
    }
    bool dfs(vector<vector<int>>& graph,vector<int>& color, int node, int state ){
        color[node] = state;
        for(int i: graph[node]){
            if(color[i]== -1){
               if( !dfs(graph,color,i,!state)) return false;
            }
            else if(color[i]==color[node]){
                return false;
            }
        } 
        return true;
    }

      bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
      

        for(int start =0; start<n; ++start){
            if(color[start]==-1){
              if(  !dfs(graph,color,start, 0)) return false;
            }            
        }
        return true;
    }