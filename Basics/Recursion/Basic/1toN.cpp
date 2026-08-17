#include<iostream>
using namespace std;
void naturalNO(int n,int i=1){
    if (i >n )return;
    cout << i << endl;
    naturalNO(n,i+1);
}
//alternative approach
void func(int i, int n){
      if(i<1) return;
      func(i-1,n);
   cout<<i<<endl;
}
int main(){
    int n;
    cin>>n;
    func(n,n);
    return 0;
}