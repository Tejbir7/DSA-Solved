 #include<iostream>
 #include<vector>
 #include<algorithm>
 #include<unordered_map>
 #include<queue>
 using namespace std;
 vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mpp;
        for(int i=0;i<n;++i){
            ++mpp[nums[i]];
        }
        priority_queue<
        pair<int,int>, 
        vector<pair<int,int>>, 
        greater<pair<int,int>>> pq;
        for(auto &it: mpp){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
     int main(){
        vector<int> testing = {1,1,1,2,2,3};
        int k = 2;
        vector<int> ans = topKFrequent(testing,k);
        for(int it: ans){
            cout << it << " ";
        }
        cout << endl;
        return 0;
    }
