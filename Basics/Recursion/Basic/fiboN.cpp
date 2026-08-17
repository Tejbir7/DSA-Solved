#include<iostream>
using namespace std;
//F(0) = 0, F(1) = 1
//F(n) = F(n - 1) + F(n - 2), for n > 1.
 int fibbo(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int ans = fibbo(n-1)+fibbo(n-2);
    return ans;
 }
 // alternative itterative approach, much faster!
 int fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int a=0,b=1,ans;
    for(int i=2;i<=n;i++){
        ans = a+b;
        a=b;
        b=ans;
    }
    return ans;
 }
 int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    int recAns = fib(n);
    cout << recAns;
    return 0;
 }