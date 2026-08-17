#include<iostream>
#include<vector>
using namespace std;
 int smallestDivisor(vector<int>& nums, int threshold) {
    int n = nums.size();
    long long sum=0;
    int high = 0;
    for(int i: nums){
        if(i>high) high = i;
        sum += i;
    }
    if(threshold==n) return high;
    int low = (int)max(1LL,(sum+threshold-1)/threshold);
    while(low<=high){
        int sum = 0;
        int mid = low + ((high-low)/2);
        for(int p:nums){
            sum += (p+mid-1)/mid;
            if(sum>threshold) break;
        }
        if(sum<=threshold) high = mid-1;
        else low = mid+1;
    }
    return low;        
    }

    int main()
{
    vector<int> arr = {1,2,5,9};
    int limit = 6;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}