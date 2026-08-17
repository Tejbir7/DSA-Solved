#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>&adj, vector<int> &visited,int node, stack<int> &st ){
    visited[node] = 1;
    for(int i: adj[node]){
        if(!visited[i]) dfs(adj,visited,i,st);
    }
    st.push(node);
}

// toposort 
//Graph assumed its DAG

vector<int> topoSortDAG(vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> visited(n,0);
    stack<int> st;

    for(int start =0; start <n; ++start){
        if(!visited[start]){
            dfs(adj,visited, start,st);
        }
    }
     vector<int> result;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        result.push_back(node);
     }
     return result;
}

//topo sort if its not guaranteed to be acyclic but on directed:
bool dfsCycleTopo(int node, vector<vector<int>>& adj, vector<int>& state, stack<int>& st) {
    state[node] = 1; // visiting

    for(int i : adj[node]) {
        if(state[i] == 0) {
            if(dfsCycleTopo(i, adj, state, st)) return true;
        }
        else if(state[i] == 1) {
            return true; // cycle
        }
    }

    state[node] = 2; // done
    st.push(node);
    return false;
}

vector<int> topoSortWithCycleCheck(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> state(n, 0);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        if(state[i] == 0) {
            if(dfsCycleTopo(i, adj, state, st)) {
                return {}; // cycle exists
            }
        }
    }

    vector<int> result;
    while(!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}