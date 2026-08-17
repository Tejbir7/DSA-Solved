#include<iostream>
#include<vector>
#include<string>
using namespace std;
  void reverseString(vector<char>& s) {
    int n = s.size();
    int low = 0, high = n-1;
    while(low<high){
        swap(s[low],s[high]);
        ++low;
        --high;
    }        
    }

     int main(){
       vector<char> s = {'h','e','l','l','o'};
        reverseString(s);
        for(char i:s){
            cout << i ;
        }
        return 0;
    }