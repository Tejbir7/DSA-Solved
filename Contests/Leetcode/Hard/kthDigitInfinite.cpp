#include<bits/stdc++.h>
using namespace std;
 int kthDigit(long long k) {
    if(k<10) return k;
    if(k%2 == 0){
        int ans = ((k-9)/20 )+1;
        return ans;
    }
    if(k%2 != 0){
         int ans = ((k-9)/20 );
        if(ans %2 != 0){
            int rem = (k-9)%20;
            if(rem == 0) return 0;
            else return (rem -2) / 2;
        }else{
            int rem = (k-9)%20;
            if(rem == 0) return 9;
            else return 10-(rem/2) ;
        }
    }
    
    return 0;
        
    }