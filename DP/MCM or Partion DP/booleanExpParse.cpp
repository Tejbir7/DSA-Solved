#include<bits/stdc++.h>
using namespace std;

    bool parseOr(const string &s){
        int n = s.size();
        for(int i=0; i<n; ++i){
            if(s[i] == 't') return true;
        }
        return false;
    }
    
    bool parseAnd(const string &s){
        int n = s.size();
        for(int i=0; i<n; ++i ){
            if(s[i] == 'f') return false;
        }
        return true;
    }

    bool parseBoolExpr(const string & s) {
        int n = s.size();

        stack<char> st;
        for(int i=0; i<n; ++i){
            if(s[i] == ',') ++i;

            else if(s[i] == ')'){
                string t;
                while(!st.empty() && st.top() != '('){
                    t.push_back(st.top());
                    st.pop();
                }
                st.pop();

                char op = st.top(); 
                st.pop();

                if(op == '&'){
                    if(parseAnd(t)) st.push('t');
                    else st.push('f');
                }
                else if(op == '|'){
                    if(parseOr(t)) st.push('t');

                }
                else if(op == '!'){
                    if(t == "f") st.push('f');
                    else st.push('t');
                }
            }
            else{
                st.push(s[i]);
            }
        }
        char final = st.top();
        st.pop();

        if(final == 'f') return false;
        return true;
    }