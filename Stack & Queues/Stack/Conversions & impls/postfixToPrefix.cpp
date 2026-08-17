#include<iostream>
#include<string>
#include<stack>
using namespace std;
string postfixToPrefix(string postfix){
    int n = postfix.size();
    int i =0;
    stack<string> st;
    while(i<n){
        if(isalnum(postfix[i])){
            st.push(string(1,postfix[i]));
        }else{
           if(st.size()<2) return "Invalid!";
           string op2 = st.top(); st.pop();
           string op1= st.top(); st.pop();
           st.push(string(1,postfix[i])+op1+op2);
        }
        ++i;
    }
    if(st.size()!=1) return "Invalid!";
    return st.top();
}