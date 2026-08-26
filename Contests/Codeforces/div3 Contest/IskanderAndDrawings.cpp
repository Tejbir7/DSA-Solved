#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n; 

        string s;
        cin >> s;

        int maxLen=0;
        for(int i=0; i<n; ++i){

            if(s[i] == '#'){

                int start = i;
                while(i<n && s[i]!='*'){
                    ++i;
                }
                int len = 0;

                len = i - start;

                maxLen = max(maxLen,len);
            }
        }

        int ceil = (maxLen + 1) / 2;
        cout << ceil << '\n';
    }
    return 0;
}