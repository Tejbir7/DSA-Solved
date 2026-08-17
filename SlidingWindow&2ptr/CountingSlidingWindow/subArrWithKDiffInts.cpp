#include<bits/stdc++.h>
using namespace std;

// N long N variant
int atMost(vector<int>& nums, int k){
    if(k==0) return 0;
    int n = nums.size();

    int l=0, r=0, count = 0;

    unordered_map<int,int> mpp;
    using state = pair<int,int>;
    priority_queue<state, vector<state>, greater<state>> pq;

    while(r<n){

        mpp[nums[r]] = r;     //{val,idx}

        pq.push({r,nums[r]});  //{idx,val}

        while(mpp.size()>k){
            auto [idx,val] = pq.top(); pq.pop();
            if(mpp[val]==idx){
                while(l<=idx) ++l;
                mpp.erase(val);
            }
        }
        
        count += (r-l+1);
        ++r;
    }
    return count;
}
 int subarraysWithKDistinct(vector<int>& nums, int k) {
    int exact = atMost(nums,k) - atMost(nums,k-1);
    return exact;        
    }

    //optimised: O(N)
  int atMost(vector<int>& nums, int k){
    if(k==0) return 0;
    int n = nums.size();

    int l=0, r=0, count = 0;

    unordered_map<int,int> mpp;
   

    while(r<n){
        mpp[nums[r]]++;     //{val,freq}

        while(mpp.size()>k){
           mpp[nums[l]]--;
            if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
           ++l;
        }
        
        count += (r-l+1);
        ++r;
    }
    return count;
}

    int subarraysWithKDistinct(vector<int>& nums, int k) {
          int exact = atMost(nums,k) - atMost(nums,k-1);
    return exact;     
    }