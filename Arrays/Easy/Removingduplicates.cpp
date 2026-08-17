#include<iostream> 
#include<vector> 
using namespace std; 
int removeDuplicates(vector <int>&nums){ 
    int n= nums.size(); 
    if(n==0) return 0;
    int k=0;
    for(int j=1;j<n;++j){
        if(nums[j]!=nums[k]){
            ++k;
            nums[k]=nums[j];
        }
        
    }
  return k+1;   
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
        int ans = removeDuplicates(nums); 
        cout << ans << endl; 
        for(int x=0;x<n;x++){ 
            cout << nums[x] << " ";
         }
          return 0;
         }