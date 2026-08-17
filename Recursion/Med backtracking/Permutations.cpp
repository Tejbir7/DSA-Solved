#include<iostream>
#include<vector>
using namespace std;

void dfs( vector<int>&temp, vector<vector<int>> &ans,vector<int>& nums, vector<bool> &used){
    if(temp.size()==nums.size()){
        ans.push_back(temp);
        return;
    }
    for(int i=0;i<nums.size();++i){
        if(used[i]) continue;
        
        used[i] = true;
        temp.push_back(nums[i]);
  
        //explore
        dfs(temp,ans,nums,used);

        //backtrack
        temp.pop_back();
        used[i]= false;
    }
}

 vector<vector<int>> permute(vector<int>& nums) {
    vector<int> temp;
    vector<vector<int>> ans;
    vector<bool> used(nums.size(),false);
    dfs(temp,ans,nums,used);
    return ans;
        
    }

     int main(){
        vector<int> testing = {2,7,91,8};
        vector<vector<int>> soln = permute(testing);
        for (const auto& subset : soln) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }

        return 0;
    }