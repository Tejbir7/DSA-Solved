#include<iostream>
#include<vector>
using namespace std;
void generateC(vector<int>&temp, vector<vector<int>> &ans,int n, int k,int start){
    
    if(temp.size()==k){
        ans.push_back(temp);
        return;
    }
    for(int i = start;i<=n;++i){
        temp.push_back(i);
        generateC(temp,ans,n,k,i+1);
        temp.pop_back();
    }
}

 vector<vector<int>> combine(int n, int k) {
    vector<int>temp;
    vector<vector<int>> ans;
    generateC(temp,ans,n,k,1);
    return ans;   
        
    }

 main(){
    int n=4, k =2;
    vector<vector<int>> soln = combine(n,k);
    for (const auto& subset : soln) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }

 }