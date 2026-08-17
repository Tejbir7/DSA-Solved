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

 vector<vector<pair<int,int>>> KruskalsAlgo(const vector<vector<pair<int,int>>>&adj){
    int n = adj.size();

    //Forming list of edges
    vector<vector<int>> Edges;
    for(int u=0; u<n ;++u){
       for(auto [v,wt]: adj[u]){
        if(u<v) Edges.push_back({wt,u,v});  //To prevent duplicate edges, which inc complexity 
       }
    }

       sort(Edges.begin(), Edges.end());
        DisjointSet ds(n);

       vector<vector<pair<int,int>>> tree(n);

       for(auto &p: Edges){
        int wt= p[0] , u = p[1] , v = p[2];
        if(ds.findUPar(u) != ds.findUPar(v)){
            ds.unionByRank(u,v);
            tree[u].push_back({v,wt});
            tree[v].push_back({u,wt});
        }
    }
    return tree;

       }
    





  
