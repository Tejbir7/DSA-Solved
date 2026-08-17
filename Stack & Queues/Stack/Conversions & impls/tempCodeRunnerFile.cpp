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
void reverseAndBracket(string &s, bool bracket){
    stack<pair<char,int>>small;
    int start = 0, end = s.size()-1;
    while(start<end){
       char temp= s[start];
       s[start] = s[end];
       s[end] = temp;
       --end; ++start;
    } 
    if(bracket){
   for(char &c : s){
    if(c=='(') c = ')';
    else if(c==')') c = '(';
}
}
    return;
}
string InfixToPrefix(string infix){
        reverseAndBracket(infix,true);
        int n = infix.size();
        int i = 0;
        stack<char> st; string ans;
        while(i<n){
            //operand
           if(isalnum(infix[i])){
            ans.push_back(infix[i]);
        }
        else if(infix[i]== '(') st.push(infix[i]);
        else if(infix[i]==')'){
            while(!st.empty() && st.top()!= '('){
                ans.push_back(st.top());
                st.pop();
            }
            if(!st.empty()) st.pop();
        }
        //operator
        else{
             while(!st.empty() &&
     (priority(infix[i]) < priority(st.top()) ||
     (priority(infix[i]) == priority(st.top()) && infix[i] != '^'))){
                ans.push_back(st.top());
                st.pop();
            }
            st.push(infix[i]);
        }
       
    ++i;
    }
      while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverseAndBracket(infix,true); // to restore infix, no link with algorithm
    reverseAndBracket(ans,false);
return ans;
}
int main(){
    string s = "(A-B/C)*(A/K-L)";
    cout << InfixToPrefix(s);
    return 0;
}