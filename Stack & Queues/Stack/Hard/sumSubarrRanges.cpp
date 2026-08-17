#include<iostream>
#include<vector>
#include<utility>
#include<stack>
#include<algorithm>
using namespace std;
//Brute Force
 long long subArrayRangesBrute(vector<int>& nums) {
      int n = nums.size();
    if(n==1) return 0;
    long long ans=0;
    for(int i=0;i<n; ++i){
        int mini = nums[i] , maxi = nums[i];
        for(int j = i+1; j<n; ++j){
            mini = min(mini, nums[j]);
            maxi = max(maxi, nums[j]);
            ans += maxi- mini;            
        }
    }
        return ans;
    }

// Approach 2: Finding Sum of sub Arr max - Sum of Sub arr Min
//Pse Nse Pge nge 
  long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return 0;
    stack<int> pse, nse , pge , nge;
    vector<pair<int, int>> smaller(n), greater(n);
    //smaller({pse,nse}) and greater({pge,nge})
    for(int i=0; i<n; ++i){
        int j = n-i-1;
        //pse
        while(!pse.empty() && nums[pse.top()] > nums[i]) pse.pop();
        //pge
        while(!pge.empty() && nums[pge.top()]< nums[i]) pge.pop();
        //nse
        while(!nse.empty() && nums[nse.top()]>= nums[j]) nse.pop();
        //nge
        while(!nge.empty() && nums[nge.top()]<= nums[j]) nge.pop();
        smaller[i].first = pse.empty() ? -1 : pse.top();
        greater[i].first = pge.empty() ? -1 : pge.top();

        smaller[j].second = nse.empty() ? n : nse.top();
        greater[j].second = nge.empty() ? n : nge.top();
        
        pse.push(i); pge.push(i); nse.push(j); nge.push(j);
    }
    long long minSum = 0; long long maxSum = 0;
    for(int i=0; i<n; ++i){
        //Building Smaller
        int leftS = i - smaller[i].first;
        int rightS = smaller[i].second - i;
        long long contributionS = 1LL * leftS * rightS * nums[i];        
        minSum += contributionS;

        //Building Greater
        int leftG = i - greater[i].first;
        int rightG = greater[i].second - i;
        long long contributionG = 1LL * leftG * rightG * nums[i];
        maxSum += contributionG;
    }

    return maxSum - minSum;
        
    }