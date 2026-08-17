#include<iostream>
#include<vector>
using namespace std;
   //OPTIMAL APPROACH:
 vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positives,negatives;
        for(int i=0;i<n;++i){
            if(nums[i]>0){
                positives.push_back(nums[i]);
            }else negatives.push_back(nums[i]);
        }
        for(int i=0;i<n/2;++i){
            nums[2*i] = positives[i];
            nums[2*i+1]= negatives[i];
        }
        return nums;
    }

  /* vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(),posIDX=0,negIDX=1;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                ans[posIDX]=nums[i];
                posIDX+=2;
            }
            if(nums[i]<0){
                ans[negIDX]=nums[i];
                negIDX+=2;
            }
        }
        return ans;

    }*/
     int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter values: ";
    for(int x=0;x<n;x++){
        cin >> nums[x];
    }
   vector <int> yay =rearrangeArray(nums);
 for(int x=0;x<n;x++){
        cout<< yay[x] << " ";
    }

    return 0;

}
