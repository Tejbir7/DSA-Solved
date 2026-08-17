#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cout << "Enter your age: ";
    cin >> a;
    if(a >= 18){
        cout << "You are eligible to vote" << endl;

    } else{
        cout << "Sorry! you are ineligbile to vote" << endl;
    }

    return 0;
}