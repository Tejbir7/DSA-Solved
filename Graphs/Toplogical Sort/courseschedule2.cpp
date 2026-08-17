#include<bits/stdc++.h>
using namespace std;

 vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<int>indegree(numCourses,0);

        vector<vector<int>> adj(numCourses);
        for(const auto &p: prerequisites ){
            int v = p[0];
            int u = p[1];
            adj[u].push_back(v);
            ++indegree[v];
        }

    //forming q
    queue<int>q;
    for(int i=0; i< numCourses; ++i){
        if(!indegree[i]) q.push(i);
    }

    vector<int>topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(int i: adj[node]){
            --indegree[i];
            if(!indegree[i]) q.push(i);
        }
    }

    return topo.size()==numCourses ? topo : vector<int>() ;

    }