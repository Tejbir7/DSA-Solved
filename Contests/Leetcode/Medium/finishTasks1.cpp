#include<bits/stdc++.h>
using namespace std;
//earliest be the minimum
//latest be the maximum
long long dfs(int node, vector<vector<int>>&adj, vector<int>& baseTime  ){
    if(adj[node].size() == 0) return baseTime[node];
    long long mini = INT_MAX;
    long long maxi = INT_MIN;
    for(auto nei: adj[node]){
        long long t = dfs(nei,adj,baseTime);
        mini = min(mini, t );
        maxi = max(maxi, t);
    }
    return ((2*maxi) - mini + baseTime[node]) ;    
}
 long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
    //creating adj
    vector<vector<int>> adj(n);
    for( auto &p: edges){
        int u = p[0];
        int v = p[1];
        adj[u].push_back(v);
        }

        long long finishTime = dfs(0,adj,baseTime);
        return finishTime;
    }