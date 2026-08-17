#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;
//You are given an integer n. You need to check whether the number is a palindrome number or not. Return true if it's a palindrome number, otherwise return false.
 bool isPalindrome(int n){
    if (n == 0) return true;
    vector <int> p ={};
    while(n!=0){
        int digit = n%10;
        n=n/10;
         p.push_back(digit);
        }
     vector<int> p2(p);
     reverse(p.begin(),p.end());
     if(p==p2){
        return 1;
     }else return 0;
}
//method 2
bool m2(int x){
    if (x<0) return false;

    int num = 0,copyx =x;
    while(x!=0){
        int digit = x%10;
        x = x/10;
        if(num>INT32_MAX/10||(num==INT32_MAX/10 && digit >7)){ return false;}
        num = num*10+ digit;  
    }
  return num==copyx;
}
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    int check = m2(n);
    cout << check;
    return 0;


}
