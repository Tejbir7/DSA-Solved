#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    private:
    vector<int> rank, parent;

    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; ++i){
            parent[i] = i;
        }
    }

    //Path compression 
    int finduPar(int node){
        if(parent[node]==node) return node;
        return parent[node] = finduPar(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int uPu = finduPar(u);
        int uPv = finduPar(v);
        if(uPu==uPv) return;
        if(rank[uPu]<rank[uPv]) parent[uPu] = uPv;
       else if(rank[uPu]>rank[uPv]) parent[uPv] = uPu;
       else{
        parent[uPv] = uPu;
        rank[uPu]++;
       }

    }

};
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    vector<vector<string>> ans;
    unordered_map<string, vector<int>> group;

    int n = accounts.size();

    //O(N)
    for(int i= 0; i<n; ++i){
        string name = accounts[i][0];
        group[name].push_back(i);
     
    }

    
    DisjointSet ds(n);
   // O(X+Y) X: No of nodes sharing same name and Y: summation of all nodes in them
        for(auto &p : group){
            unordered_map<string, int> mp;
               if(p.second.size() ==1) continue;
            for(int idx: p.second){                       
                for(int j=1; j<accounts[idx].size(); ++j){
                    string email = accounts[idx][j];
                    if(mp.find(email) == mp.end()){
                        mp[email] = idx;
                    }else{
                        //mp[email] = old idx
                        ds.unionByRank(idx,mp[email]);
                    }    
                }
            }
        }

      
        unordered_map<int, set<string>> mpp;
        //M*4alpha+log(M)
       for(int i=0;i<n;i++){
            int parent = ds.finduPar(i);

        for(int j=1;j<accounts[i].size();j++){
        mpp[parent].insert(accounts[i][j]);
    }
}
//O(N+M )
        for(auto &p: mpp){
            int idx = p.first;

            string name = accounts[idx][0];
           vector<string> temp;
           temp.push_back(name);

           for(auto &email : p.second){
            temp.push_back(email);
           }
           ans.push_back(temp);
            
    
    }
     return ans;
}


//O(M log M) or ie (O(N+M)) 
  // for(int i=0; i<n; ++i){
        //     if(ds.finduPar(i)!=i){
        //         int parent = ds.finduPar(i);
        //          set<string> st;
        //          st.insert(accounts[parent][0]);

        //         for(int j=1; j<accounts[parent].size(); ++j){
        //             st.insert(accounts[parent][j]);
        //         }                                           
        //         for(int x=1; x<accounts[i].size(); ++x){
        //             st.insert(accounts[i][x]);
        //         }                  
        //         accounts[parent].clear();
        //        for(auto &s : st){
        //            accounts[parent].push_back(s);
        //          }
        //          accounts[i].clear();
        //     }
        // }