#include<iostream>
#include<string>
using namespace std;
 string removeOuterParentheses(string s) {
    int n = s.length();
    int level = 0;
    string ans;
    for(char ch:s){
        if(ch=='('){
            if(level>0){
                ans+=ch;
            }
            ++level;
        }
       else if(ch==')'){
            --level;
            if(level>0){
                ans+=ch;
            }            
        }
    }
    return ans;        
    }

    int main() {
    string s = "(()())(())";           

    // Get result
    string ans = removeOuterParentheses(s);

    // Print result
    cout << "The result is: " << ans << endl;

    return 0;
}