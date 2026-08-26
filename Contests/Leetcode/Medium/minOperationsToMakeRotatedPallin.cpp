#include<bits/stdc++.h>
using namespace std;
int operations(char &a, char &b){
    int c1 = abs(a-b);
    int c2 = 26 - c1;
    return min(c1,c2);
}

 int minOperations(string s) {
        int n = s.size();
        int ans = INT_MAX;

        for(int k=0; k<n; ++k){
           int cost = k;

            for(int i = 0; i<n/2; ++i){

                int l = (k+i)%n;
                int r= (n-i-1+k)%n;
                if(s[l] != s[r]){
                    cost += operations(s[l], s[r]);
                }
            }
            ans = min(ans,cost);
        }
        return ans;
    }