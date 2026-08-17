#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 int shipWithinDays(vector<int>& weights, int days) {
    long long maxCap=0;
    long long minCap = 0;
    for(int i: weights){
        maxCap +=  i; 
        minCap = max(minCap,(long long)i);       
    }
    minCap = max(minCap,(maxCap+days-1)/days);
    while(minCap<=maxCap){
        int mid = minCap + ((maxCap-minCap)/2);
        int windowsum=0,count =1;
        for(int i: weights){
            if(windowsum+i>mid){
                ++count;
                windowsum=0;
                if(count>days) break;            
            }
            windowsum+=i;           
        }
        if(count>days){
            minCap=mid+1;
        }else{
            maxCap=mid-1;
        }
    }
    return (int)minCap;
 }

 int main()
{
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
    int d = 5;
    int ans = shipWithinDays(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}

