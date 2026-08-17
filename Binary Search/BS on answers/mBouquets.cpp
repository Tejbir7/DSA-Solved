#include<iostream>
#include<climits>
#include<vector>
using namespace std;
 int minDays(vector<int>& bloomDay, int m, int k) {
    long long n = bloomDay.size();
    if(n< 1LL*m*k) return -1;
    int high = 0,low = INT_MAX;
    for(int i:bloomDay){
        if(i>high) high = i;
        if(i<low)  low = i;  
    }
    int ans = -1;
    while(low<=high){
        int mid = low + ((high-low)/2);
        int bouquets = 0,consecutive = 0;
        for(int d : bloomDay){
            if(d<=mid){
                ++consecutive;
                if(consecutive==k){ 
                ++bouquets;
                if(bouquets>=m) break;
                consecutive =0;
            }
            }else{
                consecutive = 0;
            }
        }
        if(bouquets >=m){
            ans = mid;
            high = mid -1;
        }else{
            low = mid+1;
        }
    }
    return ans;        
    }
//alternative approach
int approach2(vector<int>& bloomDay, int m, int k){
    long long n = bloomDay.size();
    if(n< 1LL*m*k) return -1;
    int high = 0,low = INT_MAX;
    for(int i:bloomDay){
        if(i>high) high = i;
        if(i<low)  low = i;  
    }
    while(low<=high){
    int mid = low + ((high-low)/2);
    int count = 0;
    long long noOfB = 0;
    for(int f:bloomDay){
        if(f<=mid){
            ++count;
        }else{
            noOfB += count / k;
            if(noOfB>=m) break;
            count = 0;
        }
    }
    noOfB += count/k;
    if(noOfB>=m) high = mid-1;
    else low = mid+1;
    }
    return low;
}

    int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = approach2(arr, m,k);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}