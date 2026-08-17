#include<bits/stdc++.h>
using namespace std;
void dfs(int n, int k, vector<string>& ans, string s, int cost){

    if(s.size()==n  && cost<=k){
     ans.push_back(s);
     return;
}

   int pos = s.size();
   dfs(n,k,ans,s+'0', cost);
   
   if(s[pos-1]!='1' && cost+pos<=k){
    dfs(n,k,ans,s+'1', cost+pos);
   }
    
}

 vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        dfs(n,k,ans, "", 0);
        return ans;

        
    }