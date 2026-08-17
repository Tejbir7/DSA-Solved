#include<iostream>
using namespace std;
 int GCD(int n1,int n2){
    int num =0,condtn;
    if(n1>n2){
        condtn = n2;
    }else condtn = n1;
    for(int i=condtn;i>0;i--){
            if(n1%i==0 && n2%i==0){
                return i;            
        }
    }
    return 1;
    }

    int main(){
        int n1, n2;
        cout << "Enter n1 and n2: ";
        cin >> n1>> n2;
        int cgcd = GCD(n1,n2);
        cout << cgcd;
        return 0;
    }
 