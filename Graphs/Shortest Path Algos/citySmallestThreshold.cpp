#include<bits/stdc++.h>
using namespace std;
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<long long>> cost(n,vector<long long>(n,1e9));

    for(auto &p: edges){
        int u = p[0], v = p[1] , wt = p[2];
        cost[u][v] = wt;
        cost[v][u] = wt;
    }

    for(int i=0; i<n; ++i){
       cost[i][i] = 0;
    }

    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
              cost[i][j] = min(cost[i][j], 1LL* (cost[i][k]+ cost[k][j]));
            }
        }
    }

    vector<int> count(n,0);

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(cost[i][j]<=distanceThreshold) ++count[i];
        }
    }
    int mini = INT_MAX;
    int ans = 0;
    for(int i=0; i<n; ++i){
        if(count[i]<=mini) {
            ans = i;
            mini = count[i];
        }
    }
        return ans;
    }

    //slight space efficient
     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<long long>> cost(n,vector<long long>(n,1e9));

    for(auto &p: edges){
        int u = p[0], v = p[1] , wt = p[2];
        cost[u][v] = wt;
        cost[v][u] = wt;
    }

    for(int i=0; i<n; ++i){
       cost[i][i] = 0;
    }

    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
              cost[i][j] = min(cost[i][j], 1LL* (cost[i][k]+ cost[k][j]));
            }
        }
    }

    vector<int> count(n,0);

    int ans = 0; 
    int mini = INT_MAX;

    for(int i=0; i<n; ++i){
        int cnt = 0;
        for(int j=0; j<n; ++j){
            if(cost[i][j]<=distanceThreshold) {
                ++cnt;
            }
        }
        if(cnt<=mini) {
            mini = cnt;
            ans = i;
        }

    }
        return ans;
    }
