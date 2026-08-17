#include<iostream>
#include<string>
#include<stack>
using namespace std;

int priority(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return -1;
}

string InfixToPostfix(string infix){
    stack<char> st;
    string ans;

    for(int i = 0; i < infix.size(); i++){

        char c = infix[i];

        // operand
        if(isalnum(c)){
            ans.push_back(c);
        }

        // left parenthesis
        else if(c == '('){
            st.push(c);
        }

        // right parenthesis
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                ans.push_back(st.top());
                st.pop();
            }
            if(!st.empty()) st.pop(); // remove '('
        }

        // operator
        else{
         while(!st.empty() &&
     (priority(c) < priority(st.top()) ||
     (priority(c) == priority(st.top()) && c != '^'))){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }

    // remaining operators
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main(){
    string s = "A+B*(C-D)";
    cout << InfixToPostfix(s);
}
