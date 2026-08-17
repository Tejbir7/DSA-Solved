#include<bits/stdc++.h>
using namespace std;
 int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> inc(n,1);
        vector<int>dec(n,1);

        for(int i=0; i<n; ++i){
            for(int prev = 0; prev<i; ++prev){
                if(nums[i]>nums[prev] && inc[i]< 1+inc[prev]){
                    inc[i] = 1+inc[prev];
                }
            }

            int j = n-i-1;
            for(int prev= n-1; prev>j; --prev){
                if(nums[j]>nums[prev] && dec[j]< 1+ dec[prev]){
                    dec[j] = 1+ dec[prev];
                }
            }
        }
        int maxLen = 0;
        for(int i=0; i<n; ++i){
            if (inc[i] > 1 && dec[i] > 1)
            maxLen = max(maxLen, inc[i]+dec[i]-1);
        }
        return maxLen;
    }