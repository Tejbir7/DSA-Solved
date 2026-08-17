#include<bits/stdc++.h>
using namespace std;
 vector<vector<pair<int,int>>> PrimsAlgo(const vector<vector<pair<int,int>>>&adj){
    int n = adj.size();

    vector<int> visited(n,0);
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    vector<vector<pair<int,int>>> tree(n);

    pq.push({0,0,-1});

    while(!pq.empty()){
        auto p = pq.top();
        pq.pop();

       int wt = p[0], node = p[1], parent = p[2];
       if(visited[node]) continue;

        if(parent != -1){
            tree[parent].push_back({node, wt});
            tree[node].push_back({parent, wt});
        }

       visited[node] = 1;

       for(auto [nei,edgeWt]: adj[node]){
        if(!visited[nei]) pq.push({edgeWt,nei,node});
       }
    }

return tree;

}

int main(){
  const vector<vector<pair<int,int>>>&adj = {{{1,2},{2,1}}, {{0,2},{2,1}}, {{0,1},{1,1},{4,2},{3,2}}, {{4,1},{2,2}}, {{2,2},{3,1}}};
   vector<vector<pair<int,int>>> tree = PrimsAlgo(adj);

   for(auto it: tree){
    for(auto [node, wt]: it){
        cout << "(" << node << "," << wt << ")" << " ";
    }
   }
   return 0;
}