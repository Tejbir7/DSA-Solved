#include <bits/stdc++.h>
using namespace std;

    vector<bool> transformStr(string s, vector<string>& strs) {
        vector<bool> ans;
        unordered_map<char, int> mpp;
        for (auto it : s) {
            mpp[it]++;
        }
        for (auto it : strs) {
            unordered_map<char, int> mp;
            for (auto i : it) {
                if (i == '?')
                    continue;
                mp[i]++;
            }
            if ((mp.find('0')!= mp.end() && mpp.find('0')!= mp.end() &&  mp['0'] > mpp['0']) || (mp.find('0')!= mp.end() && mpp.find('0')!= mp.end() &&   mp['1'] > mpp['1']) )
                ans.push_back(false);
            else
                ans.push_back(true);
        }
        return ans;
    }