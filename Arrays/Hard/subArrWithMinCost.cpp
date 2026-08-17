#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
  long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        long long sum = nums[0];
        int i = 1;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<int>> pq;
        while(i++ <n-1){
            pq.push({nums[i],i});
        }
        int last = nums[n-1];
        while(k-1 >0){
           auto it = pq.top();
           int num = it.first;
           int idx = it.second;
            if(num<last){
                sum+= num;
                k--;
            }



        }



        
    }
