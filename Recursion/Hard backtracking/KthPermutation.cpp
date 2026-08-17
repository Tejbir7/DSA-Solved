#include<iostream>
#include<vector>
#include<string>
using namespace std;
  string getPermutation(int n, int k) {
    int fact = 1;
    string ans;
    vector<int> numbers;
    for(int i=1;i<n;++i){
        numbers.push_back(i);
        fact = fact*i;   // calculates n-1!
    }
    numbers.push_back(n);
    k = k-1; //for zero based indexing
    while(true){
       // ans.push_back(to_string(numbers[k/fact])); 
       ans+= to_string(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact); // delete that number
        if(numbers.empty()) break; 
        k = k%fact; //new k as numbers decrease
        fact = fact/numbers.size();     // new fact  
    }
    return ans;        
    }
    //no push_back() as it demands a char
    // always prefer using long long for factorials, safe practise, here <=9 so safe