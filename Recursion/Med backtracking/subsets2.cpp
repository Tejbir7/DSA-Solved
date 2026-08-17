#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(vector<int>&temp,vector<vector<int>>&ans,vector<int>&nums,int idx){
    ans.push_back(temp);
    for(int i = idx;i<nums.size();++i){
        if(i>idx && nums[i]==nums[i-1]) continue;
        temp.push_back(nums[i]);
        dfs(temp,ans,nums,i+1);
        temp.pop_back();
    }
}


  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> temp;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    dfs(temp,ans,nums,0);
    return ans;        
    }

    int main(){
        vector<int> testing = {1,2,2};
        vector<vector<int>> soln = subsetsWithDup(testing);
        for (const auto& subset : soln) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }

        return 0;
    }