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

  int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size()<n-1) return -1;
    DisjointSet ds(n);
    int count = 0;
    for(auto &p : connections){
        int a = p[0], b = p[1];
        if(ds.finduPar(a) != ds.finduPar(b)){
            ds.unionBySize(a,b);
        }else{
            ++count;
        }

    }
    
    int disconnected = 0;
    for(int i=0; i<n; ++i){
        if(ds.finduPar(i)==i){
            ++disconnected;
        }
    }
    return count -(count - (disconnected-1));        
    } 

    //Even Better
      int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size()<n-1) return -1;
    DisjointSet ds(n);
   
    for(auto &p : connections){
        int a = p[0], b = p[1];
      
            ds.unionBySize(a,b);
    }
    
    int separate = 0;
    for(int i=0; i<n; ++i){
        if(ds.finduPar(i)==i){
            ++separate;
        }
    }
    return separate-1;        
    }
