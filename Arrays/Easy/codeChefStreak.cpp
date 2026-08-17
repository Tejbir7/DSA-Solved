#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

//TLE
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        vector < int > pref(n);

        pref[0] = s[0] - '0';

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + (s[i] - '0');
        }
        
        int totalSum = m*pref[n-1];
        int prevSum = 0, count = 0;

        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                if(j==m-1 && i==n-1 && totalSum==0){
                    ++count;
                    break;
                }
                if (prevSum + pref[i] == totalSum - (pref[i ] + prevSum)) ++count;
            }
            prevSum += pref[n - 1];
        }
        cout << count << '\n';

    }
    return 0;
}

//Clean but same complexity
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int totalSum = 0;

      
            for (auto i: s) {
                if (i == '1') ++totalSum;
            }
            totalSum *= m;
            if (totalSum % 2 != 0) {
                cout << 0 << '\n';
                continue;
            }

            int curr = 0, count = 0;
              for (int i = 0; i < m; ++i) {
            for (auto it: s) {
                if (it == '1') curr += 1;
                if (curr == totalSum - curr) ++count;
            }
              }

        
        cout << count << '\n';
    }
    return 0;
}

//Maths approach: Optimised
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;

        int totalSum = 0;
         string index;

            for (auto i: s) {
                if (i == '1') {
                    ++totalSum;
                    index.push_back(i+1);
                }
            }
            
            //Case 1
            if (totalSum == 0) {
            cout << n * m << '\n';
            continue;
        }

            totalSum *= m;
            //Case 2
            if (totalSum % 2 != 0) {
                cout << 0 << '\n';
                continue;
            }

           
            int target = totalSum/2;
            int ans = index[target+1] - index[target];
            cout << ans <<'\n';
          
    }
    return 0;
}

