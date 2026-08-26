#include<bits/stdc++.h>
using namespace std;
int bnr2Decimal(int num){
    int ans = 0;
    int i=0;

    while(num!= 0){
        int dig = num%10;
        if(dig == 1){
            ans+= pow(2,i);
        }

        num /= 10;
        ++i;
    }
    return ans;
}