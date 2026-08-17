#include<bits/stdc++.h>
using namespace std;
  bool lemonadeChange(vector<int>& bills) {
        vector<int> change(2,0);
        int n = bills.size();
        for(int i=0; i<n; ++i){
            if(bills[i]==5) change[0]++;
           else if(bills[i]=10){
            if(!change[0]) return false;
            change[1]++;
            change[0]--;
           }
           else if(bills[i]==20){
            if(!bills[1] || !bills[0]) return false;
             change[1]--;
           }
        }
        return true;
    }