#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& adj, int src){
    int n = adj.size();
    vector<int>d(n,INT_MAX);

    queue<pair<int,int>> q;    //{node,dist}
    q.push({src,0});
    d[src] = 0;

    while(!q.empty()){
        auto [node,dist]= q.front();
        q.pop();

        for(auto it: adj[node]){
            if(d[it]> dist+1){
                q.push({it,dist+1});
                d[it] = dist+1;
            }
        }              

    }

    return d;

}
//better
vector<int> shortestPathQ(vector<vector<int>>& adj, int src){
    int n = adj.size();
    vector<int>d(n,INT_MAX);

    queue<int> q;    //node
    q.push(src);
    d[src] = 0;

    while(!q.empty()){
        auto node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(d[it] == INT_MAX){
                q.push(it);
                d[it] = d[node] +1;
            }
        }              

    }

    return d;

}
