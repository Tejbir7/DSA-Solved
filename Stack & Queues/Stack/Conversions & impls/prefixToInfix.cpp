#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

string prefixToInfix(string prefix){
    int n = prefix.size();
    int i = n-1;
    stack<string>st;
    while(i>=0){
        if(isalnum(prefix[i])){
            st.push(string(1,prefix[i]));
        }else{
            if(st.size()<2) return "Invalid Input!";
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            st.push("("+top1+prefix[i]+top2+")");
        
    }
        --i;
    }
    if(st.size() != 1) return "Invalid Input!";
    return st.top();
}