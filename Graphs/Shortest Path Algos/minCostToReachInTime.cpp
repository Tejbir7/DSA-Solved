#include<bits/stdc++.h>
using namespace std;

//Dont make same mistake: we need min fee in reqd time 
//Gives TLE
int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    int n = passingFees.size();
     //creates adj
    vector<vector<pair<int,int>>> adj(n);
    for(auto&p : edges){
        int u = p[0], v = p[1], time = p[2];
        adj[u].push_back({v,time});
        adj[v].push_back({u,time});
    }

    //{cost,time,node}
    priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({passingFees[0],0,0});

    //dist[node][fees] not feasible

    //dist[node][time] = minimum fee, more feasible
    vector<vector<int>> dist(n,vector<int>(maxTime+1,1e9));
    dist[0][0] = passingFees[0];

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();
        int currFee = p[0], currTime = p[1], node = p[2];

        if(node== n-1) return currFee;
        if(currTime > maxTime) continue;
        if(dist[node][currTime] < currFee ) continue;

        
        for(auto[nei, wt]: adj[node]){
            int newTime = currTime + wt;
            int newFee =  currFee + passingFees[nei];
            
            if(newTime<= maxTime && newFee < dist[nei][newTime]){
                pq.push({newFee,newTime,nei});
                dist[nei][newTime] = newFee;
            }
            
        }

    }
return -1;        
    }

    //ILLOGICAL
    //1D arr optimised
//     int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
//     int n = passingFees.size();
//      //creates adj
//     vector<vector<pair<int,int>>> adj(n);
//     for(auto&p : edges){
//         int u = p[0], v = p[1], time = p[2];
//         adj[u].push_back({v,time});
//         adj[v].push_back({u,time});
//     }

//     //{cost,time,node}
//     priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
//     pq.push({passingFees[0],0,0});

//     //dist[node] = minimum time, more feasible
//     vector<int> dist(n,INT_MAX);
//     dist[0] = 0;

//     while(!pq.empty()){
//         auto p = pq.top();
//         pq.pop();
//         int currFee = p[0], currTime = p[1], node = p[2];

//         if(node== n-1) return currFee;
//         if(currTime > maxTime || dist[node]< currTime) continue;
      
//         for(auto[nei, wt]: adj[node]){
//             int newTime = currTime + wt;
//             int newFee =  currFee + passingFees[nei];
            
//             if(newTime<= maxTime && newTime < dist[nei]){
//                 pq.push({newFee,newTime,nei});
//                 dist[nei] = newTime;
//             }
            
//         }

//     }
// return -1;        
//     }

int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    int n = passingFees.size();
     //creates adj
    vector<vector<pair<int,int>>> adj(n);
    for(auto&p : edges){
        int u = p[0], v = p[1], time = p[2];
        adj[u].push_back({v,time});
        adj[v].push_back({u,time});
    }

    //{cost,time,node}
    using state = array<int,3> ;
    priority_queue< state, vector<state>, greater<state>> pq;
    pq.push({passingFees[0],0,0});

    //dist[node][fees] not feasible

    //dist[node][time] = minimum fee, more feasible
    vector<vector<int>> dist(n,vector<int>(maxTime+1,1e9));
    dist[0][0] = passingFees[0];

    while(!pq.empty()){
        auto [currFee, currTime, node] = pq.top();
        pq.pop();

        if(node== n-1) return currFee;
        if(currTime > maxTime) continue;
        if(dist[node][currTime] < currFee ) continue;

        
        for(auto[nei, wt]: adj[node]){
            int newTime = currTime + wt;
            int newFee =  currFee + passingFees[nei];
            
            if(newTime<= maxTime && newFee < dist[nei][newTime]){
                pq.push({newFee,newTime,nei});
                dist[nei][newTime] = newFee;
            }
            
        }

    }
return -1;        
    }

    //dp soln 
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    int n = passingFees.size();
     //creates adj
    vector<vector<pair<int,int>>> adj(n);
    for(auto&p : edges){
        int u = p[0], v = p[1], time = p[2];
        adj[u].push_back({v,time});
        adj[v].push_back({u,time});
    }

    //dist[node][time] = minimum fee, more feasible
    vector<vector<int>> dp(n,vector<int>(maxTime+1,1e9));
    dp[0][0] = passingFees[0];
    for(int time = 0; time<= maxTime; ++time){
        for(int node=0; node <n ; ++node){
            if (dp[node][time] == 1e9) continue;

            for(auto [nei,wt] : adj[node]){
                int newTime = time+wt;
                if(newTime> maxTime) continue;
                dp[nei][newTime] = min(dp[nei][newTime], dp[node][time]+passingFees[nei]);
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<=maxTime; ++i){
       ans = min(ans, dp[n-1][i]);
    }   
    if(ans == 1e9) return -1;
    return ans;   
    }