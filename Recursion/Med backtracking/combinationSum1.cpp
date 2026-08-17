#include<iostream>
#include<vector> 
using namespace std;
void dfs(vector<int>&temp,vector<vector<int>>& ans,vector<int>&candidates, int target,int idx){
    if(target==0){
        ans.push_back(temp);
        return;
    }

     if(target < 0 || idx == candidates.size()){
        return;
    }

    //pick curr el(unlimited times)
    if(candidates[idx]<=target){
        temp.push_back(candidates[idx]);
       dfs(temp,ans,candidates,target-candidates[idx],idx);
       temp.pop_back();
    }

    //skip curr
    dfs(temp,ans,candidates,target,idx+1);

}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int>temp;
    vector<vector<int>> ans;
    dfs(temp,ans,candidates,target,0);
    return ans;       
    }

        int main(){
        vector<int> testing = {3,1,2};
        vector<vector<int>> soln = combinationSum(testing,5);
        for (const auto& subset : soln) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }

        return 0;
    }