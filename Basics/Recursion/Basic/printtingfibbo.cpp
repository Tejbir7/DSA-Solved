#include<iostream>
using namespace std;
void pfiboo(int n, int a=0,int b=1,int count =0){
   if(count>=n) return;
   cout << a << " ";
  pfiboo(n,b,a+b,count+1);
}
//alternative iterative approach

void func(int n){
    int z=0,f=1;
    for(int i=0;i<=n;i++){
        cout << z << " ";
        int temp = z + f;
        z = f;
        f = temp;
    }
} 

int main(){
    int n;
    cout << "Enter number of terms: ";
    cin>>n;
    func(n);
    return 0;
}