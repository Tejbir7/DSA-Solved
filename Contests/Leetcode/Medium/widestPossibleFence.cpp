   #include<bits/stdc++.h>
   using namespace std;

   
   int maximumWidth(vector<int>& planks) {

        int n = planks.size();
        using ll = long long;
        unordered_map<ll, int> freq, possibleFreq;
        for (int i = 0; i < n; ++i) {
            freq[planks[i]]++;
            possibleFreq[planks[i]]++;
        }

        for (auto const& i : freq) {
            for (auto const& j : freq) {

                ll a = i.first, b = j.first;

                if (a < b) {  //avoids duplicate count 
                    possibleFreq[a + b] += min(i.second, j.second);
                } else if (a == b) {
                    possibleFreq[a + b] += i.second / 2;
                }
            }
        }

        int ans = 0;
        for (auto const& a : possibleFreq) {
            ans = max(ans, a.second);
        }

        return ans;
    }