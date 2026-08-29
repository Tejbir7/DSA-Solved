#include<bits/stdc++.h>
using namespace std;

//TLE
class Solution {
    int rangeGcd(vector<int>& nums, int l, int r) {
    int g = 0;

    for (int i = l; i <= r; ++i)
        g = gcd(g, nums[i]);

    return g;
}
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();

        
        vector<int> pre(n);
        vector<int> suf(n);

         pre[0] = nums[0];
         suf[n-1] = nums[n-1];

        for(int i=1; i<n; ++i){
            int j = n-i-1;

            pre[i] = gcd(pre[i-1], nums[i]);        
            suf[j] = gcd(suf[j+1], nums[j]);
        }

        int ans = 0;
        for(int i=0; i<n-1; ++i){
            if(pre[i] == suf[i+1]) ++ans;
        }
     
        for(int ignore= 0; ignore<n; ++ignore){
            int cnt = 0;

            for(int j=0; j<n-1; ++j){
                if(j==ignore) continue;

                int left = pre[j];
                int right = suf[j+1];

                if (ignore < j) {
                    if (ignore == 0)
                        left = rangeGcd(nums, 1, j);
                    else
                        left = gcd(pre[ignore - 1],
                                   rangeGcd(nums, ignore + 1, j));
                }

                else if (ignore > j) {
                    if (ignore == n - 1)
                        right = rangeGcd(nums, j + 1, n - 2);
                    else
                        right = gcd(rangeGcd(nums, j + 1, ignore - 1),
                                    suf[ignore + 1]);
                }

                if(left==right) ++cnt;
            }
            ans = max(cnt,ans);
        }
        return ans;
    }
};

//No TLE
class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
           int n = nums.size();
        int ans = 0;

        for (int ignore = -1; ignore < n; ++ignore) {
            vector<int> arr;

            for (int i = 0; i < n; ++i) {
                if (i == ignore) continue;
                arr.push_back(nums[i]);
            }

            int m = arr.size();
            vector<int> pre(m), suf(m);

            pre[0] = arr[0];         
            suf[m - 1] = arr[m - 1];

              for (int i = 1; i < m; ++i){
                int j = m-i-1;

                pre[i] = gcd(pre[i - 1], arr[i]);
                suf[j] = gcd(suf[j + 1], arr[j]);
            }
           

            int cnt = 0;

            for (int i = 0; i < m - 1; ++i) {
                if (pre[i] == suf[i + 1])
                    ++cnt;
            }

            ans = max(ans, cnt);
        }

        return ans;
    }
};