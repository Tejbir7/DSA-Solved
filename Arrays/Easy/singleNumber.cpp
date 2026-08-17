#include<iostream>
#include<climits>
#include<vector>
using namespace std;
    int singleNumber(vector<int>& nums) {
        int ans =0;
        for(int x: nums){
            ans = ans ^ x;
        }
        return ans;
       
    }
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter values: ";
    for(int x=0;x<n;x++){
        cin >> nums[x];
    }
    int ans1 = singleNumber(nums);

    cout << "The missing num is: " << ans1 << endl;

   
    return 0;
}
