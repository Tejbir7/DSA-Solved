#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> minD(vector<vector<int>>& adj){
    vector<vector<int>> cost = adj;
    int n = cost.size();

    for(int i=0; i<n;++i){
        for(int j=0; j<n; ++j) {
            if(cost[i][j] == -1) cost[i][j]= INT_MAX;
            if(i==j) cost[i][j] = 0;
        }
        
    }

    //Floyd warshall
    
    for(int k=0; k<n; ++k){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(cost[i][k]!= INT_MAX && cost[k][j]!= INT_MAX)
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);

            }
        }
    }
     //-ve detection
    for(int i=0; i<n; ++i){
        if(cost[i][i]<0) return {{-1}};
    }

    //for disconnected components
    for(int i=0; i<n;++i){
        for(int j=0; j<n; ++j) {
            if(cost[i][j] == INT_MAX) cost[i][j]= -1;

        }
     }

   

    return cost;
}