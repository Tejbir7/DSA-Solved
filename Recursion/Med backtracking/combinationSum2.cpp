#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void dfs(vector<int>&temp,vector<vector<int>> &ans,vector<int>& candidates, int target, int idx){

    if (target == 0) {
        ans.push_back(temp);
        return;
    }
    

   // iterate choices starting from idx
    for (int i = idx; i < candidates.size(); i++) {

        //skip duplicates at the SAME recursion level
        if (i > idx && candidates[i] == candidates[i - 1])
            continue;

        if (candidates[i] > target)
            break;

        // choose current element (used ONCE)
        temp.push_back(candidates[i]);

        // move to next index (i + 1 → single use)
        dfs(temp, ans, candidates,target - candidates[i],i+1 );

        // backtrack
        temp.pop_back();
    }

}

 vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int>temp;
    vector<vector<int>> ans;
    sort(candidates.begin(),candidates.end());
    dfs(temp,ans,candidates,target,0);
    return ans;        
    }

     int main(){
        vector<int> testing = {3,1,2};
        vector<vector<int>> soln = combinationSum2(testing,5);
        for (const auto& subset : soln) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }

        return 0;
    }