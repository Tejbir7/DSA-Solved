#include<iostream>
using namespace std;
int NnumbersSum(int N){
    if (N<1) return 0;
    return N + NnumbersSum(N-1);
   
}
int main(){
    int n;
    cin>>n;
    int recAns= NnumbersSum(n);
    cout << recAns << endl;
    return 0;
}