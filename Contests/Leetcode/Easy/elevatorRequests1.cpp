  #include<bits/stdc++.h>
  using namespace std;
  
  int elevatorRequests(int n, vector<int>& requests) {
      int t = requests.size();
        int prev = 0, cnt = 0;
        
        for(int i=0; i<t; ++i){
            cnt += abs(requests[i] - prev);
            prev = requests[i];
        }
        return cnt;
    }