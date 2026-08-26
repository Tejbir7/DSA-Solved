#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n; 

        vector<long long> nums(n,0);

        for(int i=0; i<n; ++i) cin >> nums[i];

        bool flag = false;
        for(int i=0; i<n-1; ++i){

            if(nums[i]< i+1){
                flag = true; 
                break;
            }
            nums[i+1] += nums[i] - (i+1);
          
        }
     if (!flag && nums[n - 1] >= n) cout << "YES\n";
else
    cout << "NO\n";
    }
    return 0;
}