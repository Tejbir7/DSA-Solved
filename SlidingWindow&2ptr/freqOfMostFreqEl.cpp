  #include<bits/stdc++.h>
  using namespace std;
  
  int maxFrequency(vector<int>& nums, int k) {
           sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0, j = 0;

        using ll = long long;

        ll currSum = nums[0];
        int currFreq = 1;

        while(j<n && i<=j){
            int len = j-i+1;
            ll cost = 1LL * nums[j]* len - (currSum);

            if(cost <=k ){
                currFreq = max(currFreq, len);
                ++j;
                if(j==n) break;
                currSum += nums[j];
            }
            else {
                currSum-= nums[i];
                ++i;
            }
        }
        return currFreq;
    }