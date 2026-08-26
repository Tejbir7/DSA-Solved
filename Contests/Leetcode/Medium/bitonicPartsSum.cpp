 #include<bits/stdc++.h>
 using namespace std;
 int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int idx =0;
       for(int i= 1; i<n-1; ++i){
           if(nums[i]>nums[i-1] && nums[i+1]<nums[i]){
               idx = i;
               break;
           }
       }
        long long inc =0, dec =0;
        for(int i =0 ;i<=idx; ++i){
            inc+= nums[i];
            
        }
        for(int i=idx; i<n; ++i){
            dec+=nums[i];
        }
      if(inc==dec) return -1;
        return(inc>dec) ? 0 :1;
    }

    //same complexity but more optimal
      int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int idx =-1;
        int low = 0, high = n-1;
 while(low<high){
            int mid = low+ (high - low) /2;
          if(nums[mid]<nums[mid+1]) low = mid+1;
          else if (nums[mid]>nums[mid+1]) high = mid;
        }
        idx = high;
       
        long long inc =0, dec =0;
       for (int i = 0; i < n; i++) {
    if (i < idx) inc += nums[i];
    else if (i > idx) dec += nums[i];
}
      if(inc==dec) return -1;
        return(inc>dec) ? 0 :1;
    }