#include<iostream>
#include<vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int>& nums) {
    int n = nums.size();
       int ans = 0, window = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                ++window;
            }
            else{
                    window =0;
                }
             ans = max(ans,window);
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
        int ans = findMaxConsecutiveOnes(nums); 
        cout << ans << endl; 
          return 0;
         }
