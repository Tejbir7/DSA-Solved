#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for(int i=0; i<n; ++i){
        cin >> nums[i];;
    }

    int ans = 0;
    unordered_map <int,int> mpp;
    unordered_map<int,bool> count;

    for(int i=0; i<n; ++i){
        mpp[nums[i]]++;
    }
    for(auto &it : mpp){
        count[it.second] = true;
    }
    
    for(auto &it: mpp){
        int currCnt = it.second +1;
        if(count.find(currCnt+1) == count.end()) ++ans;
    }

    cout << ans << '\n';
    return 0;
}