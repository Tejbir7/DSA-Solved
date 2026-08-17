#include<iostream>
#include<string>
#include<vector>
using namespace std;
void dfs( string &temp, vector<string>& ans, int n, int open, int close){
    if(temp.size()==2*n) {
        ans.push_back(temp);
        return;
    }
    if(open<n){
        temp.push_back('(');
        dfs(temp,ans,n,open+1,close);
        temp.pop_back();
    }
    if(close<open){
        temp.push_back(')');
        dfs(temp,ans,n,open,close+1);
        temp.pop_back();
    }

}


vector<string> generateParenthesis(int n) {
    string temp;
    vector<string> ans;
    dfs(temp,ans,n,0,0);
    return ans;        
    }

   int main(){
        int n = 3;
        vector<string> recAns = generateParenthesis(n);
        for(auto it: recAns){
            cout << it << " " ;

        }
        return 0;
    }