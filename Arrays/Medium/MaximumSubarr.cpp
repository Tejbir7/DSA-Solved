#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

 /* int maxSubArray(vector<int>& nums) {
    int n= nums.size();
        int sum1=0,sum2=0;
        for(int i=0;i<=n/2;i++){
           
            if(nums[i]>0){
                sum1+=nums[i];
            }
            else if(nums[i]<0 && (abs(nums[i])<sum1)){
                sum1+=nums[i];
            }
            else{
                sum1 =0;
            }
        }
        for(int i=n-1;i>n/2;i--){
           
            if(nums[i]>0){
                sum2+=nums[i];
            }
            else if(nums[i]<0 && (abs(nums[i])<sum2))
            {
                sum2+=nums[i];
            }
            else{
                sum2 =0;
            }
        }
        int megasum = sum1+sum2;
        return megasum;
    } */

    // BEST APPROACH KADANE ALGORITHM
    int kadaneAlgo(vector<int>&nums){
        int n =nums.size();
        int  maxendinghere = nums[0], maxsofar = nums[0];
        for(int i=1;i<n;++i){
            maxendinghere = max(nums[i],maxendinghere+nums[i]);
            maxsofar = max(maxsofar,maxendinghere);

        }
return maxsofar;
        
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
   int ans =kadaneAlgo(nums);
 cout << "The sum is: " << ans << endl;

    return 0;

}