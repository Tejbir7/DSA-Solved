#include<iostream>
#include<string>
#include<stack>
using namespace std;
  bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        int i = 0;
        while(i<n){
            if(s[i]=='(' || s[i]=='[' || s[i] == '{'){
                st.push(s[i]);
            }
           else{
            if(st.empty()) return false;
            if(s[i] == ')' && st.top() != '(') return false;
            else if(s[i] == ']' && st.top() != '[') return false;
            else if(s[i] == '}' && st.top() != '{') return false;
            st.pop();
        }
         ++i;
      }
return st.empty();
}