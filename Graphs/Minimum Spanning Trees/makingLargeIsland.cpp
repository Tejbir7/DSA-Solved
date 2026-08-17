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

    int getSize(int node){
        int root = finduPar(node);
        return size[root];
    }

};



   int largestIsland(vector<vector<int>>& grid) {
     int n = grid.size();
    DisjointSet ds(n*n);

     int dRow[] = {-1,0,1,0};
     int dCol[] = {0,1,0,-1};


      bool hasZero = false;
    for(int row =0; row<n; ++row){
        for(int col =0; col<n; ++col){
            if(!grid[row][col]){
                hasZero = true;
                  continue;
            }

             int node = row*n + col;

            for(int k=0; k<2; ++k){
                int nRow = row+ dRow[k];
                int nCol = col+ dCol[k];

                if(nRow>=0 && nCol>=0 && nRow <n && nCol<n && grid[nRow][nCol]==1){
                    int nei = nRow*n + nCol;
                    ds.unionBySize(node,nei);
                } 
            }

        }
    }
    if(!hasZero) return n*n;
   
    int ans =0;
    for(int row=0; row<n; ++row){
        for(int col=0; col<n; ++col){
            if(grid[row][col]==0){
                unordered_set<int> parents;
                for(int k=0; k<4; ++k){
                    int nRow = row + dRow[k];
                    int nCol = col + dCol[k];

                    if(nRow>=0 && nCol>=0 && nRow < n && nCol < n && grid[nRow][nCol]==1){
                        int nei = nRow*n + nCol;
                        parents.insert(ds.finduPar(nei));
                    } 
                }
                int currSize = 1;
                for(auto it: parents){
                    currSize += ds.getSize(it);
                }
                ans = max(ans, currSize);
            }
        }
    }
return ans;        
    }