#include<bits/stdc++.h>
using namespace std;

int countValidPrefixes(string s) {
      int n = s.size();
        int zero = 0, one = 0, count = 0;
        for(int i=0; i<n; ++i){
            if(s[i]=='0') ++zero;
            else ++one;

            if(abs(zero-one) <= 1) ++count;
        }


        return count;
    }