#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--){
	    int n; cin >> n;
        string s; cin >> s;

        for(int i=0; i<n; ++i){
            if(s[i]=='z'){
                while(s[i]!='z'){
                    s[i] = 'a';
                }
                break;
            }
        }
	    
        cout << s << '\n';
	}
    return 0;
}
