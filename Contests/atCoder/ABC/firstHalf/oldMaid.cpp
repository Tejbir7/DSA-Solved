#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; ++i){
        cin >> nums[i];;
    }

    int sum = 0;
    unordered_map<int,int> mpp;

    for(int i=0; i<n; ++i){
        mpp[nums[i]]++; 
    }
    for(auto it: mpp){
        if(it.second % 2 == 0) continue;
        else{
            sum+= it.first;
        }
    }
    cout << sum << '\n';
    return 0;
}