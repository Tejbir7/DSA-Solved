#include<bits/stdc++.h>
using namespace std;

//Gives TLE
   int minimumCost(vector<int>& nums, int k) {
    int n = nums.size();

    int operations = 0;
    int t = 1;
    int fixed = k;
    const int modulo = 1e9 + 7;


    for(int i=0; i<n; ++i){
        if(k>nums[i]){
            k -= nums[i];
        }else{
            while(k<nums[i]){
                k += fixed;
                operations+= (t)%modulo;
                ++t;
            }
             k -= nums[i];
        }
    }
        return operations;
    }

    //another Maths approach
    int minimumCost(vector<int>& nums, int k) {
         int n = nums.size();

using ll = long long;

const int mod = 1e9 + 7;
    __int128 operations = 0;
    ll done = 0;
    int fixed = k;


    for(int i=0; i<n; ++i){
        if(k>= nums[i]){
            k -= nums[i];
        }else{
            int balance = nums[i] - k;

            int extraOperations = (balance+fixed-1)/fixed;
            k = extraOperations*fixed - balance;

            ll first = done+1;
            ll last = done + extraOperations;
            done = last;

            __int128 sum =  (__int128) extraOperations * (first+last) /2 ;
            operations = (operations+sum)%mod;
                             
            
        }
    }
        return (int)operations%mod;
    }

    //Really short approach:
     int minimumCost(vector<int>& nums, int k) {
     int n = nums.size();
    long long total = 0;

    const int mod = 1e9 +7;   


    for(long long num: nums){
       total = 1LL*(total+num);
    }
    long long balance = total - k;
    long long extraOps = (1LL*(balance+k-1)/k);
    

    using large = __int128;
    large apSum = (large) extraOps * (extraOps+1);
    apSum=  (apSum/2)%mod;
    return (int)apSum%mod;
    }