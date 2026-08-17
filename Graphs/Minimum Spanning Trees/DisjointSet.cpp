#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    private:
    vector<int> rank, parent, size;

    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; ++i){
            parent[i] = i;
        }
        size.resize(n+1,1);
    }

    //Path compression 
    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int uPu = findUPar(u);
        int uPv = findUPar(v);
        if(uPu==uPv) return;
        if(rank[uPu]<rank[uPv]) parent[uPu] = uPv;
       else if(rank[uPu]>rank[uPv]) parent[uPv] = uPu;
       else{
        parent[uPv] = uPu;
        rank[uPu]++;
       }

    }

     void unionBySize(int u, int v){
        int uPu = findUPar(u);
        int uPv = findUPar(v);
        if(uPu==uPv) return;
        if(size[uPu]<=size[uPv]) {
            parent[uPu] = uPv;
            size[uPv] += size[uPu];
        }
       else{
        parent[uPv] = uPu;
       size[uPu] += size[uPv];
       }

    }
//Either use rank for all operations or size for all operations, but dont use both

};