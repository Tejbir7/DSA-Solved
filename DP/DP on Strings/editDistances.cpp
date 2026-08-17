#include<bits/stdc++.h>
using namespace std;

  int dfs(int i, int j, const string& s, const string& t,
            vector<vector<int>>& dp) {
        //if (j == 0 && i==0) return 0; Just improves readability
        if (i == 0) return j;
        if(j==0 ) return i;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == t[j - 1])
            return dp[i][j] = dfs(i - 1, j - 1, s, t, dp);
        return dp[i][j] = 1 + min({dfs(i - 1, j, s, t, dp),  // deleted
                               dfs(i - 1, j - 1, s, t, dp), // replaced
                               dfs(i, j - 1, s, t, dp)});  // inserted
    }

    int minDistance(string& s, string& t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return dfs(m, n, s, t, dp);
    }
    //tabulation

    int minDistance(string& s, string& t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for(int j=0; j<=n; ++j) dp[0][j] = j;
        for(int i=0; i<=m; ++i) dp[i][0] = i;

        for(int i=1; i<=m; ++i){
            for(int j=1; j<=n ; ++j){
                  if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1];

               else dp[i][j] = 1 + min({dp[i-1][j],  // deleted
                              dp[i-1][j-1], // replaced
                              dp[i][ j- 1]});  // inserted

            }
        }
        return dp[m][n];
    }

    //space optimised
     int minDistance(string& s, string& t) {
        int m = s.size(), n = t.size();
        vector<int> prev(n+1, 0);

        for(int j=1; j<=n; ++j)  prev[j] = j;

        for(int i=1; i<=m; ++i){
            vector<int> curr(n+1);
            curr[0] = i;
            for(int j=1; j<=n ; ++j){
                  if (s[i - 1] == t[j - 1]) curr[j] = prev[j - 1];

               else curr[j] = 1 + min({prev[j],  // deleted
                              prev[j-1], // replaced
                              curr[ j- 1]});  // inserted

            }
            prev = curr;
        }
        return prev[n];
    }

    //New habit
       int minDistance(string& s, string& t) {
        int m = s.size(), n = t.size();
        vector<int> prev(n + 1), curr(n + 1);

        for (int j = 1; j <= n; j++)
            prev[j] = j;

        curr[0] = 0;

        for (int i = 1; i <= m; ++i) {
            curr[0] = i;
            for (int j = 1; j <= n; ++j) {
                if (s[i - 1] == t[j - 1])
                    curr[j] = prev[j - 1];

                else
                    curr[j] = 1 + min({prev[j],       // deleted
                                       prev[j - 1],   // replaced
                                       curr[j - 1]}); // inserted
            }
            swap(prev, curr);
        }
        return prev[n];
    }


