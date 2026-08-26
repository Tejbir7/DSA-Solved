#include<bits/stdc++.h>
using namespace std;

//My approach of using ordered map
   vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        int n = s.size();

        map<int, vector<pair<int, int>>> mpp;

        for (int i = 0; i < n; ++i) {
            mpp[f[i]].push_back({s[i], i + 1});
        }

        vector<int> ans;
        int lastEnd = -1;

        for (auto &[endTime, meetings] : mpp) {
            for (auto &[startTime, idx] : meetings) {
                if (startTime > lastEnd) {
                    ans.push_back(idx);
                    lastEnd = endTime;
                    break;
                }
            }
        }
        //answer will be sorted is not guaranteed
        sort(ans.begin(), ans.end());
        return ans;
    }

    //Strivers approach
    class Solution {
        struct meeting{
            int start, end, idx;
        };

        static bool comp(const meeting &a, const meeting &b){
            return a.end<b.end;
        }

  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        int n = s.size();
        vector<meeting> meetings;
        for(int i=0; i<n; ++i){
            meetings.push_back({s[i],f[i], i+1});
        }

        sort(meetings.begin(), meetings.end(), comp);
        vector<int>ans;
        int lastEnd = -1;

        for(int i=0; i<n; ++i){
            if(lastEnd < meetings[i].start){
                ans.push_back(meetings[i].idx);
                lastEnd = meetings[i].end;
            }
        }

        return ans;
    }
};