#include<bits/stdc++.h>
using namespace std;
//innerloop for pass
void bubblePass(vector<int> &arr,int i, int n){
    if(i>=n) return;
    if(arr[i]>arr[i+1]){
        swap(arr[i],arr[i+1]);
    }
    bubblePass(arr,i+1,n);
}
void bubbleSort(vector<int> &arr, int n) {
    if (n == 1) return; // Base case: only one element left
    bubblePass(arr, 0, n); // Perform one full pass
    bubbleSort(arr, n - 1); // Reduce the size for next pass
}
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter values: ";
    for(int x=0;x<n;x++){
        cin >> arr[x];
    }
    int size = arr.size();
    bubbleSort(arr,size);
    cout << "The sorted arr is: ";
    for(int t=0;t<n;t++){
        cout<< arr[t] << " ";
    }
    return 0;

}