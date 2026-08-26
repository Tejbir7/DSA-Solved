#include<bits/stdc++.h>
using namespace std; 
    bool canMakeSubsequence(string s, string t) {
        int i=0, j=0;
        int n = s.size();
        bool consumed = false;

        while(j<n){
            if(s[i]==t[j]) i++;
           else{
            int last = j;
            while(s[i]!=s[j]){
                ++j;
            }
            if(s[i]==s[j]){
                i++;
                continue;
            }
            if(j==n-1 && s[i]!=s[j] && !consumed) {
              consumed = true;
              j = last+1;
              ++i; continue;
            }else return false;
           }
        }
        return true;
    }