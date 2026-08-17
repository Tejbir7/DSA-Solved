#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
 int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int presum =0, cnt =0;
    unordered_map <int,int> mp;
    mp[0]=1;
    for(int i=0;i<n;i++){
        presum += nums[i];

        int remove = presum -k;
        cnt += mp[remove];
        mp[presum]++;
    }
    return cnt;        
    }

    int main(){
    vector <int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = subarraySum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
}