#include<iostream>
#include<string>
#include <cctype>
using namespace std;
 bool isPalindrome(string s){
    int left = 0;
    int right = s.size() -1;
     while(left<right){
        while(left<right && !isalnum  (static_cast<unsigned char>(s[left])))
        ++left;
     while (left < right && !isalnum(static_cast<unsigned char>(s[right])))
            --right;
     if (tolower(static_cast<unsigned char>(s[left])) 
            != tolower(static_cast<unsigned char>(s[right])))
        {
            return false;
        }
        ++left;
        --right;
     }
     return true;
    }
  
 
int main() {
    string line;
    cout << "Enter String: ";
    getline(cin, line);
    cout << (isPalindrome(line) ? "true" : "false") << "\n";
    return 0;
}