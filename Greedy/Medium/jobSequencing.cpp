#include<bits/stdc++.h>
using namespace std;

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
   sort(ans.begin(), ans.end());

        return ans;
    }