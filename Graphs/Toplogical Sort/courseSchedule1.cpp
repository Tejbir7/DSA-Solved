 #include<bits/stdc++.h>
 using namespace std;
 bool dfs(vector<vector<int>> &adj, vector<int>&visited, int node){
        visited[node] = 1;
        for(auto i: adj[node]){
            if(!visited[i]){
                if(!dfs(adj,visited,i)) return false;
            }
            else if(visited[i]==1) return false;
        }
        visited[node] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses,0);
        for(auto &p: prerequisites){ //if not used reference, new vector created everytime, memory wasted
            int a = p[0] , b = p[1];
            adj[b].push_back(a);
        }

        for(int start =0; start< numCourses; ++start){
            if(!visited[start]){
                if(!dfs(adj,visited,start)) return false;
            }
        }
        return true;

    }