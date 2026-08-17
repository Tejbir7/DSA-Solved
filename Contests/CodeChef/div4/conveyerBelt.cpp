#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n; cin >> n;
	    int currPos ; cin >> currPos;
	    string s; cin >> s;

        //go Right
        int right = 0;
        for(int i=currPos-1; i<n; ++i){
            if(s[i]== 'R') continue;
            else ++right;
        }

        int left = 0;
        for(int i=currPos-1; i>=0; --i){
            if(s[i]== 'L') continue;
            else ++left;
        }
	    
        cout << min(left, right) << '\n';
	}
	return 0;
}
