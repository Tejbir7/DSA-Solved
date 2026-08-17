#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        int i = 0;
        while(i<n){
            if(asteroids[i]<0){
                //-ve and bigger
                while(!st.empty() && st.top() >0 && -asteroids[i]>st.top()) st.pop();

                //empty or both -ve
                if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                }
                //equal
              else if(-asteroids[i] ==st.top()){
                    st.pop();
                }
            }else{
                //+ve number
                st.push(asteroids[i]);
            }
            ++i;           
        }
        n = st.size();
       vector<int>ans(n);
       for(int i=n-1;i>=0;--i){
        ans[i] = st.top();
        st.pop();
       }
        return ans;
    }