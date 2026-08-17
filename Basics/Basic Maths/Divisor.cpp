#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//You are given an integer n. You need to find all the divisors of n. Return all the divisors of n as an array or list in a sorted order.
 vector<int> finddivisors(int n){
    vector<int> divisors;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            divisors.push_back(i);
            if(i!=n/i){
            divisors.push_back(n/i);  
        }
        }
       
    }
   sort(divisors.begin(),divisors.end());
    return divisors;
 }

 int main(){
    int num;
    cout << "Enter num: ";
    cin >> num;
    auto Ans= finddivisors(num);
    for (auto i : Ans) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
 }

