#include<iostream>
#include<string>
using namespace std;
 string largestOddNumber(string num) {
    int n= num.size();
    int right = n-1;
    while(right>=0){
        int i = (int)num[right];
        if(i%2==1){
            num.erase(right+1);
            return num;
        }
        --right;
    }
    return "";        
    }