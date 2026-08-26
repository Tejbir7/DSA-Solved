#include<bits/stdc++.h>
using namespace std;

// N^2, would give tle 
class Solution {
    private:
    struct job{
        int id;
        int deadline;
        int profit;
    };

   static bool comp(const job &a, const job&b){
        return a.profit > b.profit;
    }

  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();
        vector<job> jobs;
        for(int i=0; i<n; ++i){
          jobs.push_back({i,deadline[i], profit[i]});
        }
        
        sort(jobs.begin(), jobs.end(), comp);
        vector<int> vis(n+1,-1);

        int cnt = 0;
        int ans = 0;

        for(int i=0; i<n; ++i){
          int d = jobs[i].deadline;
          while(d>=1 && vis[d] != -1){
            --d;
          }
          if(d==0) continue;

          vis[d] = 1;
          ans += jobs[i].profit;
          ++cnt;
        }
        return {cnt,ans};
    }
};

//optimal: dsu
class DisjointSet{
    private:
    vector<int> parent;

    public:
    DisjointSet(int n){
        parent.resize(n+1);
        for(int i=0; i<=n; ++i){
            parent[i] = i;
        }
    }

    //Path compression 
    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void occupy(int slot){
        parent[slot] = findUPar(slot-1);
    }
//Either use rank for all operations or size for all operations, but dont use both

};
class Solution {
    private:
    struct job{
        int id;
        int deadline;
        int profit;
    };

   static bool comp(const job &a, const job&b){
        return a.profit > b.profit;
    }

  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();
        vector<job> jobs;
        for(int i=0; i<n; ++i){
          jobs.push_back({i,deadline[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end(), comp);

        DisjointSet ds(n);


        int cnt = 0;
        int ans = 0;

        for(int i=0; i<n; ++i){
          int d = ds.findUPar(jobs[i].deadline);
          if(d==0) continue;

          ans += jobs[i].profit;
          ++cnt;
          ds.occupy(d);
        }
        return {cnt,ans};
    }
};
