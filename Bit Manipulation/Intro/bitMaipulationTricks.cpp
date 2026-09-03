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

//Toggle the ith bit
int toggleIbit(int num, int i){
    num = num ^ (1 << i);
    return num;
}

//Remove Last set bit
int removeLastSetBit(int num){
    return num & (num-1);
}

//check if even?
bool ifEven(int num){
    if(num & 1 == 0) return true;
    return false;
}

//check if power of 2
bool checkIfPowerOf2(int num){
    if(num > 0 && ((num & (num -1)) == 0)) return true;
    return false;
}

//count no of set bits
//For positive only
int countSetBits(int num){
      int cnt = 0;
    for(int i=0; i<31 ; ++i){     
        if(num & (1 << i)) ++ cnt;
    }
         return cnt;
}
int countSetBits(int num){   //Brian kernighans algo
    int cnt = 0;
    while(num != 0){
        num &= (num -1);
        ++cnt;
    }
    return cnt;
}
// int main(){
//     int a, b;
//     cin >> a>> b;
//     cout << '\n';
  
//     SWAP(a,b);
//     cout << a <<  ' ' << b;
//     return 0;
// }