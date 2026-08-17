#include<bits/stdc++.h>
using namespace std;
vector<int>KahnsAlgo(vector<vector<int>>&adj){
    int n = adj.size();
    vector<int>indegree(n,0);
    //Forming indegree arr
    for(const auto &i: adj){
        for(auto j: i){
            ++indegree[j];
        }
    }

    //forming q
    queue<int>q;
    for(int i=0; i<indegree.size(); ++i){
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

    return topo;

}