#include<bits/stdc++.h>
using namespace std;
 void reverseArray(int arr[], int n, int i=0){
    if(i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    reverseArray(arr,n,i+1);
 }
   
int main(){
   int n;
   cout<< "Enter n: ";
   cin >> n;
   int arr[n];
   cout << "Enter array elements: ";
   for(int i=0;i<n;i++){
      cin >> arr[i];
   }
   reverseArray(arr,n);
   cout << "The reversed array elements are: ";
   for(int i=0;i<n;i++){
      cout << arr[i] << " ";
         }
return 0;

}