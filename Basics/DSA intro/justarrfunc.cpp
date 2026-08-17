#include<iostream>
using namespace std;
void dosomething(int arr[],int n){
    arr[0]+=100;
    cout << "Value inside the func: " << arr[0] << endl;
}
int main(){
    int n = 5;
    int arr[n];
    cout << "Enter 5 inputs: ";
    for(int i = 0; i <n; i++){
        cin >> arr[i];
    dosomething(arr,n);
    cout << "Value inside main function: " << arr[0] << endl;
    return 0;
    }
}