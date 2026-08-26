#include<bits/stdc++.h>
using namespace std;
//swap 2 numbers
void SWAP(int &a, int &b){
    a = a^b;
    b = a^b;
    a= a^b;
}

//Check if ith bit is set or not
bool checkByLeftShift(int num, int i){
    if(((1<<i) & num)!= 0) return true;
    return false;
}
bool checkByRightShift(int num, int i){
    if(((num>> i)&1) == 1) return true;
    return false;
}

//set ith bit
int setIbit(int num, int i){
    return (1<<i) | num;

}

//clear ith bit
int clearIbit(int num, int i){
    return (~(1<<i) & num);
}


// int main(){
//     int a, b;
//     cin >> a>> b;
//     cout << '\n';
  
//     SWAP(a,b);
//     cout << a <<  ' ' << b;
//     return 0;
// }