#include<iostream>
#include<vector>
using namespace std;
  int majorityElement(vector<int>& nums) {
        int n= nums.size();
        int cnt =0,el = 0;
        for(int i=0;i<n;i++){
            if(cnt ==0){
                cnt=1;
                el =nums[i];
            }
            else if (nums[i]==el){
                ++cnt;
            }
            else --cnt;
        }
        int cnt2=0;

        for(int i=0;i<n;i++){
            if(nums[i]==el){
                ++cnt2;
            }

        }
        if(cnt2>=n/2){
            return el;
        }
        return -1;
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
   int ans = majorityElement(nums);
cout << "The majority el is: " << ans << endl;

    return 0;

}