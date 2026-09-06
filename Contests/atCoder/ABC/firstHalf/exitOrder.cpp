#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n ; ++i) cin >> nums[i];

    int limit = 10;
    int i=0;
    while(i< n){
        if(nums[i] > limit){
              cout << "No" << '\n';
            return 0;
        } 
        ++i;
        if(i%10 == 0) limit += 10;        
    }
    cout << "Yes" << '\n';
    return 0;
}