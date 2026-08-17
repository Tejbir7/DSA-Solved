#include<bits/stdc++.h>
using namespace std; 

     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
           vector<vector<pair<int,int>>> adj(n);
     //creating ADJ
      for(auto &p: flights){
        int from = p[0];
        int to = p[1];
        int price = p[2];
        adj[from].push_back({to,price});
    }

    vector<int> dist(n,INT_MAX);    
    queue<vector<int>> q;    //{stops,node,dist}
    q.push({0,src,0});
    dist[src] = 0;

    while(!q.empty()){
        auto p = q.front();  q.pop();
        int stops = p[0] , node = p[1], d = p[2];
        if(stops>k ) continue;
    
            for(auto [nei,wt] : adj[node]){
                 int newDist = d+wt;
                if(dist[nei]> newDist){
                    dist[nei] = newDist;
                    q.push({stops+1, nei, newDist});
                }
            }
      
    }

return dist[dst] == INT_MAX ? -1 : dist[dst];  
    }