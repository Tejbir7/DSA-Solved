#include<iostream>
using namespace std;
//You are given an integer n. You need to return the number of digits in the number.
//Constraints:
//0 <= n <= 5000
//no will contain no leading zeroes except when it is 0 itself.
int countDigits(int n){
    int count =0;
    while(n>0){
        n=n/10;
        count++;
    }
    return count;
}

int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    int Digits = countDigits(n);
    cout << Digits;
    return 0;
}
