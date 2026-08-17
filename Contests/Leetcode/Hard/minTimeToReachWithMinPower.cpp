#include<bits/stdc++.h>
using namespace std;
//gives tle
 vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
    if (source == target) return {0, power};
    //creates adj
    vector<vector<pair<int,int>>> adj(n);
    for(auto&p : edges){
        int u = p[0], v = p[1], time = p[2];
        adj[u].push_back({v,time});
    }

    // {time,node,remainingPower}
    priority_queue< vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
    //dist[node][remaining power]
    vector<vector<long long>> dist(n,vector<long long>(power+1,LLONG_MAX));
    pq.push({0,source,power});
    dist[source][power] = 0;

    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        
        long long currTime = p[0];
        int node = p[1], powerLeft = p[2];
        
        if (currTime > dist[node][powerLeft]) continue;
        if (powerLeft < cost[node]) continue;

        int newPower = powerLeft - cost[node];

        for(auto[nei,wt] : adj[node]){

            long long newTime = currTime+ wt;
           // if(newTime < dist[nei][newPower]  && newPower >= cost[nei])
            if(newTime < dist[nei][newPower]) {
                dist[nei][newPower] = newTime;
                pq.push({newTime,nei,newPower});
            }
        }
    }

    long long minTime = LLONG_MAX;
    int maxPower = INT_MIN;
    for(int i=0; i<=power; ++i ){

        if(dist[target][i] < minTime){
        minTime = dist[target][i];
        maxPower = max(maxPower,i);
    } 
    else if (dist[target][i] == minTime) {
        maxPower = max(maxPower, i);
    }
}
if(minTime== LLONG_MAX) return {-1,-1};
else return {minTime,maxPower};
    }

    //better
    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
    if (source == target) return {0, power};
    //creates adj
    vector<vector<pair<int,int>>> adj(n);
    for(auto&p : edges){
        int u = p[0], v = p[1], time = p[2];
        adj[u].push_back({v,time});
    }

    // {time,-remainingPower,node}
    priority_queue< vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;
    //dist[node][remaining power]
    vector<vector<long long>> dist(n,vector<long long>(power+1,LLONG_MAX));
    pq.push({0,-power,source});
    dist[source][power] = 0;

    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        
        long long currTime = p[0];
        int powerLeft = -p[1], node = p[2];
         if (node == target) {
                return {currTime, powerLeft};
            }
        if (currTime > dist[node][powerLeft]) continue;
        if (powerLeft < cost[node]) continue;

        int newPower = powerLeft - cost[node];

        for(auto[nei,wt] : adj[node]){

            long long newTime = currTime+ wt;
           // if(newTime < dist[nei][newPower]  && newPower >= cost[nei])
            if(newTime < dist[nei][newPower]) {
                dist[nei][newPower] = newTime;
                pq.push({newTime,-newPower, nei});
            }
        }
    }

 return {-1, -1};
    }