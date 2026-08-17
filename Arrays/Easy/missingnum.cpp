#include<iostream>
#include<vector>
using namespace std;
int missingNumber(vector<int>& nums) {
        int n= nums.size();
        int truesum = (n*(n+1))/2;
        int sum =0;
        for(int i=0;i<n;i++){
            sum+= nums[i];
        }
        return truesum - sum;
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
    int ans1 = missingNumber(nums);

    cout << "The missing num is: " << ans1 << endl;

   
    return 0;

}
