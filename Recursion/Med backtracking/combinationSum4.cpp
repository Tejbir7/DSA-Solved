#include<iostream>
#include<vector>
using namespace std;
int count(vector<int>& nums, int &target, int idx, int &temp){
    if(idx = nums.size()){
        if(temp==target) return 1;
        else return 0;
    }
    temp+= nums[idx];

    int l = count(nums, target,idx+1,temp);
    temp -= nums[idx];

    int r= count(nums, target,idx+1,temp);
    
    return l+r;
}

int combinationSum4(vector<int>& nums, int target) {
    int temp;
    int required = count(nums,target,0,temp);
    return required;
}

int main(){
    vector <int> nums = {1,2,3};
    int target = 4;
    int noOfcombinations = combinationSum4(nums, target);
    cout << noOfcombinations << endl;
    return 0;

}
//incomplete.....................
// wrong ans.........
//would be done by Dp..