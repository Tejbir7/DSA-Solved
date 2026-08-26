#include<bits/stdc++.h>
using namespace std;
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = lights.size();
        int maxLight = INT_MIN;
        for(int i=0; i<n; ++i) maxLight = max(maxLight, lights[i]);

        int ans = 0;
        
        int m = arrivalTime.size();
        for(int i=0; i<m; ++i){
            int r = arrivalTime[i] % period;
            if(r >= maxLight){
                ans = max(ans, period - r);
            }
        }
        return ans;
    }