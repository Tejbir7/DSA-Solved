#include<bits/stdc++.h>
using namespace std;
class Solution {
    using ll = long long;
    const int MOD = 1e9 + 7;
    
    ll modPow(ll x, ll y) {
        ll ans = 1;

        while (y > 0) {
            if (y & 1)
                ans = ans * x % MOD;

            x = x * x % MOD;
            y >>= 1;
        }

        return ans;
    }
public:
    int sumDecoded(vector<long long>& nums) {
         int n = nums.size();
        int sum = 0;
        
      

        for(int i=0; i<n; ++i){
            ll width = nums[i] % 10;
            ll d = nums[i] / 10;

            string s = to_string(d);
            string x = s.substr(0, width);
            string y = s.substr(width);

            ll decoded = (ll) modPow(stoll(x), stoll(y));

            sum = ( 1LL * (sum + decoded) ) % MOD;
            
        }
        return sum;
    }
};