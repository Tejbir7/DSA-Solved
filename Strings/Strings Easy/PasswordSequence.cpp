#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool passCheck(string p){
    int n = p.size();
    if(n!=7) return false;
    int left = 0, right = n-1;
    while(left<right){
        if(p[left]!=p[right]) return false;
        --right,++left;
    }
    int count =0;
    string special = "!#$%&'()*+,-./:;<=>?@[]^_`{|}~";
    for(char ch:special){
       if(p[3]==ch){
        ++count;
       }
    }
    if(count!=1) return false;
    return true;
}
int main(){
string pass;
cout << "You need a password!" << endl ;
cout << "Condition: Should be 7 characters with pallindromic sequence and the middle character a special character" << endl;
cout << "Please Enter: ";


getline(cin,pass);
bool t = passCheck(pass);
if(t==false) {cout << "Invalid Password!";}
else cout << "Valid Password.";
return 0;
}