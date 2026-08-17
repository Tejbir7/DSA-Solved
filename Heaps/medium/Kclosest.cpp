#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();
        if(!n) return ans;

        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;++i){
            pq.push({abs(arr[i]-x), arr[i]});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            auto it = pq.top();
            ans.push_back(it.second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
    int main(){
        vector<int> testing = {1,2,3,4,5};
        int k = 4 , x=3;
        vector<int> ans = findClosestElements(testing,4,3);
        for(int it: ans){
            cout << it << " ";
        }
        cout << endl;
        return 0;
    }
