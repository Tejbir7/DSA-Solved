#include<bits/stdc++.h>
using namespace std;
 long long minCost(int m, int n, vector<vector<int>>& penalty) {
        
    using ll = long long;
    vector<vector<vector<ll>>> dist(m, vector<vector<ll>>(n,vector<ll>(2,LLONG_MAX)));
    //row,col,parity

    dist[0][0][0] = 1;
    using state = array<ll,4>;
    priority_queue<state, vector<state>, greater<state>> pq;
    //cost, row, col , par
    pq.push({1,0,0,0});

    int dRow[] = {0,1,0,-1};
    int dCol[] = {1,0,-1,0};

    while(!pq.empty()){
        auto [cost,row,col,par] = pq.top();
        pq.pop();

        if(dist[row][col][par]< cost) continue;
        if(row== m-1 && col == n-1) return cost;

        ll waitingCost = cost + penalty[row][col];

        if(waitingCost < dist[row][col][!par]){
            pq.push({waitingCost,row,col,!par});
            dist[row][col][!par] = waitingCost;
        }

        for(int k=0; k<4; ++k){
            int nRow = row + dRow[k];
            int nCol = col + dCol[k];

            if(nRow<0 || nRow>=m || nCol <0 || nCol>=n) continue;

            ll newCost = (nRow+1)*(nCol+1) + cost;

            //par == odd(right/down) && !par == even (left/up)
            if(!par && k>1){
                newCost = newCost + penalty[row][col];
            }
            if(par && k<2){
                newCost = newCost + penalty[row][col];
            }

            if(newCost< dist[nRow][nCol][!par]){
                pq.push({newCost,nRow,nCol,!par});
                dist[nRow][nCol][!par] = newCost;
            }

        }


    }

    return min(dist[m-1][n-1][0],dist[m-1][n-1][1]);
    }