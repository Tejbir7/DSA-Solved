#include<bits/stdc++.h>
using namespace std;
 int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size();
        int idx = -1;
        int ans = INT_MAX;
        
        for(int i=0; i<n; ++i){
            int temp = (abs(drones[i][0]-target[0]) + abs(drones[i][1]-target[1]));
            if( temp <= drones[i][2]){
                if(temp < ans){
                ans = temp;
                idx = i;
                }
            }
        }
        return idx;
    }