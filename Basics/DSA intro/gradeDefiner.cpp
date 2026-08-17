#include<iostream>
using namespace std;
int main (){
    int a;
    cout << "Enter your marks: ";
    cin >> a;
    //if(a>=90){ cout<< "You scored S"; }
    //if(a>=80 && a<90 ){ cout<< "You scored A"; }
   // if(a>=70 && a<80 ){ cout<< "You scored B"; }
   // if(a>=60 && a<70 ){ cout<< "You scored C"; }
   // if(a>=50 && a<60 ){ cout<< "You scored D"; }
   // if(a>=40 && a<50 ){ cout<< "You scored E"; }
   // if(a<40 ){ cout<< "You scored U"; }
   if (a >= 90) { cout << "You scored S"; }
else if (a >= 80) { cout << "You scored A"; }
else if (a >= 70) { cout << "You scored B"; }
else if (a >= 60) { cout << "You scored C"; }
else if (a >= 50) { cout << "You scored D"; }
else if (a >= 40) { cout << "You scored E"; }
else { cout << "You scored U"; }
   return 0;
}
