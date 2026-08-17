#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<int>&temp,vector<vector<int>>&ans, int n, int k, int start, int sum){
    if(sum>n) return;

    if(temp.size()==k){
        if(sum==n) ans.push_back(temp);
        return;
    }

    for(int i = start; i<=9; ++i ){
        if(sum+i>n) break;
            temp.push_back(i);
            dfs(temp,ans,n,k,i+1,sum+i);
            temp.pop_back();                  
}
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>target;
    vector<vector<int>> ans;
    dfs(target,ans,n,k,1,0);        
    return ans;
    }

main(){
    int n=9, k =3;
    vector<vector<int>> soln = combinationSum3(k,n);
    for (const auto& subset : soln) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }

 }
