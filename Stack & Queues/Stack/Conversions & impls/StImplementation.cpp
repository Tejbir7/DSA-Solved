#include<iostream>
using namespace std;
class StImpl{
   private:
   int top1 = -1;
   int st[10];

   public:
   void push(int x){
    if(top1>=9) {
        cout << "Stack Overflow\n"; 
        return;
    }
    top1 = top1+1;
    st[top1] = x;
   }

   int top(){
    if(top1== -1)  {
        cout << "Stack Underflow\n";
        return -1;
    }
    return st[top1];;
   }
 
   int size(){
    return top1+1;
   }

   void pop(){
    if(top1 == -1)   
    {
      cout << "Stack Underflow\n"; 
     return;
    }
    top1 = top1-1;
   }
    bool empty() {
        return top1 == -1;
    }
};