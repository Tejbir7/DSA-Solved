#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        int n = nums.size();
        if(n == 1) return 1;
        for(int i=0; i<n; ++i){
            mpp[nums[i]].push_back(i);
        }
        int cnt = 0;
        for(auto [val, pos]: mpp){
            int sz = pos.size();
            bool isValid = true;
            for(int i=1; i<sz; ++i){
                if(pos[i] != pos[i-1] + 1){
                    isValid = false;
                     break;
                }
            }
            if(isValid) ++cnt;
        }
        return cnt;
        
    }
};