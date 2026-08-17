#include<iostream>
#include<vector>
using namespace std;

void helperDfs(int idx, vector<int>&nums , vector<int> &temp, vector<vector<int>>&ans){
 
    if(idx== nums.size()){
        ans.push_back(temp);
        return;
    }
 
    //pick
    temp.push_back(nums[idx]);
    helperDfs(idx+1,nums,temp,ans);
    temp.pop_back();
 
    //dont pick
    helperDfs(idx+1,nums,temp,ans);    
}

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    helperDfs(0,nums,temp,ans);
    return ans;   
        
    }

    int main(){
        vector<int> testing = {3,1,2};
        vector<vector<int>> soln = subsets(testing);
        for (const auto& subset : soln) {
        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "}" << endl;
    }

        return 0;
    }