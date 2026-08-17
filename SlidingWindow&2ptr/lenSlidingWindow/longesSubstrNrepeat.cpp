#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
  int lengthOfLongestSubstring(string s) {
        if(!s.size()) return 0;
         int maxlen =0;
    for(int i=0;i<s.size();++i){
        unordered_map<char, int> mpp;
        int len = 0;
        for(int j=i;j<s.size();++j){
            ++mpp[s[j]];
            if(mpp[s[j]]>1){
                break;
            }
            ++len;
        }
        maxlen = max(maxlen,len);
    }
    return maxlen;
    }
    int optimal(string s){
        int n= s.size();
        if(!n) return 0;
        int hash[256];
        for(int i=0;i<256;++i) hash[i] = -1;
        int l=0, r=0, maxlen = 0, len =0;
        while(r<n){
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){
                l = hash[s[r]]+1;
            }           
            len = r-l+1;
            maxlen = max(maxlen,len);
            hash[s[r]]=r;
            ++r;
              
        }
        return maxlen;
    }
    int main(){
        string s = "abcabcbb";
        int maxxi = optimal(s);
        cout << maxxi;
        return 0;
    }