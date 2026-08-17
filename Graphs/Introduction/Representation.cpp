#include<bits/stdc++.h>
using namespace std;
// n = no of nodes
// m = no of edges
// wt = weight of edge
//u and v = array indexing 
void matrixUnweighted(){
     int n, m;
    cin >> n>> m;   
   vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    for(int i= 0; i< m; ++i ){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    } 
    return;
}
void matrixWeighted(){
     int n, m;
    cin >> n>> m;   
   vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
    for(int i= 0; i< m; ++i ){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u][v] = wt;
        adj[v][u] = wt;
    } 
    return;
}
void listUnweighted(){
    int n, m;
    cin >>n >>m;
   vector<vector<int>> adj(n+1);
    for(int i=0; i<m; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return;
}
int main(){
    

    
}