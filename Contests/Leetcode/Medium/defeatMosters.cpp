#include <bits/stdc++.h>
using namespace std;
  bool isValid(long long initial, const vector<int>& monsters,
                 const vector<long long>& extra) {
        int n = monsters.size();
        for (int i = 0; i < n; ++i) {
            if (initial + extra[i] >= monsters[i]) {

                initial -= monsters[i];
                if (initial < 0)
                    initial = 0;
            } else
                return false;
        }
        return true;
    }

    long long minInitialStrength(vector<int>& monsters,
                                 vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> extra(n + 1, 0);
        for (auto& b : boosts) {

            int l = b[0];
            int r = b[1];
            int v = b[2];

            extra[l] += v;
            extra[r + 1] -= v;
        }
        long long required = monsters[0];
        for (int i = 1; i < n; i++) {
            extra[i] += extra[i - 1];
            required += monsters[i];
        }

        long long initial = 0;

        while (initial < required) {
            long long mid = initial + (required - initial) / 2;
            if (isValid(mid, monsters, extra)) {
                required = mid;
            } else {
                initial = mid + 1;
            }
        }

        return initial;
    }