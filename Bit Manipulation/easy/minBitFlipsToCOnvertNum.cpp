#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        for(int i=0; i<31; ++i){
            if((start & 1<<i) != (goal & 1<<i)) ++cnt;
        }
        return cnt;
    }
};

//soln 2
class Solution {
public:
    int minBitFlips(int start, int goal) {
     int num = start ^ goal;
     int cnt = 0;
     while(num != 0){
        num &= (num-1);
        ++cnt;
     }
     return cnt;
    }
};