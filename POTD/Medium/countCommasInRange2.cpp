#include<bits/stdc++.h>
using namespace std;
class Solution {
    using ll = long long;
    using bigi = __int128;

public:
    long long countCommas(long long n) {
        
        ll ans = 0;
        int commas = 1;
        bigi start = 1000, end = 999999;

        while(start <=n){
            bigi actEnd = min( (bigi)n, end);

            ans += (actEnd - start +1 ) * commas;

            start*= 1000;
            end = end * 1000 + 999;
            ++commas;
        }
        return ans;

    }
};