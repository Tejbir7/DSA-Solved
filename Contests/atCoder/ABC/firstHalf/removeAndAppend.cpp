#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, Q;
    cin >> n >> Q;
    vector<int> nums(n);
    for(int i=0; i<n; ++i) cin >> nums[i];

    vector<int> q(Q);

    for(int i= 0; i<Q; ++i ){
         cin >> q[i];
    }

    vector<int> ans(n);
    unordered_set<int> st;
    vector<int> moved;

    for(int i= Q-1; i>=0; --i){
         if(st.find(q[i]) == st.end()){
            st.insert(q[i]);
            moved.push_back(q[i]);
        }
    }

       int i=0;

    for(int j=0; j<n; ++j){
        if(st.find(nums[j]) == st.end()){
            ans[i++] = nums[j];
        }
    }

    for(int j=(int)moved.size()-1; j>=0; --j){
        ans[i++] = moved[j];
    }

    for(int j=0; j<n; ++j) cout << ans[j] << ' ';
    return 0;
}