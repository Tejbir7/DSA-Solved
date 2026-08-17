#include<bits/stdc++.h>
using namespace std;
  string sortVowels(string s) {
        int n = s.size();
        unordered_map<char,int>mpp;
        for(int i=0 ; i<n; ++i){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                if(mpp.find(s[i])!=mpp.end()) mpp[s[i]]++;
                else{
                    mpp.insert({s[i],1});
                }
            }
        }
        string ans;
        vector<pair<int,char>> vowels;
      for(auto it = mpp.begin(); it != mpp.end(); ){
        vowels.push_back({it->second,it->first});
        mpp.erase(it);
}
       

        for(int i=0; i<n; ++i){
             if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u'){
                ans+=s[i];
             }else{

             }

        }
    }