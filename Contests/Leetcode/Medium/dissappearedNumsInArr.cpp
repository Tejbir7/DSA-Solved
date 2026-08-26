#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;

        int i = lower;
        int j = 0;
        while (j < n && nums[j] < lower)
            ++j;

        while (i <= upper) {
            if (j >= n || nums[j] > upper) {
                ans.push_back({i, upper});
                break;
            }

            if (j < n && nums[j] == i) {
                ++i;
                ++j;
            } else if (nums[j] < i) {
                ++j; // duplicate
            } else {
                ans.push_back({i, nums[j] - 1});
                i = nums[j];
            }
        }

        return ans;
    }
};