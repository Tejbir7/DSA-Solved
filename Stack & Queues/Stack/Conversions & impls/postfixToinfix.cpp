#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

string postfixToInfix(string postfix){
    int n = postfix.size();
    stack<string>st;
    string ans;
int i = 0;
    while(i<n){
        if(isalnum(postfix[i])) st.push(string(1,postfix[i]));
        else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push(("("+t2+postfix[i]+t1+")"));
        }
        ++i;
    }
return st.top();
}