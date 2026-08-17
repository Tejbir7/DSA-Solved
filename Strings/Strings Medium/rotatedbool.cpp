#include<iostream>
#include<string>
using namespace std;
  bool rotateString(string s, string goal) {
    if(s.size()!=goal.size()) return false;
    string doubled = s+s;
     return doubled.find(goal) != string::npos;
        
    }

    int main(){
    string s = "rotation";
    string goal = "tioznrota";
    
    // Output the result
    if (rotateString(s, goal)) {
        cout << "true" << endl;  
    } else {
        cout << "false" << endl;
    }

    return 0;
    }