#include<iostream>
using namespace std;
bool isPrime(int n, int i=2){
    if(n<=1) return false;
    if (i * i > n) return true;
    if(n%i==0) return false;
    return isPrime(n,i+1);
   
}

int main(){
int n;
cout <<"Enter number: ";
cin >> n;
int result = isPrime(n);
cout << (result?"Prime":"Not Prime");
return 0;
}
