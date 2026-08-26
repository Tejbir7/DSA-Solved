#include<bits/stdc++.h>
using namespace std;

class Solution {
     bool midCheck(char &s){
        
         int num = (int)s;
                
        for(int i=7; i>=0; --i){
            int x = (num >> (7-i) & 1);
            int y = (num >>i & 1);
            if(x != y) return false;
        }
        return true;
    }
    
    bool binCheck(char &s, char& t){
        
         int num1 = (int)s;
         int num2 = (int)t;
        
        for(int i=7; i>=0; --i){
            int x = (num1 >> (7-i) & 1);
            int y = (num2 >>i & 1);
            if(x != y) return false;
        }
        return true;
    }
public:
    bool isPalindromic( string &s) {
        int n = s.size();
              
        int i=0, j = n-1;
        while(i<j){
            if(!binCheck(s[i], s[j])) return false;
            ++i;
            --j;
        }
        
        if(i==j) return midCheck(s[i]);
        return true;
      
    }
};