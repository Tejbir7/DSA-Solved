#include<iostream>
#include<climits>
#include<vector>
using namespace std;
 int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    if(!n) return 0;
    int left = 0, right =0, mini =INT_MAX;
    long long sum=0;
    while(right<n){
      sum+=nums[right];
    while (sum >= target) {
            mini = min(mini, right - left + 1);
            sum -= nums[left];
            ++left;
        }
        ++right;
    }
     return mini == INT_MAX ? 0 : mini;
    }

    int main(){
        vector<int>testing = {2,3,1,2,4,3};
        int target = 7;
        int ans = minSubArrayLen(target,testing);
        cout << ans << endl;
        return 0;
    }
