#include<bits/stdc++.h>
using namespace std;

//Tell if -ve cycle exists, if not then give min dist of nodes from source

//{u,v,weight}
vector<int> minD(int V, vector<vector<int>>& edges, int src){

    vector<int> dist(V,INT_MAX);
    dist[src] =0;

    for(int i=0; i<V-1; i++){
        
        bool updated = false;

        for(auto &p : edges){

            int u = p[0], v= p[1], wt = p[2];
            //Relaxation:
            if( dist[u] != INT_MAX && dist[u]+ wt < dist[v]) {
            dist[v] = dist[u] + wt;  
            updated = true;         
            }
        }
        if(!updated) break;
    }

    //-ve cycle detection:
     for(auto &p : edges){

            int u = p[0], v= p[1], wt = p[2];
           
            if( dist[u] != INT_MAX && dist[u]+ wt < dist[v]){
                cout << "Negative cycle is there!" << endl;
                return {};
            }         

        }

    return dist;
}
