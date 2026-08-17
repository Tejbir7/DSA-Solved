#include<bits/stdc++.h>
using namespace std;
void insertionsort(vector<int> &arr,int i,int n){
    if(i>=n) return;
    int key = arr[i];
    int temp = i-1;
    while(temp>=0 && arr[temp]>key){
        arr[temp+1] = arr[temp];
        temp--;
    }
    arr[temp+1]=key;
    insertionsort(arr,i+1,n);
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
    insertionsort(arr,1,size);
    cout << "The sorted arr is: ";
    for(int t=0;t<n;t++){
        cout<< arr[t] << " ";
    }
    return 0;

}