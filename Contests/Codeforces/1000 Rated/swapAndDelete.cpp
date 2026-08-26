#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        int n = s.size();

        unordered_map<char, int> mpp;

        for(int i=0; i<n; ++i){
            mpp[s[i]]++ ;
        }
        if(mpp.size()==1) {
            cout << n << "\n";
            continue;
        }
        if(mpp['0']==mpp['1']){
            cout << 0 << "\n";
            continue;
        }

        int cnt =n;
        for(int i=0; i<n; ++i){
            if(s[i]=='1'){
                 if (mpp['0'] == 0) break;
                 mpp['0']--;
                 --cnt;
            }else{
                if (mpp['1'] == 0) break;
                mpp['1']--;
                --cnt;
            }
        }
       cout << cnt << "\n";
    }
    return 0;
}