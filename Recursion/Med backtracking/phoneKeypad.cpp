#include<iostream>
#include<string>
#include<vector>
using namespace std;
void dfs(string &temp,vector<string> &ans, string &digits,string combos[], int idx){
    if(idx==digits.size()){
        ans.push_back(temp);
        return;
    }
    int digit = digits[idx]-'0';
    for(int i = 0;i<combos[digit].size();++i){
       temp.push_back(combos[digit][i]);
        dfs(temp,ans,digits,combos,idx+1);
        temp.pop_back();           
    }
}
 vector<string> letterCombinations(string digits) {
    if(digits.empty()) return {};
    string temp = "";
    vector<string> ans;
    string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    dfs(temp,ans,digits,combos,0);
    return ans;
}