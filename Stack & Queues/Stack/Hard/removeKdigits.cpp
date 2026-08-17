#include<iostream>
#include<string>
#include<stack>
using namespace std;
  string removeKdigitsStack(string num, int k) {
    int n = num.size();
    if(k==n) return "0";
    stack<char> st;
    for(int i=0; i<n; ++i){
        while(!st.empty() && k>0 && st.top()> num[i]) 
        {st.pop();
            --k;
        }
        st.push(num[i]);
    }
    while(k-- && !st.empty()){
        st.pop();
    }
    string ans;
    n = st.size();
    ans.resize(n);
   for(int i= n-1; i>=0; --i){
    ans[i] = st.top();
    st.pop();
   }
    int del = 0;
     for(int i =0; i<n; ++i){
        if(ans[i]!= '0') break;
        ++del;
    }
    ans = ans.substr(del);
    return ans.empty() ? "0" : ans;
    }

    //best version
    string removeKdigits(string num, int k) {
    int n = num.size();
    if(k==n) return "0";
    string st;
    for(int i=0; i<n; ++i){
        while(!st.empty() && k>0 && st.back()> num[i]) 
        {st.pop_back();
            --k;
        }
        st.push_back(num[i]);
    }
    while(k-- && !st.empty()){
        st.pop_back();
    }
   int i = 0;
    while(i < st.size() && st[i] == '0') i++;
     if(i == st.size()) return "0";
    st.erase(0, i);
    return st;
    }
