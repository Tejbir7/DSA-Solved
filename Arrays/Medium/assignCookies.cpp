#include<bits/stdc++.h>
using namespace std;
  int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n1 = g.size();
        int n2 = s.size();
        if (n2 == 0)
            return 0;

        int count = 0, i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (s[j] >= g[i]) {
                count++;
                i++;
                j++;
            } else
                ++j;
        }
        return count;
    }

    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n1 = g.size();
        int n2 = s.size();
        if (n2 == 0) return 0;

                int i = 0, j = 0;

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++;
            }
            j++;
        }

        return i;

    }