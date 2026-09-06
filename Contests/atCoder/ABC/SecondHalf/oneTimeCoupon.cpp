#include<bits/stdc++.h>
using namespace std;

//Wrong ans, need to work again 
int n;
using ll = long long;

ll f(int i, int coupons,const vector<int>& a,const vector<int>& b, vector<vector<ll>> &dp){
    if(i > n-1){
        return 0;
    }  

    if(dp[i][coupons] != -1) return dp[i][coupons];

    ll dontUseMove = a[i] + f(i+1, min(n,coupons+1), a, b, dp);
    ll dontUseStay = 1e18;
    if(coupons < n){
        dontUseStay = a[i] + f(i, coupons+1, a, b, dp);
    }

    ll dontUse = min(dontUseMove, dontUseStay);

    ll use = 1e18;
    if(coupons != 0){
        use = b[i] + f(i+1, coupons-1, a, b, dp);
    }

    return dp[i][coupons] = min(use,dontUse);
}
int main(){
    int k;
    cin >> k;
    while(k--){
        cin >> n;
        vector<int> a(n), b(n);
        for(int i=0; i<n; ++i){
            cin >> a[i] >> b[i];
        }

        vector<vector<ll>> dp(n, vector<ll>(n+1, -1));
        cout << f(0,0, a, b, dp) << '\n';
    }
    return 0;
}