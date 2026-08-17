#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
  int minimumCost(vector<int>& nums) {
        int sum = nums[0];
        sort(nums.begin()+1, nums.end());
        sum+= nums[1]+nums[2];
        return sum;
    }
        int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int S = INT_MAX;
        int secondS = INT_MAX;
        for(int i = 1; i<n;++i){
            if(nums[i]<S){
                secondS = S;
                S = nums[i];
                
            }
            else if(nums[i]<secondS  ){
                secondS = nums[i];
            }
        }
        sum+=S + secondS;
        return sum;
    }