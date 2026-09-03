#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int odd = 0, even = 0;
        int miniOdd = INT_MAX, miniEven = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 0) {
                ++even;
                miniEven = min(miniEven, nums[i]);
            } else {
                ++odd;
                miniOdd = min(miniOdd, nums[i]);
            }
        }

        if (even == n || odd == n)
            return true;

        return miniOdd < miniEven;
    }
};