#include<bits/stdc++.h>
using namespace std;

//priority_queue<T, container, comparator> 
// T = data type stored 
// container = underlying storage 
// comparator decides priority ordering

//S: source and V: No of vertices
//Imp: wts are non negative
vector<int> minPath(const vector<vector<pair<int,int>>>&adj, int S){
    int V= adj.size();
    vector<int> minList(V,INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

    pq.push({0,S});
    minList[S] = 0;

    while(!pq.empty()){
        auto [dist,node] = pq.top();
        pq.pop();

        if(dist> minList[node]) continue;

        for(auto [nei,wt]: adj[node]){
            int newDist = dist+wt;
            if(minList[nei]>newDist){
                minList[nei] = newDist;
                pq.push({newDist,nei});
            }
            
        }
        
    }
    return minList;
}

//Another version with Set data structure
vector<int> minPath(const vector<vector<pair<int,int>>>&adj, int S){
    int V= adj.size();
    vector<int> minList(V,INT_MAX);
    set<pair<int,int>> st;

    st.insert({0,S});
    minList[S] = 0;

    while(!st.empty()){
        auto it = *st.begin();
        auto [dist,node] = it;
        st.erase(it);
        

        for(auto [nei,wt]: adj[node]){
            int newDist = dist+wt;
            if(minList[nei]>newDist){
                if(minList[nei]!=INT_MAX){
                    st.erase({minList[nei],nei});
                }
                minList[nei] = newDist;
                st.insert({newDist,nei});
            }
            
        }
        
    }
    return minList;
}

//Set internally use Red Black Trees
//Used in 
// set
// map
// multiset
// multimap