#include<bits/stdc++.h>
using namespace std;
 long long maxSum(vector<int>& nums, int k, int mul) {
         int n = nums.size();
        sort(nums.begin(),nums.end());
        long long sum = 0;

        for(int i=n-1; i>= n-k; i--){        
            if(mul>0){
                long long j =  1LL*  nums[i]* (mul--);
                sum += j;
            }
            else{
                sum+= nums[i];
            }
        }
return sum;

        }
    