#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll bigi =  (ll) 1e18;

int main(){
    int n;
     cin >> n;
     vector<ll> a(n), b(n);
     for(int i=0; i<n; ++i) cin >> a[i];
     for(int i=0; i<n; ++i) cin >> b[i];

     vector<long long> ans;
     __int128 sumA = 0 , sumB = 0;

     for(int i=0; i<n; ++i){
        if(a[i] <= b[i]){
            ans.push_back(1);
            sumA += a[i];
            sumB += b[i];
           
        }else{
            ans.push_back(bigi);
            sumA += (__int128)a[i] * bigi;
            sumB += (__int128)b[i] * bigi;
        }
     }
     if(sumA <= sumB){
        cout << "No" << '\n';
        return 0;
     }
     cout << "Yes" << '\n';
     for(int i=0; i<n; ++i){
        cout << ans[i] << ' ';
     }
     return 0;
}