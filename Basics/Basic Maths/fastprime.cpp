#include<iostream>
using namespace std;

 bool isPrime(int n) {
    if (n <= 1) return false;
  int count=0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0){
            count++;
            if(i!=n/i){
                count++;
            }
        }   
    }
     if(count>0) {return false;
     }else return true;
}


int main(){
    int t;
    cout << "Enter num: ";
    cin >> t;
    bool result = isPrime(t);
    cout << (result ? "Prime" : "Not Prime") << endl;
    return 0;
}

