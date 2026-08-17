#include<bits/stdc++.h>
using namespace std;
void minPath(const vector<vector<pair<int,int>>>&adj, int S, vector<int>&minList){

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    pq.push({0,S});
    minList[S] = 0;

    while(!pq.empty()){
        auto [dist,node] = pq.top();
        pq.pop();

        if(dist> minList[node]) continue;

        for(auto [nei,wt]: adj[node]){
            int newDist = dist+wt;
            if(minList[nei]>newDist){
                minList[nei] = newDist;
                pq.push({newDist,nei});
            }
            
        }
        
    }
 
}
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &e : times){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].push_back({v,w});

            //Here graph is directed so we wouldnt do: adj[v].push_back({u,,w});
        }
        vector<int>minList(n+1,INT_MAX);
        minPath(adj,k,minList);

        int maxi = *max_element(minList.begin()+1,minList.end()); 
        if(maxi==INT_MAX) return -1;
        return maxi;
    }