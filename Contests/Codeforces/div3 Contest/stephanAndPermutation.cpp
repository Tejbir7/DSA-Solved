#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&adj, vector<int>&components, int i, int id){
    components[i] = id;
    for(auto it: adj[i] ){
       if(components[it] == -1) dfs(adj,components,it,id);
    }
    return;
}

int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n; 
        int x, y;
        cin >> x >> y;

        vector<int> nums(n,0);

        for(int i=0; i<n; ++i) cin >> nums[i];
     vector<vector<int>> adj(n);

   for (int i = 0; i < n; i++) {
    if (i + x < n) {
        adj[i].push_back(i + x);
        adj[i + x].push_back(i);
    }

    if (i + y < n) {
        adj[i].push_back(i + y);
        adj[i + y].push_back(i);
    }
}
     vector<int>components(n,-1);
     int id= 1;

     for(int i=0; i<n; ++i){
        if(components[i]==-1){
            dfs(adj,components,i,id);
            ++id;
        }
     }

     bool ok = true;
       
     for(int i=0; i<n; ++i){
        if(components[i] != components[nums[i]-1]){
            ok = false;
            break;
        }
     }
      if(ok) cout<< "YES\n";
      else cout << "NO\n";

    }
    return 0;
}