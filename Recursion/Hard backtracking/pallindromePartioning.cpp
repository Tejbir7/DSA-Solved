#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isPallindrome(int idx, int end, const string &s){
    int left = idx; int right = end;
    while(left<right){
    if(s[left]!=s[right]){
        return false;
    }else{ ++left; --right;}

}
    return true;
}
void dfs(vector<string> &temp,vector<vector<string>> &ans, const string &s, int idx){
    if(idx==s.size()){
        ans.push_back(temp);
        return;
    }
    for(int end =idx;end<s.size();++end){
        if(isPallindrome(idx,end,s)){
            temp.push_back(s.substr(idx,end-idx+1));
            dfs(temp,ans,s,end+1);
            temp.pop_back();
        }

    }

}
  vector<vector<string>> partition(string s) {
    vector<string> temp;
    vector<vector<string>> ans;
    dfs(temp,ans,s,0);
    return ans;        
    }