#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    private:
    vector<int>size, parent;

    public:
    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i=0; i<n+1; ++i){
            parent[i] = i;
        }
    }

    //compression
    int finduPar(int x){
        if(parent[x] == x) return x;
        return parent[x] = finduPar(parent[x]);
    }

    void unionBySize(int u, int v){
        
        int Pu = finduPar(u);
        int Pv = finduPar(v);
        if(Pu==Pv) return;

        if(size[Pu]>= size[Pv]){
            parent[Pv] = Pu;
            size[Pu] += size[Pv];
        }else{
            parent[Pu] = Pv;
            size[Pv]+= size[Pu];
        }
    }


};
  int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; //minheap
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        pq.push({grid[0][0],{0,0}});
        dist[0][0] =grid[0][0];

        int dRow[] = {0,0,1,-1};
        int dCol[] = {1,-1,0,0};

        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            int nodeWt = p.first; auto [row, col] = p.second;
            if(row == n-1 && col == n-1) return nodeWt;
            if(nodeWt > dist[row][col]) continue;

            for(int k=0; k<4; ++k){
                int nRow = row +dRow[k];
                int nCol = col+ dCol[k];
                if(nRow>=0 && nCol >=0 && nRow<n && nCol <n ){
                    int newWt = max(nodeWt , grid[nRow][nCol]);
                    if(newWt < dist[nRow][nCol]){
                    dist[nRow][nCol] = newWt;
                    pq.push({newWt,{nRow,nCol}});
                    }
                }
            }

        }

        return -1;
    }

    //Union Method: Kruskal derivative:
     int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==1) return grid[0][0];
        vector<pair<int,pair<int,int>>> edges;
        int dRow[] = {0,1};
        int dCol[] = {1,0};

        for(int row=0; row<n; ++row){
            for(int col=0; col<n; ++col){
                int nodeWt = grid[row][col];
                int u = row*n+col;
               
                 for(int k=0; k<2; ++k){
                int nRow = row +dRow[k];
                int nCol = col+ dCol[k];
                if(nRow>=0 && nCol >=0 && nRow<n && nCol <n ){
                    int newWt = max(nodeWt , grid[nRow][nCol]);
                    int v = nRow*n + nCol;
                    edges.push_back({newWt,{u,v}});                  
                }
            }
                
            }
        }
        sort(edges.begin(), edges.end());        
        DisjointSet ds(n*n);

        for(auto& edge: edges){
            int wt = edge.first;
             int u = edge.second.first;
             int v = edge.second.second;
             ds.unionBySize(u,v);
              if(ds.finduPar(0) == ds.finduPar(n*n-1))
              return wt;
        }
        return -1;
    }
