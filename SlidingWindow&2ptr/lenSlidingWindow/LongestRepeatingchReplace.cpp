#include<iostream>
#include<vector>
#include<string>
using namespace std;
 int characterReplacement(string s, int k) {
    int n = s.size();
    if(!n) return 0;
        int l=0, r=0, maxlen =0, maxfreq=0;
        int hash[26] = {0};
        while(r<n){
           ++ hash[s[r]-'A'];
           maxfreq = max(maxfreq,hash[s[r]-'A']);
           if((r-l+1)-maxfreq>k){
            --hash[s[l]-'A'];
            ++l;
           }
           if((r-l+1)-maxfreq <=k){
            maxlen = max(maxlen,r-l+1);
            ++r;
           }   

        }
     return maxlen;
    }

    int main(){
      string s = "AABABBA";
      int k = 1;
      int ans = characterReplacement(s,k);
      cout << ans;
      return 0;
    }