#include<bits/stdc++.h>
using namespace std;
int f(int i, int j, const string &s){

    for(int k=i; k<j; k+=2){
        int count = f(i,k-1, s) + f(k+1,j,s);
    }


}
 int countWays(const string &s) {
        // code here
        int n = s.size();
        return f(0,n-1, s);
    }