#include<bits/stdc++.h>
using namespace std;
 int minLights(vector<int>& lights) {
    int n = lights.size();
  
    vector<int> visited(n,0);
    for(int i=0; i<n; ++i){
        int v = lights[i];
        if(v>0){
            int start = max(0, i - v);
            int end = min(n - 1, i + v);
            for(int j= start; j<=end; ++j){
                visited[j] = 1;
            }            
        }
    }
    int count =0;

    for(int j=0; j<n; ++j){
        if(!visited[j]){
            int toPlace = j+1;
            int start = max(0, toPlace - 1);
            int end = min(n - 1, toPlace + 1);
            for(int i= start; i<=end; ++i){
                visited[i] = 1;
            }
            ++count;
        }
    }
   
    return count;        
    }

    //optimal: Prefix Sum
    int minLights(vector<int>& lights) {
    int n = lights.size();
  
    vector<int> difference(n+1,0);
    for(int i=0; i<n; ++i){
        int v = lights[i];
        if(v>0){
            int start = max(0, i - v);
            int end = min(n - 1, i + v);
           difference[start]++;
          if(end+1 <n) difference[end+1]--;         
        }
    }
    for(int i=1; i<n; ++i){
        difference[i] += difference[i-1];
    }
    int count =0;

    for (int i = 0; i < n; ) {
    if (difference[i]) { 
        i++; 
        continue; 
    }
    count++;   // place a bulb covering i, i+1, i+2
    i += 3;
}
    return count;        
    }