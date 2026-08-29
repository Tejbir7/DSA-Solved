#include<bits/stdc++.h>
using namespace std;

class Solution {
    void f(int num,  vector<string> &ans){
        int n = log2(num);
        string temp;
        for(int i=0; i<=25; ++i){
            if(num >> i & 1){
                temp.push_back('a' + i);
            }
        }
        int rem = n-25;
        if(rem>0){
            rem = pow(2,rem);
            temp.append(rem , 'z');
        }

        reverse(temp.begin(), temp.end());
        ans.push_back(temp);
    }

public:
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        
        for(int i=0; i<n ; ++i){
            f(nums[i], ans);
        }
        return ans;
    }
};