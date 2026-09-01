#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& nums, int energy) {
        int n = nums.size();
        int m = 0;

        for (int i = 0; i < n; ++i)  m = max(m, (int)nums[i].size());

        int cnt = 0; // litterCount
        vector<vector<int>> id(n, vector<int>(m, -1));
        int sr, sc;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                if (nums[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (nums[i][j] == 'L')
                    id[i][j] = cnt++;
            }
        }

        if (cnt == 0) return 0;

        // vis[row][col][mask] = maximum energy left
        vector<vector<vector<int>>> vis( n, vector<vector<int>>(m, vector<int>(1 << cnt, -1)));
        int fullMask = (1 << cnt) - 1;

        int dRow[] = {1, -1, 0, 0};
        int dCol[] = {0, 0, 1, -1};

        // row, col, energy left, mask
        using state = array<int, 4>;
        queue<state> q;

        q.push({sr, sc, energy, 0});
        vis[sr][sc][0] = energy;

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {

                auto [row, col, energyLeft, mask] = q.front();
                q.pop();

                if (mask == fullMask) return steps;
                if (nums[row][col] == 'R')  energyLeft = energy;
                if (energyLeft == 0)  continue;

                for (int k = 0; k < 4; ++k) {
                    int nr = row + dRow[k];
                    int nc = col + dCol[k];

                  if (nr < 0 || nr >= n || nc < 0 || nc >= nums[nr].size() || nums[nr][nc] == 'X') continue;
                   
                    int newMask = mask;

                    if (nums[nr][nc] == 'L') newMask = newMask | (1 << id[nr][nc]);
                    

                    if (vis[nr][nc][newMask] < energyLeft - 1) {
                        vis[nr][nc][newMask] = energyLeft - 1;
                        q.push({nr, nc, energyLeft - 1, newMask});
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};