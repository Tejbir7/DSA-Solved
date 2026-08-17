#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

/**vector<int> myrec(vector<int>&nums,int target,int check1=0){
    int n = nums.size();
    if (check1 >= n) return {};
    for(int check2=check1+1;check2<n;++check2){
        if(nums[check1]+nums[check2]==target){
            return{check1,check2};
        }else{
            myrec(nums,target,check1+1);
        }      
        }
}
 vector<int> twoSum(vector<int>& nums, int target) {
       return myrec(nums,target);
    }**/
//ANOTHER APPROACH [2PTR OPTIMISED]
//FIRST SORT THE ARRAY
/*vector <int> betterapproach(vector<int>&nums, int target ){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    int left =0, right = n-1;
    while(left<right){
       int sum = nums[left]+nums[right];
        if( sum ==target){
            return {left,right};
        }
        else if(sum<target){
            ++left;
        }
        else{--right;}
    }
    return {};
}*/
//FAILS AS ORIGINAL INDICES ARE LOST
//BEST BEST APPROACH
vector <int>twosummap(vector<int>&nums,int target){
    int n = nums.size();
    unordered_map <int,int> uttar;
    for(int i=0;i<n;++i){
        int num = nums[i];
        int complement = target -num;
        if (uttar.find(complement) != uttar.end()){
            return {uttar[complement],i};
        }
        uttar[nums[i]]=i;
        }
        return {};


}

int main(){
    int n,target;
    cout << "Enter n: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter values: ";
    for(int x=0;x<n;x++){
        cin >> nums[x];
    }
     cout << "Enter target: ";
     cin >> target;
     vector<int>ans=twosummap(nums,target);
     int n2= ans.size();
     if(n2==0){
        cout << "No Indices found" << endl;
     }else{
 for(int x=0;x<n2;x++){
        cout << ans[x] << " ";
    }
}
    return 0;

}
