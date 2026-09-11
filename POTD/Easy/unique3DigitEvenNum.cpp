#include<bits/stdc++.h>
using namespace std;
class Solution {      
    
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_set<int> st;
        int cnt = 0;

        for(int k=0; k<n; ++k){
            if( digits[k]==0) continue;
            int num = digits[k];
           

            for(int i=0; i<n; ++i){

                if(i==k) continue;
                num = num*10 + digits[i];

                for(int j=0; j<n; ++j){
                    if(j==i || j==k) continue;
                    num = num*10 + digits[j];

                    if( (num&1 )==0 && st.find(num) == st.end()){
                        ++cnt;
                        st.insert(num);
                    }

                    num /= 10;
                }
                 num/= 10;
            }

           
        }

return cnt;
    }
};

//slight better
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> st;
        int n = digits.size();

        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;

            for (int j = 0; j < n; j++) {
                if (j == i) continue;

                for (int k = 0; k < n; k++) {
                    if (k == i || k == j || (digits[k]&1) == 1) continue;

                 

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    st.insert(num);
                }
            }
        }

        return st.size();
    }
};

//No set usage
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        bool vis[1000] = {};
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;

            for (int j = 0; j < n; j++) {
                if (j == i) continue;

                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue;

                    if (digits[k] % 2 != 0) continue;

                    int num = digits[i] * 100
                            + digits[j] * 10
                            + digits[k];

                    if (!vis[num]) {
                        vis[num] = true;
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};