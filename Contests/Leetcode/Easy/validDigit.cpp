#include<bits/stdc++.h>
using namespace std;
bool validDigit(int n, int x) {
        if(n==0) return false;
       vector<int> number;
        while(n!=0){
            int lastDigit = n%10;
            number.push_back(lastDigit);
            n= n/10;            
        }
        int N = number.size();
        if(number[N-1]==x) return false;
        for(int i=0 ; i<N; ++i){
            if(number[i]==x) return true;
        }       
        return false;
    }

    //better but same complexity
    bool validDigit(int n, int x) {
        string s = to_string(n);
        char target = x + '0';
        
        if (s[0] == target) return false;
        
        for (char c : s) {
            if (c == target) return true;
        }
        
        return false;
    }