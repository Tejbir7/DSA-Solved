#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
       queue< array<int,3>> q;
        bool visited[9][9] = {};

         int dRow[] = {1, 1, -1, -1};
         int dCol[] = {1, -1, 1, -1};

        q.push({source[0],source[1],0});
         visited[source[0]][source[1]] = true;

        while(!q.empty()){
            auto [row, col,steps] = q.front();
            q.pop();
            if(row == target[0] && col == target[1]){
                return steps;
            }
           
            for(int d =0; d<4; ++d){
                for(int k=1; k<8; ++k){
                    int nr = row + dRow[d]*k;
                    int nc = col + dCol[d]*k;

                    if(nr<1 || nc<1 || nr>8 || nc>8) break;
                      if (!visited[nr][nc]) {
                        visited[nr][nc] = true;
                        q.push({nr, nc, steps + 1});
                    }

                }
            }
        }
        return -1;
    }
};