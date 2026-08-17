#include<bits/stdc++.h>
using namespace std; 
bool f(int first, int second, int k){
     if( abs(second - first) > k) return false;
     return true;
}
bool check(long long num, int k){
    vector<int> temp;
    while(num != 0){
       int last = num % 10;
         temp.push_back(last);
           num /= 10;
    }
    int n = temp.size();
    for(int i=1; i<n; ++i){
        if(!f(temp[i], temp[i-1],k)) return false;
    }
    return true;        
}

 long long goodIntegers(long long l, long long r, int k) {
        long long count = 0;
      while(l<r){
    if(check(l,k)) ++count;
    ++l;
   }
   return count;  
    }