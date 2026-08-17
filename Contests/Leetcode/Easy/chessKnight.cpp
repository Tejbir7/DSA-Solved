#include <bits/stdc++.h>
using namespace std;
   bool canReach(vector<int>& start, vector<int>& target) {
       vector<vector<int>> dist(8, vector<int>(8, -1));

        int dRow[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dCol[] = {-1, 1, -2, 2, -2, 2, -1, 1};

        queue<pair<int,int>> q;
        q.push({start[0], start[1]});
        dist[start[0]][start[1]] = 0;

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if(r == target[0] && c == target[1])
                return dist[r][c] % 2 == 0;

            for(int k = 0; k < 8; k++) {
                int nr = r + dRow[k];
                int nc = c + dCol[k];

                if(nr >= 0 && nr < 8 && nc >= 0 && nc < 8 &&
                   dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }