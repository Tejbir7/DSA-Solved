#include<bits/stdc++.h>
using namespace std;
int countPaths(int n, vector<vector<int>>& roads) {
      vector<vector<pair<int,int>>> adj(n);
     //creating ADJ
      for(auto &p: roads){
        int u = p[0];
        int v = p[1];
        int time = p[2];
        //[nei,wt]
        adj[u].push_back({v,time}); 
        adj[v].push_back({u,time});  
    }

    vector<long long> dist(n,LLONG_MAX);
    dist[0] = 0;
    vector<long long> ways(n,0);
    ways[0] = 1;

    priority_queue< pair<long long,int> , vector<pair<long long, int>>, greater<pair<long long, int>>> pq;  // {dist, node}

    pq.push({0,0});
   const int modi = (int) 1e9 +7;

    while(!pq.empty()){
        auto [d, node] = pq.top(); pq.pop();

        if(dist[node]<d) continue;

        for(auto [nei, wt] : adj[node] ){
            long long newDist = d+wt;
            if(newDist< dist[nei]){
                dist[nei] = newDist;
                ways[nei] = ways[node];
                pq.push({newDist,nei});
            } 
            else if(newDist == dist[nei]){
                ways[nei] = (ways[node] + ways[nei]) % modi;
            }
        }

    }
    return ways[n-1] % modi;
    }